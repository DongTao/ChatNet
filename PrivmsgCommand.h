/*
 * =====================================================================================
 *
 *       Filename:  PrivmsgCommand.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/04/17 15:24:07
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __PRIVMSGCOMMAND_H
#define  __PRIVMSGCOMMAND_H

#include "Message.h"

class PrivmsgCommand : public MsgCommand {

public:
    PrivmsgCommand();
    ~PrivmsgCommand() {};

    bool verifyParams();
    bool execute(std::string &rsp);
};

#endif   /* __PRIVMSGCOMMAND_H */
