#include "my_socket.h"
#include "utility.h"
#include <unistd.h>
#include <fcntl.h>
#include "stdio.h"

CSocket::CSocket() :fd(-1)
{
	fd = socket(AF_INET, SOCK_STREAM, 0);
	errif(fd == -1, "init socket err\n");
}

CSocket::~CSocket()
{
	if (fd != -1)
	{
		close(fd);
	}
}

int CSocket::Connect(CInet* inet)
{
	int ret = connect(fd, (sockaddr*)&inet->addr, sizeof(inet->addr));
	errif(ret == -1, "connect error\n");
}

int CSocket::Write(char* buf)
{
	ssize_t write_bytes = write(fd, buf, BUFFER_SIZE);
	errif(write_bytes == -1, "write to server failed\n");
}

int CSocket::Read(char* buf)
{
	ssize_t read_bytes = read(fd, buf, BUFFER_SIZE);
	if (read_bytes > 0) {
		printf("message from server: %s\n", buf);
	}
	else if (read_bytes == 0) {
		printf("server socket disconnected!\n");
	}
	else if (read_bytes == -1) {
		errif(true, "socket read error");
	}
}