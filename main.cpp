/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-26 13:19:20
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-30 12:27:26
 */
#include <iostream>
#include "DataBase.hpp"
#include "Admin.hpp"
#include "OpString.hpp"
#include "Arithmetic.hpp"

int main(int argc,char** argv)
{
    //OpString op;
    //op.StringExtract("10+i-23+i12");
    Admin* admin=new Admin(argv);
    delete admin;
    //std::cout<<OpString::StringExtract("i34+i1xi100/i2")<<std::endl;
    return 0;
}