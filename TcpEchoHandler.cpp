/*
 * =====================================================================================
 *
 *       Filename:  TcpEchoHandler.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 16:49:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include "TcpEchoHandler.h"

bool TcpEchoHandler::preHandle(int sock)
{
    return true;
}

bool TcpEchoHandler::handle(int sock)
{
    ssize_t ret;

    while (1) {
        if ((ret = recv(sock, this->recv_buf, MAX_BUF_SIZE, 0)) == -1) {
            perror("recv failed");
            return false;
        }

        std::cout << "[" << pthread_self() << "]: " << this->recv_buf << std::endl;

        if ((ret = send(sock, this->recv_buf, ret, 0)) == -1) {
            perror("send failed");
            return false;
        }
    }

    return true;
}

void TcpEchoHandler::postHandle()
{

}
