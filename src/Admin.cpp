/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-29 14:30:28
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-03 10:44:09
 */
#include "Admin.hpp"

void Admin::go(char* cmd)
{
    opCmd=new CmdAnaly(cmd);
    if(opCmd->s)
    {
        ChangeModel();
    }
    else
    {
        //std::cout<<"cccccccccccccccccccc"<<std::endl;
        if(currentStatus.statusInt==PRIMARY)
        {
            //std::cout<<opCmd->cmd.c_str()<<std::endl;
            Arithmetic *ari=new Arithmetic(opCmd->cmd.c_str());
            ari->out();
            ari=nullptr;
            delete ari;
            //std::cout<<"sdsdsdsdsd"<<std::endl;
        }
        else if(currentStatus.statusInt==PRIMARY_SAVE)
        {
            Arithmetic *ari=new Arithmetic(opCmd->cmd.c_str());
            ari->outS();
            ari=nullptr;
            delete ari;
        }
        else if(currentStatus.statusInt==DATABASE)
        {
            //std::cout<<currentStatus.statusInt<<std::endl;
            //std::cout<<"sdsdsdsdsd"<<std::endl;
            DataBaseAdmin dAdmin(opCmd->cmd);
        }
        else
        {
            std::cout<<"[Worning]:No such parameter!"<<std::endl;
            exit(1);
        }
        //std::cout<<"sdsdsdsdsd"<<std::endl; 
    }
    //std::cout<<"sdsdsdsdssd"<<std::endl;
    opCmd=nullptr;
    delete opCmd;
}

void Admin::version() 
{
    std::cout<<"\033[1m\033[46m********************************************************************\033[0m\n";  
    std::cout<<"\033[1m\033[31m      __     __       ___   ________   _____   _______       __     \033[0m\n";
    std::cout<<"\033[1m\033[31m     /  |   /  |     /   | |    _   | |_   _| |  _____|     |  |    \033[0m\n";
    std::cout<<"\033[1m\033[31m    / | |  / | |    / |  | |   | |__|   | |   | |        ___|  |___ \033[0m\n";
    std::cout<<"\033[1m\033[34m   / /| | / /| |   / /|  | |   |____    | |   | |       |___    ___|\033[0m\n";
    std::cout<<"\033[1m\033[34m  / / | |/ / | |  / /=|  | |   |    |  _| |_  | |_____      |  |    \033[0m\n";
    std::cout<<"\033[1m\033[34m /_/  |___/  |_| /_/  |_ | |_____|__| |_____| |_______|     |__|    \033[0m\n";
    std::cout<<"\033[1m\033[32m********************************************************************\033[0m\n";
    std::cout<<"Author:Fantety\tVersion:0.3.0\t\nE-mail:fantety@foxmail.com\tweb:https://fantety.top\n";
    std::cout<<"\033[1m\033[46m********************************************************************\033[0m\n";
}
Admin::~Admin()
{
    //delete opCmd;
}
std::string Admin::GetCurrentStatus() 
{
    return currentStatus.statusStr;
}

void Admin::ChangeModel() 
{
    if(opCmd->CheckCmd('p')||opCmd->CheckCmd("/p"))
        {
            //std::cout<<"ppppppppppp"<<std::endl;
            if(opCmd->CheckCmd('s')||opCmd->CheckCmd("/s"))
            {
                //std::cout<<"ssssssssssss"<<std::endl;
                currentStatus={PRIMARY_SAVE,"primary|save"};
            }
            else
            {
                currentStatus={PRIMARY,"primary"};
            }
        }
        else if(opCmd->CheckCmd('d')||opCmd->CheckCmd("/d"))
        {
            currentStatus={DATABASE,"database"};  
            //std::cout<<currentStatus.statusInt<<std::endl;
        }
        else
        {
            std::cout<<"[Worning]:No such parameter!"<<std::endl;
            exit(1);
        }
}
