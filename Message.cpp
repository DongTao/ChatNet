/*
 * =====================================================================================
 *
 *       Filename:  Message.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/04/17 13:03:18
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#include <sstream>

#include "Message.h"
#include "UserCommand.h"
#include "PassCommand.h"
#include "PrivmsgCommand.h"

Message::Message(std::string &msg, MsgCommandParser &p)
    : mMessage(msg), mParser(p)
{
    mCmd = mParser.parse(mMessage);
}

Message::~Message()
{
    if (NULL != mCmd) {
        delete mCmd;
    }
}

std::string Message::response()
{
    std::string rsp("");

    if (mCmd->verifyParams()) {
        mCmd->execute(rsp);
    }

    return rsp;
}

int MsgCommand::addParam(std::string &p)
{
    mParamList.push_back(p);
    return mParamList.size();
}

MsgCommand *MsgCommandParser::parse(std::string &msg)
{
    // Get cmd phase
    std::string cmd_text = msg.substr(0, msg.find(' '));
    std::string param_text = msg.substr(cmd_text.length(), msg.length() - cmd_text.length() - 1);

    // Create concrete cmd subclass
    MsgCommand *cmd;
    if ("USER" == cmd_text) {
        cmd = new UserCommand;
    } else if ("PASS" == cmd_text) {
        cmd = new PassCommand;
    } else if ("PRIVMSG" == cmd_text) {
        cmd = new PrivmsgCommand;
    } else {
        cmd = NULL;
    }

    // Parse the parameter list
    std::string tmp;
    std::stringstream ss(param_text);
    while (ss >> tmp) {
        cmd->addParam(tmp);
    }

    return cmd;
}
