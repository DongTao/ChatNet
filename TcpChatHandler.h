/*
 * =====================================================================================
 *
 *       Filename:  TcpChatHandler.h
 *
 *    Description:  Handler for Simple Chat
 *
 *        Version:  1.0
 *        Created:  04/09/17 13:40:23
 *       Revision:  0.1 - Creation
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */

#ifndef  __TCPCHATHANDLER_H
#define  __TCPCHATHANDLER_H

#include <set>

#include "BaseRequestHandler.h"
#include "utils/Mutex.h"

#define MAX_BUF_SIZE 512 // 512 bytes in a single tranfer

class TcpChatHandler : public BaseRequestHandler {

public:
    TcpChatHandler();
    ~TcpChatHandler();

    bool preHandle(int sock);
    bool handle(int sock);
    void postHandle(int sock) throw();

private:
    char mRecvBuf[MAX_BUF_SIZE + 1];
    std::set<int> clients;
    Mutex mLock;
};

#endif   /* __TCPCHATHANDLER_H */
