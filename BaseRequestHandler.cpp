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
    if (!preHandle(sock)) {
        postHandle();
        return;
    }

    std::cout << "handle request" << std::endl;
    if (!handle(sock)) {
        postHandle();
        return;
    }

    postHandle();
}
