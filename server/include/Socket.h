 ///
 /// @file    Socket.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 15:30:24
 ///

#ifndef __ZH_SOCKET_H__
#define __ZH_SOCKET_H__
#include "Noncopyable.h"

namespace zh
{

class InetAddress;
class Socket
:Noncopyable
{
public:
	Socket(int sockfd);
	Socket();
	~Socket();

	void shutdownWrite();
	int fd() const
	{
		return _sockfd;
	}

	void nonblock();

	static InetAddress getLocalAddr(int sockfd);
	static InetAddress getPeerAddr(int sockfd);

private:
	int _sockfd;
};

}//end of namespace zh

#endif
