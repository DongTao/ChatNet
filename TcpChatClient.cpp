/*
 * =====================================================================================
 *
 *       Filename:  TcpChatClient.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/09/17 21:25:33
 *       Revision:  0.1 - Creation
 *       Compiler:  gcc
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "TcpChatClient.h"

TcpChatClient::TcpChatClient(const char *remote, int port)
    : BaseSocketClient(remote, port)
{
    // TODO: need an exeption to indicate constructor error
    if (BaseSocketClient::create()) {
        mConnSock = BaseSocketClient::mConnSock;
    }
}

bool TcpChatClient::prepare()
{
    int ret;

    ret = connect(mConnSock, (struct sockaddr *)&mAddr, sizeof(mAddr));
    if (ret == -1) {
        perror("connect to server failed");
        return false;
    }

    return true;
}

bool TcpChatClient::onSend(std::string &s)
{
    std::cin >> s;

    return true;
}

bool TcpChatClient::onReceive(std::string &s)
{
    std::cout << "Receive Message: " << s << std::endl;
    return true;
}

bool TcpChatClient::start()
{
    pthread_t stid, rtid;

    if (!prepare()) {
        puts("prepare failed");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&stid, NULL, send_handler, (void *)this) != 0) {
        puts("can not create send thread");
        return false;
    }

    if (pthread_create(&rtid, NULL, recv_handler, (void *)this) != 0) {
        puts("can not create recv thread");
        return false;
    }

    pthread_join(stid, NULL);
    pthread_join(rtid, NULL);
    return true;
}

void *TcpChatClient::send_handler(void *arg)
{
    std::string msg;
    TcpChatClient *c = (TcpChatClient *)arg;

    while (1) {
        //c->mUiLock.lock();
        c->onSend(msg);
        //c->mUiLock.unlock();
        // TODO: error handler
        send(c->mConnSock, msg.c_str(), msg.size(), 0);
    }
}

void *TcpChatClient::recv_handler(void *arg)
{
    ssize_t ret;
    std::string msg;
    char buf[MAX_BUF_SIZE + 1];
    TcpChatClient *c = (TcpChatClient *)arg;

    while (1) {
        ret = recv(c->mConnSock, buf, MAX_BUF_SIZE, 0);
        if (ret > 0) {
            msg = "";
            msg = buf;
            //c->mUiLock.lock();
            c->onReceive(msg);
            //c->mUiLock.unlock();
        } else if (ret == 0) {// EOF
            std::cout << "Disconnected from server" << std::endl;
            exit(EXIT_SUCCESS);
        } else {// Error
            perror("recv error");
            exit(EXIT_FAILURE);
        }
    }
}
