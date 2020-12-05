/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-12-05 21:58:31
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-05 22:08:21
 */
#include "Formula.hpp"
std::string Formula::GetCircleArea(std::string radius) 
{
    double r=OpString::StringToDouble(radius);
    return std::to_string(PI*r*r);
}

std::string Formula::GetCircleArea(double radius) 
{
    return std::to_string(PI*radius*radius);
}

std::string Formula::GetCircleCircumference(std::string radius) 
{
    double r=OpString::StringToDouble(radius);
    return std::to_string(2.0*PI*r);
}

std::string Formula::GetCircleCircumference(double radius) 
{
    return std::to_string(2.0*PI*radius);
}
