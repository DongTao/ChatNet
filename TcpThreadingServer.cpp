/*
 * =====================================================================================
 *
 *       Filename:  TcpThreadingServer.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 20:56:15
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include "TcpThreadingServer.h"

TcpThreadingServer::TcpThreadingServer(const char *host, int port, BaseRequestHandler &handler)
    : BaseSocketServer(host, port, handler)
{
    BaseSocketServer::create();
    BaseSocketServer::bind();
}

bool TcpThreadingServer::prepare()
{
    if (listen(mListenSocket, MAX_CONN) == -1) {
        perror("listen failed");
        return false;
    }

    return true;
}

int TcpThreadingServer::get_request()
{
    int conn_sock;
    socklen_t len = sizeof(mAddr);

    conn_sock = accept(mListenSocket, (struct sockaddr *)&mAddr, &len);
    if (conn_sock < 0) {
        perror("accept error");
        return -1;
    }

    std::cout << "Connected: " << conn_sock << std::endl;

    return conn_sock;
}

struct ThreadFuncParams {
    int sock;
    TcpThreadingServer *ts;
};

bool TcpThreadingServer::serve_forever()
{
    int ret;
    int conn_sock;
    pthread_t tid;
    struct ThreadFuncParams p;

    if (!prepare()) {
        return false;
    }

    while (!mShutdown) {
        conn_sock = get_request();
        if (conn_sock != -1) {
            p.sock = conn_sock;
            p.ts = this;
            ret = pthread_create(&tid, NULL, process_request, (void *)&p);
            if (ret != 0) {
                ::close(conn_sock);
            }
        }
    }

    return true;
}

void *TcpThreadingServer::process_request(void *arg)
{
    ThreadFuncParams *p = (ThreadFuncParams *)arg;
    int conn_sock = p->sock;

    std::cout << "start thread " << pthread_self() << std::endl;
    pthread_detach(pthread_self());
    p->ts->mHandler.process_request(conn_sock);
}
