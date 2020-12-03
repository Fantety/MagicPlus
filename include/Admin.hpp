/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-29 14:30:36
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-03 10:43:27
 */
#ifndef ADMIN_HPP 
#define ADMIN_HPP


#include "Arithmetic.hpp"

typedef struct statusS
{
    int statusInt=0;
    std::string statusStr="primary";

}statusS;
class Admin
{
    private:
    /* data */
    enum status{PRIMARY=0,PRIMARY_SAVE,DATABASE};
    CmdAnaly* opCmd=nullptr;
    statusS currentStatus;
    
    private:
    void ChangeModel();

    public:
    std::string GetCurrentStatus();
    //Admin();
    void go(char* cmd);

    static void version();
    ~Admin();
};



#endif // ADMIN_HPP 
