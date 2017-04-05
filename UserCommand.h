/*
 * =====================================================================================
 *
 *       Filename:  UserCommand.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/04/17 15:13:08
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __USERCOMMAND_H
#define  __USERCOMMAND_H

#include "Message.h"

class UserCommand : public MsgCommand {

public:
    UserCommand();
    ~UserCommand() {};

    bool verifyParams();
    bool execute(std::string &rsp);
};

#endif   /* __USERCOMMAND_H */
