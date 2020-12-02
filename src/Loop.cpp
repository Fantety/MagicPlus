/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-12-02 13:08:32
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-02 16:11:28
 */
#include "Loop.hpp"
#include <string.h>
void MainLoop() 
{
    Admin::version();
    Admin admin;
    std::string currentS("primary");
    while(1)
    {
        char* cmd;
        std::cout<<"\033[1m\033[34mMagic+ \033[0m<"<<currentS<<"> "<<"\033[1m\033[32m>> \033[0m";
        std::cin>>cmd;
        if(!strcmp(cmd,"quit")) break;
        admin.go(cmd);
        currentS=admin.GetCurrentStatus();
    }
    return ;
}
