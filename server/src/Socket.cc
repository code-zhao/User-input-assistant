 
 /// @file    Socket.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 16:07:47
 ///

#include "Socket.h"
#include "SocketUtil.h"
#include "InetAddress.h"

namespace zh
{
Socket::Socket(int sockfd)
:_sockfd(sockfd)
{}

Socket::Socket()
:_sockfd(createSocketFd())
{}

Socket::~Socket()
{
	::close(_sockfd);
}

void Socket::nonblock()
{
	setNonblock(_sockfd);
}

void Socket::shutdownWrite()
{
	if(::shutdown(_sockfd, SHUT_WR) == -1)
	{
		perror("shutdown write error!");
	}
}

InetAddress Socket::getLocalAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getsockname(sockfd, (struct sockaddr *)&addr, &len) == -1)
	{
		perror("getsockname error");
	}
	return InetAddress(addr);
}

InetAddress Socket::getPeerAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getpeername(sockfd, (struct sockaddr*)&addr, &len) == -1)
	{
		perror("getpeername error");
	}
	return InetAddress(addr);
}
}//end of namespace zh
