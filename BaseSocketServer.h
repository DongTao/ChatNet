/*
 * =====================================================================================
 *
 *       Filename:  BaseServer.h
 *
 *    Description:  Base Server Interfaces
 *
 *        Version:  1.0
 *        Created:  04/02/17 14:45:43
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __BASESERVER_H
#define  __BASESERVER_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>

#include "BaseRequestHandler.h"

class BaseSocketServer {

public:
    BaseSocketServer(const char *host, int port, BaseRequestHandler &handler);
    virtual ~BaseSocketServer();

    // Top level APIs for callers
    bool create();
    bool bind();
    virtual bool serve_forever();
    virtual bool shutdown();

    // May be overridden
    virtual bool prepare() = 0;
    virtual int get_request() = 0;

protected:
    int mListenSocket;
    bool mShutdown;
    sockaddr_in mAddr;
    BaseRequestHandler &mHandler;
};

#endif   /* __BASESERVER_H */
