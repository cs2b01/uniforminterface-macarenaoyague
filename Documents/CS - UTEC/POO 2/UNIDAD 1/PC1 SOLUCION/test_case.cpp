
#include "catch.hpp"
#include "calc.cpp"

#include <string>
using namespace std;

TEST_CASE("Calculadora") {

    SECTION("Debe crearse sin parametros") {

        // Arrange

        // Act
        Calc* calc= new Calc();
        // Assert
        REQUIRE(calc->obtenerNumeroElementos() ==  0);
        delete calc;
    }

    SECTION("Debe validar errores usando excepciones"){
        // Arrange
        Calc* calc= new Calc();
        // Act & Assert
        REQUIRE_THROWS_AS(calc->obtenerElementoMayor(), logic_error);
        REQUIRE_THROWS_AS(calc->obtenerElementoMenor(), logic_error);
        REQUIRE_THROWS_AS(calc->calcularPromedio(), logic_error);
        REQUIRE_THROWS_AS(calc->obtenerMediana(), logic_error);
        delete calc;

    }

    SECTION("Debe registrar elementos") {

        // Arrange
        Calc* calc= new Calc();
        double f1 = 2.5f, f2 = 2.7f, f3 =2.6f, f4=2.3f;

        // Act
        calc->registrarElemento(f1);
        calc->registrarElemento(f2);
        calc->registrarElemento(f3);
        calc->registrarElemento(f4);
        // Assert
        REQUIRE(calc->obtenerNumeroElementos() ==  4);
        delete calc;
    }


    SECTION("Debe obtener el elemento mayor") {
        // Arrange
        Calc* calc= new Calc();
        double f1 = 2.5f, f2 = 2.7f, f3 =2.6f, f4=2.3f;
        calc->registrarElemento(f1);
        calc->registrarElemento(f2);
        calc->registrarElemento(f3);
        calc->registrarElemento(f4);
        // Act
        double expected = f2;
        double actual = calc->obtenerElementoMayor();
        // Assert
        REQUIRE( expected ==  actual);
        delete calc;

    }

    SECTION("Debe obtener el elemento menor") {
        // Arrange
        Calc* calc= new Calc();
        double f1 = 2.5f, f2 = 2.7f, f3 =2.6f, f4=2.3f;
        calc->registrarElemento(f1);
        calc->registrarElemento(f2);
        calc->registrarElemento(f3);
        calc->registrarElemento(f4);
        // Act
        double expected = f4;
        double actual = calc->obtenerElementoMenor();
        // Assert
        REQUIRE( expected ==  actual);
        delete calc;

    }

    SECTION("Debe calcular el promedio") {
        // Arrange
        Calc* calc= new Calc();
        double f1 = 2.5f, f2 = 2.7f, f3 =2.6f, f4=2.3f;
        calc->registrarElemento(f1);
        calc->registrarElemento(f2);
        calc->registrarElemento(f3);
        calc->registrarElemento(f4);
        // Act
        double expected = (f1+f2+f3+f4)/4;
        double actual = calc->calcularPromedio();
        //Assert
        REQUIRE(expected == actual);
        delete calc;

    }

    SECTION("Debe calcular la mediana con elementos pares") {
        // Arrange
        Calc* calc= new Calc();
        double f1 = 2.5f, f2 = 2.7f, f3 =2.6f, f4=2.3f;
        calc->registrarElemento(f1);
        calc->registrarElemento(f2);
        calc->registrarElemento(f3);
        calc->registrarElemento(f4);
        // Act
        double expected = (f1+f3)/2;
        double actual = calc->obtenerMediana();
        //Assert
        REQUIRE(expected == actual );
        delete calc;
    }

    SECTION("Debe calcular la mediana con elementos impares") {
        // Arrange
        Calc* calc= new Calc();
        double f1 = 2.5f, f2 = 2.7f, f3 =2.6f, f4=2.3f, f5=2.4f;
        calc->registrarElemento(f1);
        calc->registrarElemento(f2);
        calc->registrarElemento(f3);
        calc->registrarElemento(f4);
        calc->registrarElemento(f5);
        // Act
        double expected = f1;
        double actual = calc->obtenerMediana();
        // Assert
        REQUIRE(expected == actual);
        delete calc;
    }



}

