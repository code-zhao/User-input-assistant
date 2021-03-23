 ///
 /// @file    MainServer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-31 13:51:17
 ///

#ifndef __MAINSERVER_H__
#define __MAINSERVER_H__

#include "CacheManager.h"
#include "TcpServer.h"
#include "Threadpool.h"
#include "MyDict.h"
#include "QueryTask.h"
#include "Config.h"
#include "TimerThread.h"
#include "Mylog.h"
#include <iostream>
#include <memory>

void onConnection(const zh::TcpConnectionPtr&);
void onMessage(const zh::TcpConnectionPtr&);
void onClose(const zh::TcpConnectionPtr&);

class MainServer
{
	friend void onConnection(const zh::TcpConnectionPtr&);
	friend void onMessage(const zh::TcpConnectionPtr&);
	friend void onClose(const zh::TcpConnectionPtr&);
public:
	MainServer(const string& ConfigPath)
	:_configMap(Config::getInstance(ConfigPath)->getConfigMap())
	,_threadpool(stoi(_configMap["ThreadpoolCap"]), stoi(_configMap["TaskQueSize"]))
	,_tcpserver(_configMap["ServerIP"], (stoi(_configMap["Port"])))
	,_cacheMgr(_configMap["cachePath"])
	,_timer(5, 5, bind(&CacheManager::periodUpdate, &_cacheMgr))
	{}

	void start();
	void stop();
private:
	map<string,string> &_configMap;
	zh::Threadpool _threadpool;
	zh::TcpServer _tcpserver;
	MyDict* _dict;
	CacheManager _cacheMgr;
	zh::TimerThread _timer;
};
#endif
