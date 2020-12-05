/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-12-05 21:58:18
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-05 22:20:17
 */
#ifndef FORMULA_HPP 
#define FORMULA_HPP

#define PI 3.1415926535
#include <math.h>
#include <string>
#include "OpString.hpp"
class Formula
{
    private:
    /* data */
    public:

    std::string GetCircleArea(std::string radius);
    std::string GetCircleArea(double radius);

    std::string GetCircleCircumference(std::string radius);
    std::string GetCircleCircumference(double radius);
    //Formula(/* args */);
    //~Formula();
};



#endif // FORMULA_HPP 
