//
// Created by tavo on 28/3/22.
//

#ifndef MEMORY_GAME_COMMANDHANDLER_H
#define MEMORY_GAME_COMMANDHANDLER_H

#include <functional>
#include <map>
#include "PagedArray.h"

using namespace std;
/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: C++.
 * Clase CommandHandler.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de manejar todas las peticiones realizadas por el cliente mediante JSON.
 */
class CommandHandler {
public:
    void Handle(string json);
    string J1, J2;
    CommandHandler(int socket);

private:
    map<string, function<void()>> CommandMap;
    void SaveNames(), sendMatrixSize(), sendNames(), sendCardImage(), validateCards();
    int server, Card1, Card2, times;
    PagedArray pagedArray;
};


#endif //MEMORY_GAME_COMMANDHANDLER_H
