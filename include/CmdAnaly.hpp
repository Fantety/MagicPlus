/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-28 21:53:44
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-28 22:49:39
 */
#ifndef CMDANALY_HPP 
#define CMDANALY_HPP

#include <string>
#include <vector>
#include <iostream>
class CmdAnaly
{
    private:
    /* data */
    std::vector<std::string> cmdModifier;

    private:
    void GetCmdModifier(char** Cmd);

    public:
    std::string cmd;
    bool CheckCmd(std::string cmd);
    bool CheckCmd(char cmd);
    CmdAnaly(char** Cmd);
};


#endif // CMDANALY_HPP 
