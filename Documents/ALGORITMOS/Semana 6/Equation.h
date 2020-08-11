//
// Created by Macarena Oyague on 5/24/20.
//

#ifndef SOLVER_MACARENAOYAGUE_EQUATION_H
#define SOLVER_MACARENAOYAGUE_EQUATION_H

#include "Token.h"
#include <vector>
using namespace std;

class Equation{
    string eq;
    vector<Token*> tokens;

    void reduceSigns(){     ///change to iterators
        auto cont = 0;
        while(cont != tokens.size())
        {
            if (tokens[cont]->tokenType == SumSubsOperator and tokens[cont+1]->tokenType  == SumSubsOperator)
            {
                if ((tokens[cont]->element == '-') && (tokens[cont+1]->element == '-'))
                {
                    tokens[cont]->element = '+';
                    tokens.erase (tokens.begin()+cont+1);
                }
                else if (tokens[cont]->element < tokens[cont+1]->element)
                    tokens.erase (tokens.begin()+cont);
                else
                    tokens.erase (tokens.begin()+cont+1);
            }
        }
    }













    -------------------



    
    c+5*RESULT^4;

    analyse expression;








    ( ) + - * / numeros variables


    void analize(int count){
        if (tokens[count]->tokenType == LeftParenthesis)
    }

public:
    Equation(string eq) : eq(eq) {}

    void doScan(){
        for (auto element: eq)
            tokens.push_back(new Token(element));
        reduceSigns();
    }

    void doParsing(){
        analize(0);
    }

    float execute(){
        doParsing();
    }
};

#endif //SOLVER_MACARENAOYAGUE_EQUATION_H
