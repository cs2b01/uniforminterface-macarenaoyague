//
// Created by Macarena Oyague on 2019-09-28.
//

#include "catch.hpp"
#include "dynamic_array.cpp"
using namespace std;

TEST_CASE("Arreglo dinamico"){

    SECTION("Debe crearse"){

        //Arrange and Act
        auto array1 = new DynamicArray <int, 5> ();

        //Assert
        unsigned int expectedSize = 0;
        unsigned int actualSize = array1 -> getSize();
        delete array1;

        REQUIRE(expectedSize == actualSize);
    }

    SECTION("Debe adicionar elementos al final"){

        //Arrange and Act
        auto array1 = new DynamicArray <int, 2>();
        int dato1 = 100, dato2 = 50;

        //Act
        array1->pushBack(dato1);
        array1->pushBack(dato2);

        //Assert
        unsigned int expectedSize = 2;
        unsigned int actualSize = array1 -> getSize();

        REQUIRE(expectedSize == actualSize);

    }

    SECTION("Verificar los elementos"){

        //Arrange and Act
        auto array1 = new DynamicArray <int, 2>();
        int dato1 = 100, dato2 = 50;

        //Act
        array1->pushBack(dato1);
        array1->pushBack(dato2);

        //Assert
        unsigned int expectedSize = 2;
        unsigned int actualSize = array1 -> getSize();

        REQUIRE(expectedSize == actualSize);
        REQUIRE(dato1 == array1 -> getItem(0));
        REQUIRE(dato2 == array1 -> getItem(1));

    }

    SECTION("Debe reservas mas espacio cuando llega a la capacidad reservada"){

        //Arrange and Act
        auto array1 = new DynamicArray <int, 2>();
        int dato1 = 100, dato2 = 50, dato3 = 15;

        //Act
        array1->pushBack(dato1)->pushBack(dato2)->pushBack(dato3);

        //Assert
        unsigned int expectedReserved = 4;
        unsigned int actualReserved = array1 -> getReserved();

        REQUIRE(expectedReserved == actualReserved);
    }

    SECTION("Debe eliminar el elemento de una posicion"){
        //Arrange and Act
        auto array1 = new DynamicArray <int, 2>();
        int dato1 = 100, dato2 = 50, dato3 = 15;

        //Act
        array1->pushBack(dato1)->pushBack(dato2)->pushBack(dato3);
        array1->removeElement(2);

        //Assert
        unsigned int expectedSize = 2;
        unsigned int expectedReserved = 2;
        unsigned int actualSize = array1 -> getReserved();
        unsigned int actualReserved = array1 -> getReserved();

        REQUIRE(expectedReserved == actualReserved);
        REQUIRE(expectedSize == actualSize);
    }

    SECTION("Debe un  elemento en una posicion"){
        //Arrange and Act
        auto array1 = new DynamicArray <int, 3>();
        int dato1 = 100, dato2 = 50, dato3 = 15;
        int expectedElement = 88;

        //Act
        array1->pushBack(dato1)->pushBack(dato2)->pushBack(dato3);
        array1->addElement(2, expectedElement);

        //Assert
        unsigned int actualElement = array1 -> getItem(2);

        REQUIRE(expectedElement == actualElement);
    }

    SECTION("Debe ordenar de mayor a menor"){
        //Arrange and Act
        auto array1 = new DynamicArray <char, 3>();
        int dato1 = 10, dato2 = 50, dato3 = 15;

        //Act
        array1->pushBack(dato1)->pushBack(dato2)->pushBack(dato3)->sort();

        //Assert
        unsigned int mayorItem = array1 -> getItem(0);

        REQUIRE(mayorItem == dato2);
    }

}