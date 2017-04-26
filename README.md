# ChatNet

## Feature List
* All clients connecting to chat server can send message to each other

## Dependency

## Revision
* 2017/04/05
    * A base echo server is completed
    * Design message parser class but not used
* 2017/04/09
    * Clients can send messages to each other
    * Two bugs are fixed:
        1. Server side socket is not closed when client disconnecting
        2. Server did not append '\0' on received string

## TODO
* Need to integrate application layer protocol into project
* Need unit tests(gtest)
* How to add a security protocol
