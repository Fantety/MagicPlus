/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-28 21:54:00
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-29 14:53:13
 */
#include "CmdAnaly.hpp"


CmdAnaly::CmdAnaly(char** Cmd) 
{
    GetCmdModifier(Cmd);
}

void CmdAnaly::GetCmdModifier(char** Cmd) 
{
    int counter=0;
    //while(*Cmd)
    //{
    while(*Cmd)
    {
        if(**Cmd=='-')
        {
            cmdModifier.push_back(*Cmd);
            //std::cout<<cmdModifier[0]<<std::endl;
        }
        else
        {
            /* code */
            if(counter>=1)
            {
                cmd=*Cmd;
                //std::cout<<cmd<<std::endl;
            }
            counter++;
        }
        Cmd++;
        //std::cout<<"sdsdsdsdsdsdsds"<<std::endl;
    }
    //std::cout<<"sdsdsdsdsdsdsds"<<std::endl;
    //(*Cmd)++;
    //}
    //std::cout<<cmdModifier[1]<<std::endl;
}

bool CmdAnaly::CheckCmd(std::string cmd) 
{
    for(int i=0;i<cmdModifier.size();i++)
    {
        if(cmd==cmdModifier[i])
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}

bool CmdAnaly::CheckCmd(char cmd) 
{
    for(int i=0;i<cmdModifier.size();i++)
    {
        for(int j=0;j<cmdModifier[i].size();j++)
        {
            if(cmd==cmdModifier[i][j])
            {
                return true;
            }
            else
            {
                continue;
            }
        }
    }
    return false;
}
