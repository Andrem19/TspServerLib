#include "TcpClientServiceManager.h"
#include "TcpServerController.h"

TcpClientServiceManager::TcpClientServiceManager(TcpServerController* tcp_ctrlr) {
    this->tcp_ctrlr = tcp_ctrlr;
}
TcpClientServiceManager::~TcpClientServiceManager() {

}

void TcpClientServiceManager::StartTcpClientServiceManagerThread() {

}
void TcpClientServiceManager::ClientFDStartListed(TcpClient* tcp_client) {

}
