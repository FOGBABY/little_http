#include <iostream>
#include "http.h"
#include "utility.h"
#include <stdlib.h>

int main(int argc , char* argv[]) 
{
	while (true)
	{
		getchar();
		CHttp* http = new CHttp("127.0.0.1", 6519);
		http->HttpSend(GET, "/TEST");
		delete http;
		http = NULL;
	}
	return 0;
}