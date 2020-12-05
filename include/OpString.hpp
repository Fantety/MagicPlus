/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety  
 * @Date: 2020-11-26 20:52:12
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-02 15:23:36
 */
#ifndef OPSTRING_HPP 
#define OPSTRING_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>

typedef struct variant
{
    int dataPos=0;
    std::string str;
    size_t pos;
    size_t length;
    double vaule;
}variant;

class OpString
{
    public:
    std::vector<variant> var;
    public:
    static std::vector<std::string> StringSplit(std::string inputStr ,char splitMark);
    static double StringToDouble(std::string inputStr);
    static std::string DoubleToString(double inputDouble);
    std::string StringExtract(std::string inputStr,char preStr);
};

#endif // OPSTRING_HPP 

