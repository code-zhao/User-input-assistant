 ///
 /// @file    InetAddress.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-18 15:42:44
 ///

#ifndef __ZH_INETADDRESS_H__
#define __ZH_INETADDRESS_H__

#include <netinet/in.h>
#include <string>
namespace zh
{
class InetAddress
{
public:
	InetAddress(short port);
	InetAddress(const char* ip, short port);
	InetAddress(const struct sockaddr_in &addr);

	const struct sockaddr_in *getSockAddrPtr() const;
	std::string ip() const;
	unsigned short port() const;

private:
	struct sockaddr_in _addr;
};

}//and of namespace zh


#endif
