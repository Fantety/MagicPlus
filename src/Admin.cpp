/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-29 14:30:28
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-02 15:22:13
 */
#include "Admin.hpp"

void Admin::go(char* cmd)
{
    opCmd=new CmdAnaly(cmd);
    if(opCmd->s)
    {
        if(opCmd->CheckCmd('p')||opCmd->CheckCmd("-p"))
        {
            //std::cout<<"ppppppppppp"<<std::endl;
            if(opCmd->CheckCmd('s')||opCmd->CheckCmd("-s"))
            {
                //std::cout<<"ssssssssssss"<<std::endl;
                currentStatus={PRIMARY_SAVE,"primary|save"};
            }
            else
            {
                currentStatus={PRIMARY,"primary"};
            }
        }
        else if(opCmd->CheckCmd('d')||opCmd->CheckCmd("-d"))
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
    else
    {
        //std::cout<<"cccccccccccccccccccc"<<std::endl;
        if(currentStatus.statusInt==PRIMARY)
        {
            //std::cout<<opCmd->cmd.c_str()<<std::endl;
            Arithmetic* ari=new Arithmetic(opCmd->cmd.c_str());
            ari->out();
            delete ari;
        }
        else if(currentStatus.statusInt==PRIMARY_SAVE)
        {
            Arithmetic* ari=new Arithmetic(opCmd->cmd.c_str());
            ari->outS();
            delete ari;
        }
        else if(currentStatus.statusInt==DATABASE)
        {
            //std::cout<<currentStatus.statusInt<<std::endl;
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
    delete opCmd;
}

Admin::~Admin()
{
    //delete opCmd;
}
std::string Admin::GetCurrentStatus() 
{
    return currentStatus.statusStr;
}
