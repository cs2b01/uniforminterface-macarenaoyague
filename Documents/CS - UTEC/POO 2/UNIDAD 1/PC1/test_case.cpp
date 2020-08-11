
#include "catch.hpp"
#include "calc.cpp"


#include <string>


TEST_CASE("Calculadora") {


    SECTION("Debe crearse sin parametros") {

        // Arrange Local

        // Act
        Calc* calc= new Calc();
        // Assert

        // TODO: Calcular el total de items leidos del archivo
        REQUIRE(calc->obtenerNumeroElementos() ==  0);
        delete calc;
    }

    SECTION("Debe registrar elementos") {

        // Arrange Local
        Calc* calc= new Calc();

        // Act
        calc->registrarElemento(2.5);
        // Assert
        REQUIRE(calc->obtenerNumeroElementos() ==  1);
        delete calc;
    }


    SECTION("Debe obtener el elemento mayor") {
        // Arrange Local
        Calc* calc= new Calc();

        calc->registrarElemento(2.5);
        calc->registrarElemento(2.7);
        calc->registrarElemento(2.6);
        calc->registrarElemento(2.3);
        // Act & Assert

        float expected=2.7;
        REQUIRE(calc->obtenerElementoMayor()==expected);
        delete calc;

    }

    SECTION("Debe obtener el elemento menor") {
        // Arrange Local
        Calc* calc= new Calc();

        calc->registrarElemento(2.5);
        calc->registrarElemento(2.7);
        calc->registrarElemento(2.6);
        calc->registrarElemento(2.3);
        // Act & Assert

        float expected=2.3;
        REQUIRE(calc->obteneElementoMenor() ==  expected);
        delete calc;

    }

    SECTION("Debe calcular el promedio") {
        // Arrange Local
        Calc* calc= new Calc();

        float elemento1=2.5f;
        float elemento2=2.7f;
        float elemento3=2.6f;
        float elemento4=2.3f;
        calc->registrarElemento(elemento1);
        calc->registrarElemento(elemento2);
        calc->registrarElemento(elemento3);
        calc->registrarElemento(elemento4);
        // Act & Assert

        float expected=(elemento1+elemento2+elemento3+elemento4)/4;
        REQUIRE(calc->calcularPromedio() ==  expected);
        delete calc;
    }

    SECTION("Debe calcular la mediana (n impar)") {
        // Arrange Local
        Calc* calc= new Calc();
        calc->registrarElemento(2.5);
        calc->registrarElemento(2.7);
        calc->registrarElemento(2.6);
        calc->registrarElemento(2.3);
        calc->registrarElemento(2.9);
        // Act & Assert

        float expected=2.6;
        REQUIRE(calc->obtenerMediana()== expected);
        delete calc;
    }

    SECTION("Debe calcular la mediana (n par)") {
        // Arrange Local
        Calc* calc= new Calc();
        calc->registrarElemento(2.6);
        calc->registrarElemento(2.7);
        calc->registrarElemento(2.4);
        calc->registrarElemento(2.3);
        // Act & Assert

        float expected=2.5;
        REQUIRE(calc->obtenerMediana()==expected);
        delete calc;
    }

}

