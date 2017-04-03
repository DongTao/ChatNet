/*
 * =====================================================================================
 *
 *       Filename:  TcpEchoHandler.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 16:44:40
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __TCPECHOHANDLER_H
#define  __TCPECHOHANDLER_H

#include "BaseRequestHandler.h"

#define MAX_BUF_SIZE 512 // 512 bytes in a single tranfer

class TcpEchoHandler : public BaseRequestHandler {

public:
    TcpEchoHandler() {};
    ~TcpEchoHandler() {};

    bool preHandle(int sock);
    bool handle(int sock);
    void postHandle();

private:
    char recv_buf[MAX_BUF_SIZE + 1];
};

#endif   /* __TCPECHOHANDLER_H */
