/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-26 20:52:12
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-30 12:10:38
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
    int dataPos;
    std::string str;
    size_t pos;
    size_t length;
}variant;

class OpString
{
    public:
    std::vector<variant> var;
    public:
    static std::vector<std::string> StringSplit(std::string inputStr ,char splitMark);
    static double StringToDouble(std::string inputStr);
    static std::string DoubleToString(double inputDouble);
    std::string StringExtract(std::string inputStr);
};

#endif // OPSTRING_HPP 

