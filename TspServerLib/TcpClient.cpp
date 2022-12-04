#include "TcpClient.h"
#include <stdio.h>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <memory.h>
#include <windows.h>
#include <io.h>
#include "network_utils.h"
#include "TcpMsgDemarcar.h"


TcpClient::TcpClient(uint32_t ip_addr, uint16_t port_no) {

    this->ip_addr = ip_addr;
    this->port_no = port_no;
}

void
TcpClient::Display() {

    char ip_addr_str1[16];
    char ip_addr_str2[16];

    printf("Tcp Client : [%s , %d] connected to [%s, %d]\n",
        network_convert_ip_n_to_p(this->ip_addr, ip_addr_str1),
        (this->port_no),
        network_convert_ip_n_to_p(this->server_ip_addr, ip_addr_str2),
        (this->server_port_no)
    );
}

void
TcpClient::Abort() {

    if (this->comm_fd) {
        close(this->comm_fd);
        this->comm_fd = 0;
    }

    this->tcp_ctrlr = NULL;

    if (this->msgd) {
        this->msgd->Destroy();
        delete this->msgd;
        this->msgd = NULL;
    }

    delete this;
}