//
// Created by mauro on 6/17/21.
//

#ifndef LITTLESOCER_CONECTIONMANAGER_H
#define LITTLESOCER_CONECTIONMANAGER_H
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

class ConectionManager {
public:
    int sock;
    int port;
    int sendRes;
    int bytesReceived;
    string ipAddress;
    sockaddr_in hint;
    int connectRes;
    char buf[4096];

    ConectionManager();
    QString mandarPeticion(string mensajeCliente);


};


#endif //LITTLESOCER_CONECTIONMANAGER_H
