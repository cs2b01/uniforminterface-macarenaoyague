#include <iostream>
#include "repo.h"
#include "element.h"
#include <sstream>
using namespace std;

bool isAlbania(Element* element){
    if (element->getLocation()=="Albania")
        return true;
    else
        return false;
}

bool compareYear(Element* element1, Element* element2){
    if (element1->getYear()<=element2->getYear())
        return true;
    else
        return false;
}

bool isExport(Element* element){
    if (element->getFlow()=="Export")
        return true;
    else
        return false;
}

bool compareCommCode(Element* element1, Element* element2){
    if (element1->getComm_code()<=element2->getComm_code())
        return true;
    else
        return false;
}


int main() {

    Repo<Element>* repo1 = new Repo<Element> (",");

    Element* element1 = new Element("Peru", 2019, 33333, "Goats live", "Export", 3333,33,"01_live_animals");
    Element* element2 = new Element("Peru", 2019, 33333, "Goats live", "Export", 3333,33,"01_live_animals");

    repo1->insert(element1);
    repo1->insert(element2);

    for (Element* element: *(repo1->getElements()))
        cout<<element->getLocation()<<","<<element->getYear()<<","
            <<element->getComm_code()<<","<<element->getCommodity()<<","
            <<element->getFlow()<<","<<element->getTrade_usd()<<","
            <<element->getQuantity()<<","<<element->getCategory()<<endl;

    Repo<Element>* repo2 = new Repo<Element> (".");
    repo2->load_from("sample_data.csv", [repo2](string cadena){vector <string> campos; stringstream stream(cadena);
                                                                string campo;
                                                                while(getline(stream,campo,repo2->getSeparador()[0])){
                                                                if (campo == "") campos.push_back("0");
                                                                else campos.push_back(campo);}
                                                                return new Element(campos[0],stoll(campos[1]),stoll(campos[2]),
                                                                        campos[3],campos[4], stoll(campos[5]),stoll(campos[6]),campos[7]);});

    for (Element* element: *(repo2->getElements()))
        cout<<element->getLocation()<<","<<element->getYear()<<","
            <<element->getComm_code()<<","<<element->getCommodity()<<","
            <<element->getFlow()<<","<<element->getTrade_usd()<<","
            <<element->getQuantity()<<","<<element->getCategory()<<endl;

    Repo<Element>* repo3 = repo2->save_to("newFile1.csv", [repo2](Element* element){return element->getLocation() + repo2->getSeparador() + to_string(element->getYear()) + repo2->getSeparador() +
                                                                                     to_string(element->getComm_code()) + repo2->getSeparador() + element->getCommodity() + repo2->getSeparador() +
                                                                                     element->getFlow() + repo2->getSeparador() + to_string(element->getTrade_usd()) + repo2->getSeparador() +
                                                                                     to_string(element->getQuantity()) + repo2->getSeparador() + element->getCategory();});

    Repo<Element>* repo4 = repo1->save_to("newFile2.csv", [repo1](Element* element){return element->getLocation() + repo1->getSeparador() + to_string(element->getYear()) + repo1->getSeparador() +
                                                                                           to_string(element->getComm_code()) + repo1->getSeparador() + element->getCommodity() + repo1->getSeparador() +
                                                                                           element->getFlow() + repo1->getSeparador() + to_string(element->getTrade_usd()) + repo1->getSeparador() +
                                                                                           to_string(element->getQuantity()) + repo1->getSeparador() + element->getCategory();});


    vector<Element*>* select1 = repo2->select(isAlbania, compareYear);

    for (Element* element: *(select1))
        cout<<element->getLocation()<<","<<element->getYear()<<","
            <<element->getComm_code()<<","<<element->getCommodity()<<","
            <<element->getFlow()<<","<<element->getTrade_usd()<<","
            <<element->getQuantity()<<","<<element->getCategory()<<endl;

    vector<Element*>* select2 = repo2->select(isExport, compareCommCode);

    for (Element* element: *(select2))
        cout<<element->getLocation()<<","<<element->getYear()<<","
            <<element->getComm_code()<<","<<element->getCommodity()<<","
            <<element->getFlow()<<","<<element->getTrade_usd()<<","
            <<element->getQuantity()<<","<<element->getCategory()<<endl;


    repo2->select_and_save("newFile3.csv", isAlbania, compareCommCode, [repo2](Element* element){return element->getLocation() + repo2->getSeparador() + to_string(element->getYear()) + repo2->getSeparador() +
                                                                                                    to_string(element->getComm_code()) + repo2->getSeparador() + element->getCommodity() + repo2->getSeparador() +
                                                                                                    element->getFlow() + repo2->getSeparador() + to_string(element->getTrade_usd()) + repo2->getSeparador() +
                                                                                                    to_string(element->getQuantity()) + repo2->getSeparador() + element->getCategory();} );

    repo2->select_and_save("newFile4.csv", isExport, compareYear, [repo2](Element* element){return element->getLocation() + repo2->getSeparador() + to_string(element->getYear()) + repo2->getSeparador() +
                                                                                                        to_string(element->getComm_code()) + repo2->getSeparador() + element->getCommodity() + repo2->getSeparador() +
                                                                                                        element->getFlow() + repo2->getSeparador() + to_string(element->getTrade_usd()) + repo2->getSeparador() +
                                                                                                        to_string(element->getQuantity()) + repo2->getSeparador() + element->getCategory();} );

    unsigned int count = repo2->count(isAlbania);
    cout<<count<<endl;

    unsigned int count2 = repo2->count(isExport);
    cout<<count2<<endl;

    Element* min = repo2->min(isAlbania, [](Element* element, Element* element2){if (element->getYear()<element2->getYear()) return true; else return false;});

    cout<<min->getLocation()<<","<<min->getYear()<<","
        <<min->getComm_code()<<","<<min->getCommodity()<<","
        <<min->getFlow()<<","<<min->getTrade_usd()<<","
        <<min->getQuantity()<<","<<min->getCategory()<<endl;

    Element* min2 = repo2->min(isExport, [](Element* element, Element* element2){if (element->getQuantity()<element2->getQuantity()) return true; else return false;});

    cout<<min2->getLocation()<<","<<min2->getYear()<<","
        <<min2->getComm_code()<<","<<min2->getCommodity()<<","
        <<min2->getFlow()<<","<<min2->getTrade_usd()<<","
        <<min2->getQuantity()<<","<<min->getCategory()<<endl;

    Element* max = repo2->max(isAlbania, [](Element* element, Element* element2){if (element->getYear()>element2->getYear()) return true; else return false;});

    cout<<max->getLocation()<<","<<max->getYear()<<","
        <<max->getComm_code()<<","<<max->getCommodity()<<","
        <<max->getFlow()<<","<<max->getTrade_usd()<<","
        <<max->getQuantity()<<","<<max->getCategory()<<endl;

    Element* max2 = repo2->max(isExport, [](Element* element, Element* element2){if (element->getQuantity()>element2->getQuantity()) return true; else return false;});

    cout<<max2->getLocation()<<","<<max2->getYear()<<","
        <<max2->getComm_code()<<","<<max2->getCommodity()<<","
        <<max2->getFlow()<<","<<max2->getTrade_usd()<<","
        <<max2->getQuantity()<<","<<max2->getCategory()<<endl;

    double datafromAfghanistan = repo2->sum([](Element* element){if (element->getLocation() == "Afghanistan") return true; else return false;},
                     [](Element* element){return 1;});

    cout<<datafromAfghanistan<<endl;

    double dataImport = repo2->sum([](Element* element){if (element->getFlow() == "Import") return true; else return false;},
                                        [](Element* element){return 1;});

    cout<<dataImport<<endl;

    return 0;
}