/*
 * =====================================================================================
 *
 *       Filename:  PrivmsgCommand.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/04/17 15:45:23
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include "PrivmsgCommand.h"

bool PrivmsgCommand::verifyParams()
{
    return true;
}

bool PrivmsgCommand::execute(std::string &rsp)
{
    rsp = "";
    return true;
}

