SERVER_SRCS=server_main.cpp BaseSocketServer.cpp TcpThreadingServer.cpp BaseRequestHandler.cpp TcpEchoHandler.cpp
CLIENT_SRCS=client_main.cpp BaseSocketClient.cpp TcpClient.cpp

server: $(SERVER_SRCS)
	g++ -o server $(SERVER_SRCS) -lpthread

client: $(CLIENT_SRCS)
	g++ -o client $(CLIENT_SRCS)

all: server client

clean:
	-rm -rf *.o server client
