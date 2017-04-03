/*
 * =====================================================================================
 *
 *       Filename:  BaseRequestHandler.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/02/17 16:12:59
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __BASEREQUESTHANDLER_H
#define  __BASEREQUESTHANDLER_H

class BaseRequestHandler {

public:
    BaseRequestHandler() {};
    virtual ~BaseRequestHandler() {};

    virtual void process_request(int sock);

    virtual bool preHandle(int sock) = 0;
    virtual bool handle(int sock) = 0;
    virtual void postHandle() = 0;
};

#endif   /* __BASEREQUESTHANDLER_H */
