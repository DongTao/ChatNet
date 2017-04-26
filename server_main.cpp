/*
 * =====================================================================================
 *
 *       Filename:  server_main.cpp
 *
 *    Description:  Main function of server
 *
 *        Version:  1.0
 *        Created:  04/02/17 13:33:37
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include "TcpChatHandler.h"
#include "TcpThreadingServer.h"

int main(int argc, char *argv[])
{
    TcpChatHandler handler;
    TcpThreadingServer chatServer(NULL, 10080, handler);

    chatServer.serve_forever();

    return 0;
}
