/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-29 14:30:28
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-29 15:09:45
 */
#include "Admin.hpp"

Admin::Admin(char** cmd)
{
    opCmd=new CmdAnaly(cmd);
    if(opCmd->CheckCmd('p')||opCmd->CheckCmd("-p"))
    {
        if(opCmd->CheckCmd('s')||opCmd->CheckCmd("-s"))
        {
            Arithmetic* ari=new Arithmetic(opCmd->cmd.c_str());
            ari->outS();
            delete ari;
        }
        else
        {
            Arithmetic* ari=new Arithmetic(opCmd->cmd.c_str());
            ari->out();
            delete ari;
        }
    }
    else if(opCmd->CheckCmd('d')||opCmd->CheckCmd("-d"))
    {
        if(opCmd->cmd=="all")
        {
            DataBase* db=new DataBase;
            db->ShowAllData();
            delete db;
        }
        else
        {
            std::cout<<"[Worning]:No such commend!"<<std::endl;
        }    
    }
    else
    {
        std::cout<<"[Worning]:No such parameter!"<<std::endl;
		exit(1);
    }
    
}

Admin::~Admin()
{
    delete opCmd;
}