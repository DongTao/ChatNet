/*
 * =====================================================================================
 *
 *       Filename:  TcpThreadingServer.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 20:50:54
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */

#ifndef  __TCPTHREADINGSERVER_H
#define  __TCPTHREADINGSERVER_H

#include "BaseSocketServer.h"

#define MAX_CONN 5

class TcpThreadingServer : public BaseSocketServer {

public:
    TcpThreadingServer(const char *host, int port, BaseRequestHandler &handler);
    ~TcpThreadingServer() {};

    bool serve_forever();
    bool prepare();
    int get_request();

private:
    static void *process_request(void *arg);
};

#endif   /* __TCPTHREADINGSERVER_H */
