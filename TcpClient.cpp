/*
 * =====================================================================================
 *
 *       Filename:  TcpClient.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/03/17 13:12:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <iostream>

#include "TcpClient.h"

TcpClient::TcpClient(const char *host, int port)
    : BaseSocketClient(host, port)
{
    BaseSocketClient::create();
}

bool TcpClient::prepare()
{
    int ret;

    ret = connect(mConnSock, (struct sockaddr *)&mAddr, sizeof(mAddr));
    if (ret == -1) {
        perror("connect to server failed");
        return false;
    }

    return true;
}

bool TcpClient::onSend(std::string &s)
{
    std::cin >> s;

    return true;
}

bool TcpClient::onReceive(std::string &s)
{
    std::cout << "Receive Message: " << s << std::endl;
    return true;
}
