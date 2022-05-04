//
// Created by tavo on 28/3/22.
//

#include <string>
#include "headers/CommandHandler.h"
#include "headers/Server.h"

using namespace std;
/**
 * Este metodo se encarga de ejecutar una accion en funcion a el tipo de peticion.
 * @param Json Estructura json en string que contiene la peticion del cliente.
 */
void CommandHandler::Handle(string Json){

    CommandMap[Json]();
}

 void CommandHandler::SaveNames() { //Guardado y muestra de nombres en la interfaz del servidor.
     string response = "Saving player names";
     Server::sender(response, server);
}
/**
 * Este metodo se encarga de responder a la peticion del tamaño de la matriz.
 */
void CommandHandler::sendMatrixSize(){
    string response = "Matrix size: 6x5";
    Server::sender(response, server);
}

/**
 * Este metodo se encarga de responder a la peticion de los nombres de jugadores.
 */
void CommandHandler::sendNames(){
    string response = "Player names: XXXX, AAAA";
    Server::sender(response, server);
}
/**
 * Este metodo se encarga de enviar el ID de la imagen al cliente.
 */
void CommandHandler::sendCardImage() {
    //int ID = pagedArray(JSON["I"], JSON["J"]);
    int ID = 0;
    //Server::sender(response, server);
    times++;
    if (times == 1){
        Card1 = ID;
    }else{
        Card2 = ID;
        times = 0;
    }
}

void CommandHandler::validateCards(){ //Valida el par de cartas seleccionadas y lo envia al cliente.
    string response = "Card equals";
    Server::sender(response, server);
}

/**
 * Constructor de la clase, almacena instancias necesarias y crea el HashMap con los metodos para las peticiones.
 * @param socket socket del servidor para envio de datos.
 * @param windowInstance instancia de la ventana del servidor para realizar modificaciones a la misma.
 */
CommandHandler::CommandHandler(int socket) {
    server = socket;
    CommandMap["Names"] = [this]() {SaveNames();};
    CommandMap["MatrixSize"] = [this]() {sendMatrixSize();};
    CommandMap["PlayerNames"] = [this]() {sendNames();};
    CommandMap["Card"] = [this]() {sendCardImage();};
    CommandMap["Validate"] = [this]() {validateCards();};
}
