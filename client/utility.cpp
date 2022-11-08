#include "stdio.h"
#include "stdlib.h"

void errif(bool condition, const char* errmsg)
{
	if (condition)
	{
		printf("%s\n", errmsg);
		exit(-1);
	}
}