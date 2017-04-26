/*
 * =====================================================================================
 *
 *       Filename:  Message.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/04/17 09:24:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Feng Jie<fengjie.87@gmail.com>
 *
 * =====================================================================================
 */
#ifndef  __MESSAGE_H
#define  __MESSAGE_H

#include <string>
#include <vector>

/*
 * Command Defination
 *
 * USER <username>
 * PASS <password>
 *
 * PRIVMSG <receiver>[,<receiver>] <text>
 *
 */

enum MsgCode {
    USER,
    PASS,
    PRIVMSG,
    NUM_OF_CMD
};

class MsgCommand {
public:
    MsgCommand();
    virtual ~MsgCommand();

    int addParam(std::string &p);

    virtual bool verifyParams() = 0;
    virtual bool execute(std::string &rsp) = 0;

private:
    std::vector<std::string> mParamList;
};

class MsgCommandParser {
public:
    MsgCommandParser();
    ~MsgCommandParser() {};

    // A factory method
    virtual MsgCommand *parse(std::string &msg);
};

class Message {

public:
    Message(std::string &msg, MsgCommandParser &p);
    ~Message();

    // API for the caller
    std::string response();

private:
    std::string &mMessage;
    MsgCommandParser &mParser;
    MsgCommand *mCmd;
};

#endif   /* __MESSAGE_H */
