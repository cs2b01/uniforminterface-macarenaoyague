//
// Created by Macarena Oyague on 2019-04-10.
//

#include "catch.hpp"
#include "factorial.h"

TEST_CASE("Evaluacion de Limite de Factorial") {
    REQUIRE(factorial(1)==1)
    REQUIRE(factorial(0)==0)
}
