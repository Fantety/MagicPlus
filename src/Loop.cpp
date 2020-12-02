/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-12-02 13:08:32
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-12-02 15:17:57
 */
#include "Loop.hpp"
#include <string.h>
void MainLoop() 
{
    Admin admin;
    std::string currentS("primary");
    while(1)
    {
        char* cmd;
        std::cout<<"Magic <"<<currentS<<"> "<<"+>> ";
        std::cin>>cmd;
        if(!strcmp(cmd,"quit")) break;
        admin.go(cmd);
        currentS=admin.GetCurrentStatus();
    }
    return ;
}
