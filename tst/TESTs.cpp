//
// Created by galva on 3/5/2022.
//

#include <gtest/gtest.h>
#include "MockClient.h"

TEST(ServerTesting, NamesRequest){
    MockClient mockObject;
    EXPECT_CALL(mockObject, connect("Names"))
    .Times(1);
}

TEST(ServerTesting, MatrixRequest){
    MockClient mockObject;
    EXPECT_CALL(mockObject, connect("MatrixSize"))
    .Times(1);
}

TEST(ServerTesting, PlayerNamesRequest){
    MockClient mockObject;
    EXPECT_CALL(mockObject, connect("PlayerNames"))
            .Times(1);
}

TEST(ServerTesting, CardRequest){
    MockClient mockObject;
    EXPECT_CALL(mockObject, connect("Card"))
            .Times(1);
}

TEST(ServerTesting, ValidateCardRequest){
    MockClient mockObject;
    EXPECT_CALL(mockObject, connect("Validate"))
    .Times(1);
}