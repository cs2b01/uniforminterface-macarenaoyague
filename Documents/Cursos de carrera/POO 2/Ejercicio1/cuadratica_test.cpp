//
// Created by Macarena Oyague on 2019-09-07.
//

#include "catch.hpp"
#include "cuadratica.cpp"

//Ciclo de TDD: Rojo, Verde, Refactorizar

TEST_CASE("Ecuacion Cuadratica"){

    //Arrange: Preparar los datos de entrada
    float A=5, B=4, C=-1;

    //Act: Ejecutar el metodo a probar
    Cuadratica * cuadratica= new Cuadratica(A, B, C);

    SECTION("Debe saber crearse con los terminos A, B y C"){

        //Assert
        REQUIRE(A==cuadratica->getA());
        REQUIRE(B==cuadratica->getB());
        REQUIRE(C==cuadratica->getC());
    }

    SECTION("Debe calcular raiz X1"){

        //Arrange
        float x1=cuadratica->calcularX1();

        //Assert
        float expectedX1=0.2;
        REQUIRE(x1==expectedX1);
    }

    SECTION("Debe calcular raiz X2"){

        //Arrange
        float x2=cuadratica->calcularX2();

        //Assert
        float expectedX2=-1;
        REQUIRE(x2==expectedX2);

    }

    SECTION("Comprobar discriminante =/ de 0"){

        //Arrange
        bool expected=cuadratica->calcularDiscriminante();

        //Assert
        REQUIRE(expected);

    }

}