#pragma once
#include <sys/socket.h>
#include "inet_addr.h"

class CSocket
{
public:
	CSocket();
	~CSocket();

	int Connect(CInet* inet);
	int Write(char* buf);
	int Read(char* buf);

private:
	int fd;
};
