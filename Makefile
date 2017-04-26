SERVER_SRCS=server_main.cpp BaseSocketServer.cpp TcpThreadingServer.cpp BaseRequestHandler.cpp TcpChatHandler.cpp
CLIENT_SRCS=client_main.cpp BaseSocketClient.cpp TcpChatClient.cpp

server: $(SERVER_SRCS)
	g++ -o server $(SERVER_SRCS) -lpthread

client: $(CLIENT_SRCS)
	g++ -o client $(CLIENT_SRCS) -lpthread

all: server client

clean:
	-rm -rf *.o server client
