#include "TcpServerController.h"
#include "TcpClient.h"
#include "network_utils.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

static void print_client(const TcpClient* tcp_client) {

	printf("[%s , %d]\n", network_convert_ip_n_to_p((tcp_client->ip_addr), 0),
		(tcp_client->port_no));
}

static void print_server(const TcpServerController* tcp_server) {

	printf("%p [%s , %d]\n", tcp_server,
		network_convert_ip_n_to_p((tcp_server->ip_addr), 0),
		(tcp_server->port_no));
}

static void appln_client_connected(const TcpServerController *tcp_server, const TcpClient *tcp_client) {
	printf("\nTcp Server \n");
	print_server(tcp_server);
	printf("Appln : Client Connected : ");
	print_client(tcp_client);
}

static void appln_client_disconnected(const TcpServerController* tcp_server, const TcpClient* tcp_client) {

}

static void appln_client_msg_recvd(const TcpServerController*, const TcpClient *tcp_client, unsigned char* msg, uint16_t msg_size) {
	printf("%s() Bytes recvd : %d msg : %s\n", __FUNCTION__, msg_size, msg);
}

int main()
{
	TcpServerController* server1 = new TcpServerController("127.0.0.1", 40000, "Default TCP Server");
	server1->SetServerNotifCallback(appln_client_connected, appln_client_disconnected, appln_client_msg_recvd);
	server1->Start();
	scanf_s("\n");
	server1->Display();
	return 0;
}