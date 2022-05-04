//
// Created by tavo on 03/05/22.
//

#ifndef UNIT_TESTINGC___MOCKCLIENT_H
#define UNIT_TESTINGC___MOCKCLIENT_H
#include <gmock/gmock.h>
#include "headers/Server.h"

class MockClient : public Server {
public:
    MOCK_METHOD1(connect, void (string Type));
};


#endif //UNIT_TESTINGC___MOCKCLIENT_H
