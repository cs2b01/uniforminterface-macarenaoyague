//
// Created by estanislao.contreras on 6/8/2019.
//

#include "catch.hpp"
#include "product.cpp"
#include "repository.cpp"

#include <string>

TEST_CASE("Clase Product",""){
    // Arrange - Global - Se ejecuta para cada seccion
    string code="PR010";
    string brand="Samsung";
    string name="SM";
    string category="Tablet";
    float price=2599.00;
    string line = code+";"+brand+";"+name+";"+category+";"+to_string(price);


    SECTION("Debe crearse a partir de un string con campos separados por ';'") {
        // Arrange Local

        // Act
        Product* p = new Product(line);

        // Assert
        REQUIRE(p != nullptr);
        REQUIRE(p->getCode() == code);
        REQUIRE(p->getBrand() == brand);
        REQUIRE(p->getName() == name);
        REQUIRE(p->getCategory() == category);
        REQUIRE(p->getPrice() == price);
        // Finalize Local
        delete p;
    }

    SECTION("Debe crearse con parametros para cada atributo") {
        // Arrange Local

        // Act
        Product* p = new Product(code, brand, name, category, price);

        // Assert
        REQUIRE(p != nullptr);
        REQUIRE(p->getCode() == code);
        REQUIRE(p->getBrand() == brand);
        REQUIRE(p->getName() == name);
        REQUIRE(p->getCategory() == category);
        REQUIRE(p->getPrice() == price);
        // Finalize Local
        delete p;
    }

    SECTION("Debe representarse como un string con campos separados por ';' y terminar en \\n") {
        // Arrange Local
        Product* p = new Product(code, brand, name, category, price);
        string expected = line + "\n";


        // Act
        string actual = p->toLine();

        // Assert
        REQUIRE(expected == actual);

        // Finalize Local
        delete p;
    }

    // Finalize Global

}


TEST_CASE("Clase Repository","") {
    string fileName = "Product.txt";
    unsigned int totalProducts = 10;
    auto lineToObject = [](string line){ return new Product(line);};
    auto objectToLine = [](Product *product){ return product->toLine();};

    SECTION("Debe crearse recibiendo un nombre de archivo y una expresion lambda") {
        // Al crearse el repositorio debe creare los items del archivo

        // Arrange Local

        // Act
        Repository<Product>* repo = new Repository<Product>(fileName,lineToObject);
        // Assert
        REQUIRE(fileName == repo->getFileName());
        REQUIRE(totalProducts == repo->getItems()->size());
        delete repo;

    }

    SECTION("Debe adicionar nuevos items") {
        // Arrange Local
        string code="PR010";
        string brand="Samsung";
        string name="SM";
        string category="Tablet";
        float price=2599.00;

        Repository<Product>* repo = new Repository<Product>("Temp.txt",lineToObject);
        unsigned int expectedProducts = repo->getItems()->size()+1;
        // Act
        repo->add(new Product(code, brand, name, category, price));
        // Assert
        REQUIRE(expectedProducts == repo->getItems()->size());

        delete repo;

    }

    SECTION("Debe guardar los items actualizados en el archivo a traves de una expresion lambda") {

        // Arrange Local
        string code="PR010";
        string brand="Samsung";
        string name="SM";
        string category="Tablet";
        float price=2599.00;

        Repository<Product>* repo = new Repository<Product>("Temp.txt",lineToObject);
        repo->getItems()->clear();
        repo->add(new Product(code, brand, name, category, price));
        // Act
        repo->updateChanges(objectToLine);
        delete repo;
        repo = new Repository<Product>("Temp.txt",lineToObject);
        // Assert
        int expectedProducts = 1;
        REQUIRE(expectedProducts == repo->getItems()->size());
        delete repo;
    }

    SECTION("Debe encontrar el primer elemento que cumpla una condicion lambda") {

        // Arrange Local
        Repository<Product>* repo = new Repository<Product>(fileName,lineToObject);
        // Act
        auto tabletSamsung = [](Product* p){return p->getCategory()=="Tablet" and p->getBrand()=="Samsung";};
        auto* product = repo->findFirst(tabletSamsung);
        // Assert
        string expectedProductCode = "PR007";
        REQUIRE(expectedProductCode == product->getCode());
        delete repo;
    }

    SECTION("Debe encontrar el ultimo elemento que cumpla una condicion lambda") {

        // Arrange Local
        Repository<Product>* repo = new Repository<Product>(fileName,lineToObject);
        // Act
        auto* product = repo->findLast([](Product* p){return p->getBrand()=="Lenovo";});
        // Assert
        string expectedProductCode = "PR006";
        REQUIRE(expectedProductCode == product->getCode());
        delete repo;
    }

    SECTION("Debe contar, usando hilos, la cantidad de elementos que cumplen una condicion"){
        // Arrange Local
        Repository<Product>* repo = new Repository<Product>(fileName,lineToObject);
        // Act
        auto appleProductsCount= repo->count([](Product* p){return p->getBrand()=="Apple";});
        // Assert
        unsigned int expectedAppleProductCount = 3;
        REQUIRE(expectedAppleProductCount == appleProductsCount);
        delete repo;

    }

    SECTION("Debe evaluar un lambda y si cumple debe ejecutar un segundo lambda. Retorna la cantida de elementos afectados"){
        // Arrange Local
        Repository<Product>* repo = new Repository<Product>(fileName,lineToObject);
        // Act
        auto tablet= [](Product* p){return p->getCategory()=="Tablet";};
        auto increaseThePriceInTenPercent = [](Product* p){p->setPrice(p->getPrice()*1.10);};

        auto tabletsCount = repo->forEach(tablet,increaseThePriceInTenPercent);
        // Assert
        unsigned int expectedTabletCount = 5;
        REQUIRE(expectedTabletCount == tabletsCount);
        repo->updateChanges(objectToLine);
        delete repo;
    }

    SECTION("Debe ejecutar un lambda, usando hilos, con todos los elementos"){
        // Arrange Local
        Repository<Product>* repo = new Repository<Product>(fileName,lineToObject);
        // Act

        auto increaseThePriceInFivePercent = [](Product* p){p->setPrice(p->getPrice()*1.05);};

        repo->forAll(increaseThePriceInFivePercent);
        repo->updateChanges(objectToLine);
        // Assert
        REQUIRE(repo->getItems()->size()==10);
        delete repo;

    }



}