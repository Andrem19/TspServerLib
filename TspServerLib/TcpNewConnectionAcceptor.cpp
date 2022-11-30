#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "TcpServerController.h"
#include "TcpNewConnectionAcceptor.h"

TcpNewConnectionAcceptor::TcpNewConnectionAcceptor(TcpServerController* tcp_ctrlr) {
    this->tcp_ctrlr = tcp_ctrlr;
}
TcpNewConnectionAcceptor::~TcpNewConnectionAcceptor() {

}
