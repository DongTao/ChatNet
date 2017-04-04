/*
 * =====================================================================================
 *
 *       Filename:  TcpClient.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/03/17 13:01:01
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __TCPCLIENT_H
#define  __TCPCLIENT_H

#include "BaseSocketClient.h"

class TcpClient : public BaseSocketClient {

public:
    TcpClient(const char *remote, int port);
    ~TcpClient() {};

protected:
    virtual bool prepare();
    virtual bool onSend(std::string &s);
    virtual bool onReceive(std::string &s);

};

#endif   /* __TCPCLIENT_H */
