//
// Created by Macarena Oyague on 5/24/20.
//

#ifndef SOLVER_MACARENAOYAGUE_EQUATION_H
#define SOLVER_MACARENAOYAGUE_EQUATION_H

#include "Node.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Equation{

private:

    string eq;
    Node *root;

    bool conditionParenthesis(string str, string::iterator end){
        auto it = str.begin();
        bool count = false;
        while(it != end)
        {
            if (*it == '(')
                count = true;
            if (*it == ')' && !count)
                return false;
            it++;
        }
        return true;
    }

    string eliminateParenthesis(string str){
        auto end = str.begin()+(str.size()-1);
        if (*str.begin() == '(' && *end == ')' && conditionParenthesis(str, end))
        {
            str.erase (end);
            str.erase (str.begin());
            cout<<str<<" ";
            return eliminateParenthesis(str);
        }
        return str;
    }

    Node* generateTree(string portion){

        Node *current = nullptr;

        if (portion.size() == 1)
            if (isalpha(portion[0]))
            {
                current = new Node(portion[0], Variable);
                return current;
            }

        if (portion[0] == '(') portion = eliminateParenthesis(portion);

        int parenthesis = 0, i = 0;
        int tempPosition = 0;
        char *temp = nullptr;
        int priority = 0;
        bool prevDigit = false;
        int contsum = 0;

        for(auto it = portion.begin(); i<portion.size(); it++, i++)
        {
            if (*it == '(')
                parenthesis++;
            else if (*it == ')')
                parenthesis--;
            if (parenthesis == 0)
            {
                if ((*it == '+' || *it == '-') && prevDigit)
                {
                    temp = &(*it);
                    if (priority != 3)
                        priority = 3;
                    tempPosition = i;
                }
                else if (priority < 3 && (*it == '*' || *it == '/'))
                {
                    temp = &(*it);
                    if (priority != 2)
                        priority = 2;
                    tempPosition = i;
                }
                else if (priority < 2 && *it == '^')
                {
                    temp = &(*it);
                    if (priority != 2)
                        priority = 2;
                    tempPosition = i;
                }
                if (isdigit(*it))
                    prevDigit = true;
                else
                    prevDigit = false;
            }
        }

        if (temp != nullptr)
        {
            current = new Node(*temp, Operator);
            if (i>0)
                current->left = generateTree(portion.substr(0, tempPosition));
            current->right = generateTree(portion.substr(tempPosition+1, portion.size()));
            return current;
        }

        float number = stof(portion);
        if (portion[0] == isdigit(portion[0]) or portion[0] == '-' or portion[0] == '+')
        for (int x = 1; x<portion.size(); x++)
        {
            if (!isdigit(portion[x]))
                throw std::invalid_argument("There is a mistake in the arguments");
        }

        current = new Node(number, Number);
        return current;
    }

    float generateAnswer(Node *current){
        float returnValue;
        if (current->dataType == Operator)
        {
            switch (current->op){
                case '+':
                    if (current->left != nullptr )
                        return generateAnswer(current->left) + generateAnswer(current->right);
                    else
                        return + generateAnswer(current->right);
                case '-':
                    if (current->left != nullptr)
                        return generateAnswer(current->left) - generateAnswer(current->right);
                    else
                        return - generateAnswer(current->right);
                case '*':
                    return generateAnswer(current->left) * generateAnswer(current->right);
                case '/':
                {
                    auto temp = generateAnswer(current->right);
                    if (temp != 0)
                        return generateAnswer(current->left) / temp;
                    else
                        throw std::logic_error("Division by zero is undefined");
                }
                case '^':
                    return pow(generateAnswer(current->left), generateAnswer(current->right));
            }
        }
        else if (current->dataType == Number)
            return current->num;
        else
            throw std::invalid_argument("There is a missing variable definition");
    };

    Node * searchInTree(char var, Node* current){/*
        Node* returnNode = nullptr;
        if (current->dataType == Variable && current->var == var)
            return current;
        if (current->left != nullptr)
            searchInTree(var, current->left);
        else if (current->right != nullptr)
            searchInTree(var, current->left);*/
    }

public:
    Equation(string eq) : eq(eq), root(nullptr) {
        parse();
    }

    void parse(){
    root = generateTree(eq);
    }

    float execute(){
        return generateAnswer(root);
    }

    void setVariable(char var, float num){
        Node* toSet = searchInTree(var, root);
        toSet->setDataType(Number);
        toSet->setNum(num);
    }

};

#endif //SOLVER_MACARENAOYAGUE_EQUATION_H
