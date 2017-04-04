/*
 * =====================================================================================
 *
 *       Filename:  client_main.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 14:42:59
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "TcpClient.h"

static void usage(void)
{
    std::cout << "client <remote_ip> <remote_port>" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        usage();
        exit(EXIT_FAILURE);
    }

    TcpClient echoClient(argv[1], atoi(argv[2]));

    echoClient.start();

    return 0;
}
