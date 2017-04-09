/*
 * =====================================================================================
 *
 *       Filename:  TcpChatClient.h
 *
 *    Description:  Chat client based on TCP
 *
 *        Version:  1.0
 *        Created:  04/09/17 20:24:36
 *       Revision:  0.1 - Creation
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */

#ifndef  __TCPCHATCLIENT_H
#define  __TCPCHATCLIENT_H

#include "BaseSocketClient.h"
#include "utils/Mutex.h"

#define MAX_BUF_SIZE 512

class TcpChatClient : public BaseSocketClient {

public:
    TcpChatClient(const char *remote, int port);
    ~TcpChatClient() {}

    virtual bool start();

protected:
    bool prepare();
    bool onSend(std::string &s);
    bool onReceive(std::string &s);

private:
    static void *send_handler(void *arg);
    static void *recv_handler(void *arg);
    Mutex mUiLock;
    int mConnSock;
};

#endif   /* __TCPCHATCLIENT_H */
