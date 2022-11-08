#include <iostream>
#include <stdio.h>
#include "my_socket.h"

#define BUFFER_SIZE 1024 

int main(int argc , char* argv[]) 
{
	CInet* inet = new CInet("127.0.0.1", 8888);
	CSocket* sock = new CSocket();
	sock->Connect(inet);

	while (true)
	{
		char buf[BUFFER_SIZE];
		bzero(&buf, sizeof(buf));
		scanf("%s", buf);
		sock->Write(buf);
		bzero(&buf, sizeof(buf));
		sock->Read(buf);
	}

	delete inet;
	delete sock;
	return 0;
}