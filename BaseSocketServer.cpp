/*
 * =====================================================================================
 *
 *       Filename:  BaseServer.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 19:19:51
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

#include "BaseSocketServer.h"

BaseSocketServer::BaseSocketServer(const char *host, int port, BaseRequestHandler &handler)
    : mListenSocket(-1), mShutdown(false), mHandler(handler)
{
    memset(&mAddr, 0, sizeof(mAddr));
    mAddr.sin_family = AF_INET;
    if (NULL == host) {
        mAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    } else {
        mAddr.sin_addr.s_addr = inet_addr(host);
    }
    mAddr.sin_port = htons(port);
}

BaseSocketServer::~BaseSocketServer()
{
    if (mListenSocket > 0) {
        close(mListenSocket);
        mListenSocket = -1;
    }
}

bool BaseSocketServer::create()
{
    mListenSocket = socket(AF_INET, SOCK_STREAM, 0);
    return (mListenSocket != -1) ? true : false;
}

bool BaseSocketServer::bind()
{
    int ret;

    ret = ::bind(mListenSocket, (struct sockaddr *)&mAddr, sizeof(mAddr));
    if (ret == -1) {
        perror("bind failed");
        return false;
    }

    return true;
}

bool BaseSocketServer::serve_forever()
{
    int conn_sock;

    if (!prepare()) {
        return false;
    }

    conn_sock = get_request();

    while (!mShutdown) {
        if (conn_sock != -1) {
            //std::cout << "ready to process_request" << std::endl;
            mHandler.process_request(conn_sock);
        }
    }

    return true;
}

bool BaseSocketServer::shutdown()
{
    mShutdown = true;

    return mShutdown;
}
