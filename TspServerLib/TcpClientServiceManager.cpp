#include "TcpClientServiceManager.h"
#include "TcpServerController.h"

TcpClientServiceManager::TcpClientServiceManager(TcpServerController* tcp_ctrlr) {
    this->tcp_ctrlr = tcp_ctrlr;
}
TcpClientServiceManager::~TcpClientServiceManager() {

}
