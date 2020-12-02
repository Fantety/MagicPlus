/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-28 21:54:00
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-02 15:22:41
 */
#include "CmdAnaly.hpp"


CmdAnaly::CmdAnaly(char* Cmd) 
{
    GetCmdModifier(Cmd);
}

void CmdAnaly::GetCmdModifier(char* Cmd) 
{
    if(*Cmd=='-')
    {
        //std::cout<<Cmd<<std::endl;
        cmdModifier=Cmd;
        s=true;
    }
    else
    {
        //std::cout<<Cmd<<std::endl;
        cmd=Cmd;
        s=false;
    }
    
}

bool CmdAnaly::CheckCmd(std::string cmd) 
{
    if(cmdModifier.find(cmd)!=std::string::npos)
    {
        //std::cout<<cmdModifier.find(cmd)<<std::endl;
        return true;
    }
    else
    {
        /* code */     
        return false;
    }

} 

bool CmdAnaly::CheckCmd(char cmd) 
{
    if(cmdModifier.find(cmd)!=std::string::npos)
    {
        //std::cout<<cmdModifier.find(cmd)<<std::endl;
        return true;
    }
    else
    {
        /* code */     
        return false;
    }
}
