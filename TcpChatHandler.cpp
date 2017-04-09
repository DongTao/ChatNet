/*
 * =====================================================================================
 *
 *       Filename:  TcpChatHandler.cpp
 *
 *    Description:  Handler for Simple Chat
 *
 *        Version:  1.0
 *        Created:  04/09/17 13:50:02
 *       Revision:  0.1 - Creation
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
// OS related headers
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

// C standard lib
#include <stdio.h>
#include <stdlib.h>

// C++ standard lib
#include <iostream>
#include <set>

// Self defined
#include "TcpChatHandler.h"
#include "Message.h"

TcpChatHandler::TcpChatHandler()
{

}

TcpChatHandler::~TcpChatHandler()
{

}

bool TcpChatHandler::preHandle(int sock)
{
    AutoMutex _l(mLock);
    clients.insert(sock);
    return true;
}

bool TcpChatHandler::handle(int sock)
{
    ssize_t ret;
    std::set<int>::iterator it;

    while (1) {
        if ((ret = recv(sock, this->mRecvBuf, MAX_BUF_SIZE, 0)) <= 0) {
            perror("recv failed");
            return false;
        }
        this->mRecvBuf[ret] = 0;
        std::cout << "[" << pthread_self() << "]: " << this->mRecvBuf << std::endl;

        mLock.lock();
        for (it = this->clients.begin(); it != this->clients.end(); ++it) {
            if (sock != *it) {
                if ((ret = send(*it, this->mRecvBuf, ret, 0)) == -1) {
                    perror("send failed");
                    mLock.unlock();
                    return false;
                }
            }
        }
        mLock.unlock();
    }

    return true;
}

void TcpChatHandler::postHandle(int sock) throw()
{
    close(sock);
}
