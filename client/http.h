#pragma once
#include "my_socket.h"
#include <string>

enum METHOD
{
	GET,
	POST
};

class CHttp
{
public:
	CHttp(const char* ip, uint16_t port);
	~CHttp();
public:
	int HttpSend(METHOD,std::string url);
private:
	int HttpGet(std::string url);
	int HttpPost(std::string url);
	int HttpRead();
	int HttpWrite(METHOD method,std::string body);
private:
	CSocket* m_sock;
};
