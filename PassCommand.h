/*
 * =====================================================================================
 *
 *       Filename:  PassCommand.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/04/17 15:20:53
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __PASSCOMMAND_H
#define  __PASSCOMMAND_H

#include "Message.h"

class PassCommand : public MsgCommand {

public:
    PassCommand();
    ~PassCommand() {};

    bool verifyParams();
    bool execute(std::string &rsp);
};

#endif   /* __PASSCOMMAND_H */
