/*
 * =====================================================================================
 *
 *       Filename:  BaseRequestHandler.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 16:17:11
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <iostream>
#include "BaseRequestHandler.h"

void BaseRequestHandler::process_request(int sock)
{
    try {
        std::cout << "prehandle request socketfd:" << sock << std::endl;
        if (!preHandle(sock)) {
            std::cout << "prehandle request failed socketfd:" << sock << std::endl;
        } else {
            std::cout << "handle request socketfd:" << sock << std::endl;
            if (!handle(sock)) {
                std::cout << "handle request failed socketfd:" << sock << std::endl;
            }
        }
        std::cout << "posthandle request socketfd:" << sock << std::endl;
        postHandle(sock);
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        postHandle(sock);
    }
}
