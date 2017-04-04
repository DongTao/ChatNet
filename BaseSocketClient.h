/*
 * =====================================================================================
 *
 *       Filename:  BaseSocketClient.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/03/17 11:54:47
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __BASESOCKETCLIENT_H
#define  __BASESOCKETCLIENT_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>

#define MAX_RECV_LEN 512

class BaseSocketClient {

public:
    BaseSocketClient(const char *remote, int port);
    virtual ~BaseSocketClient();

    // Top level APIs for callers
    virtual bool start();
    virtual bool shutdown();

protected:
    bool create();

    // May be overridden
    virtual bool prepare() = 0;
    virtual bool onSend(std::string &s) = 0;
    virtual bool onReceive(std::string &s) = 0;

protected:
    int mConnSock;
    bool mShutdown;
    sockaddr_in mAddr;
};

#endif   /* __BASESOCKETCLIENT_H */
