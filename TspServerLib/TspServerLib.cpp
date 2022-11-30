#include "TcpServerController.h"
#include <iostream>

int main()
{
	TcpServerController* server1 = new TcpServerController("127.0.0.1", 40000, "Default TCP Server");
	server1->Start();
	scanf_s("\n");
	return 0;
}