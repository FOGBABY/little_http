#pragma once
#include <arpa/inet.h>
#include <string.h>

class CInet
{
public:
	CInet(const char* ip, uint16_t port);
	~CInet();
	struct sockaddr_in addr;
	socklen_t addr_len;
};