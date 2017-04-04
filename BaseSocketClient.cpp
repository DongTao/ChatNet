/*
 * =====================================================================================
 *
 *       Filename:  BaseSocketClient.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/03/17 12:11:13
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "BaseSocketClient.h"

BaseSocketClient::BaseSocketClient(const char *remote, int port)
    : mConnSock(-1), mShutdown(false)
{
    memset(&mAddr, 0, sizeof(mAddr));
    mAddr.sin_family = AF_INET;
    mAddr.sin_addr.s_addr = inet_addr(remote);
    mAddr.sin_port = htons(port);
}

BaseSocketClient::~BaseSocketClient()
{
    if (mConnSock > 0) {
        close(mConnSock);
        mConnSock = -1;
    }
}

bool BaseSocketClient::create()
{
    mConnSock = socket(AF_INET, SOCK_STREAM, 0);
    return (mConnSock != -1) ? true : false;
}

bool BaseSocketClient::start()
{
    ssize_t ret;
    std::string msg;
    char buf[MAX_RECV_LEN + 1];

    prepare();
    while (!mShutdown) {
        onSend(msg);
        send(mConnSock, msg.c_str(), msg.size(), 0);
        ret = recv(mConnSock, buf, MAX_RECV_LEN, 0);
        if (ret > 0) {
            msg = "";
            msg = buf;
            onReceive(msg);
        } else {
            return false;
        }
    }

    return true;
}

bool BaseSocketClient::shutdown()
{
    mShutdown = true;

    return mShutdown;
}
