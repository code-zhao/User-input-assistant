 ///
 /// @file    Acceptor.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-02 11:03:17
 ///

#ifndef __ZH_ACCEPTOR_H__
#define __ZH_ACCEPTOR_H__

#include "Socket.h"
#include "InetAddress.h"

namespace zh
{

class Acceptor
{
public:
	Acceptor(int listenfd, const InetAddress &addr);

	void ready();
	int accept();

	int fd() const
	{
		return _listenSock.fd();
	}

private:
	void setReuseAddr(bool flag);
	void setReusePort(bool flag);
	void bind();
	void listen();
private:
	Socket _listenSock;
	InetAddress _addr;
};
}//end of namespace zh

#endif
