//
// Created by mauro on 6/17/21.
//

#include <QString>
#include "../Headers/ConectionManager.h"

ConectionManager::ConectionManager(){
    // Crear un socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        cout << "Error al crear el socket" << endl;
    }
    else {
        // Agregar el IP y puerto al socket
        port = 54000; // Puerto
        ipAddress = "127.0.0.1"; // Localhost
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        //	Conectarse al servidor
        connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
        if (connectRes == -1) {
            cout << "Error al conectarse al servidor" << endl;
        }
        /*else {

            //	Close the socket
            close(sock);
        }*/
    }
}

QString ConectionManager::mandarPeticion(string mensajeCliente) {
    // Enviar al servidor
    sendRes = send(sock, mensajeCliente.c_str(), mensajeCliente.size() + 1, 0);
    if (sendRes == -1) {
        cout << "No se pudo enviar al servidor!\r\n";
    }
    else {
        // Esperar la respuesta del servidor
        memset(buf, 0, 4096);
        bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1) {
            cout << "Hubo un error con la respuesta del servidor\r\n";
        }
        else {
            // Mostrar la respuesta
            return QString::fromUtf8(string(buf, bytesReceived).c_str());
        }
    }
    return NULL;
}