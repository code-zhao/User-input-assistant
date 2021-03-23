 ///
 /// @file    SocketIO.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-02-01 16:09:31
 ///

#ifndef __ZH_SOCKETIO_H__
#define __ZH_SOCKETIO_H__
#include <stdio.h>

namespace zh
{
class SocketIO
{
public:
	SocketIO(int sockfd);
	
	size_t readn(char* buf, size_t count);
	size_t writen(const char *buf, size_t count);
	size_t readline(char *buf, size_t max_len);
	int getFd()
	{
		return _sockfd;
	}

private:
	size_t recv_peek(char *buf, size_t count);

private:
	int _sockfd;
};
}//end of namespace zh

#endif
