//
// Created by Macarena Oyague on 5/23/20.
//

#ifndef SOLVER_MACARENAOYAGUE_TOKEN_H
#define SOLVER_MACARENAOYAGUE_TOKEN_H

#include <stdexcept>
#include <string>

enum DataType{
    RightParenthesis,
    LeftParenthesis,
    SumSubsOperator,
    MultDivOperator,
    Number,
    Variable
};

/* for parsing

  char str[]="1776ad";
  int year;

  if (isdigit(str[0]))
  {
    year = atoi (str);
    printf ("The year that followed %d was %d.\n",year,year+1);
  }

  leer si es digito, concatenar

*/


class Token{
    void assignTokenType(){
        if (element == '(')
            tokenType =  LeftParenthesis;
        else if (element == ')')
            tokenType =  RightParenthesis;
        else if (element == '+' || element == '-')
            tokenType = SumSubsOperator;
        else if (element == '*' || element == '/')
            tokenType = MultDivOperator;
        else if (element >= 48 && element <= 57)  //numbers in ascii
            tokenType = Number;
        else if ((element >= 65 && element <= 90) || (element >= 97 && element <= 122))  //letters in ascii
            tokenType = Variable;
        else
            throw std::invalid_argument("'"+std::string(1, element)+"'"+" is not valid to implement in the equation");
    }
public:
    Token(char token){
        element = token;
        assignTokenType();
    }
    char element;
    DataType tokenType;
};

#endif //SOLVER_MACARENAOYAGUE_TOKEN_H
