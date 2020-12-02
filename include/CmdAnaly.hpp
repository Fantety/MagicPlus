/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-28 21:53:44
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-02 15:23:16
 */
#ifndef CMDANALY_HPP 
#define CMDANALY_HPP

#include <string>
#include <vector>
#include <iostream>

#define MODE true
#define CALCULATE false
class CmdAnaly
{
    private:
    /* data */
    std::string cmdModifier;


    private:
    void GetCmdModifier(char* Cmd);

    public:
    bool s;
    std::string cmd;
    bool CheckCmd(std::string cmd);
    bool CheckCmd(char cmd);
    CmdAnaly(char* Cmd);
};


#endif // CMDANALY_HPP 
