SERVER_SRCS=server_main.cpp BaseSocketServer.cpp TcpThreadingServer.cpp BaseRequestHandler.cpp TcpEchoHandler.cpp

server: $(SERVER_SRCS)
	g++ -o server $(SERVER_SRCS) -lpthread

all: server

clean:
	-rm -rf *.o server
