 ///
 /// @file    TcpServer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-06 16:01:12
 ///
 
#ifndef __ZH_TCPSERVER_H__
#define __ZH_TCPSERVER_H__
#include "Acceptor.h"
#include "EpollPoller.h"
#include "Mylog.h"
#include <string>

using std::string;

namespace zh
{
class TcpServer
{
public:
	typedef EpollPoller::EpollCallback TcpServerCallback;
	TcpServer(const string &ip, unsigned short port);
	TcpServer(unsigned short port);

	void start();
	void stop();

	void setConnectionCallback(TcpServerCallback cb);
	void setMessageCallback(TcpServerCallback cb);
	void setCloseCallback(TcpServerCallback cb);

private:
	Acceptor _acceptor;
	EpollPoller _poller;

	TcpServerCallback _connectionCallback;
	TcpServerCallback _messageCallback;
	TcpServerCallback _closeCallback;

};
}//end of namespace zh

#endif
