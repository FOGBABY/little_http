#include "http.h"
#include "utility.h"

CHttp::CHttp(const char* ip, uint16_t port)
{
	CInet inet(ip, port);
	m_sock = new CSocket();
	m_sock->Connect(&inet);
}

CHttp::~CHttp()
{
	if (m_sock)
	{
		delete m_sock;
		m_sock = NULL;
	}
}

int CHttp::HttpWrite(METHOD method, std::string request)
{
	char buf[BUFFER_SIZE];
	bzero(&buf, sizeof(buf));
	memcpy(&buf, request.c_str(), request.length());
	m_sock->Write(buf);
}

int CHttp::HttpRead()
{
	char buf[BUFFER_SIZE];
	bzero(&buf, sizeof(buf));
	m_sock->Read(buf);
}

int CHttp::HttpGet(std::string url)
{
	std::string strSend = " HTTP/1.1\r\n""Connection:keep-alive\r\n\r\n";
	std::string request = "GET " + url + strSend;


	printf("message send:%s\n", request.c_str());

	HttpWrite(GET, request);
	HttpRead();

	return 1;
}

int CHttp::HttpSend(METHOD method, std::string url)
{
	switch (method)
	{
		case GET:
			printf("Http Get\n");
			HttpGet(url);
			break;
		case POST:
			break;
	}
	return 1;
}