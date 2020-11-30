/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-27 23:18:32
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-29 14:43:41
 */
#ifndef ARITHMETIC_CPP 
#define ARITHMETIC_CPP

#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include "DataBase.hpp"
#include "CmdAnaly.hpp"

class Arithmetic
{
    private:
    double postfixExpression(const std::string &str);
    int priority(const std::string str);
    std::string InfixToPostfi(const std::string &str);

    private:
    std::string str;
    double result;
    CmdAnaly *cmdAnaly;
    DataBase* db;

    public:
    Arithmetic(const char* cmd);
    ~Arithmetic();
    void out();
    void outS();
    private:
    void preDeal();
    void WriteDatabase();
};

#endif // Arithmetic.cpp