/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-29 14:30:36
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-29 14:50:32
 */
#ifndef ADMIN_HPP 
#define ADMIN_HPP
#include "Arithmetic.hpp"

class Admin
{
private:
    /* data */
    CmdAnaly* opCmd;
public:
    Admin(char** cmd);
    ~Admin();
};



#endif // ADMIN_HPP 
