/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-26 20:52:23
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-05 22:17:00
 */
#include "OpString.hpp"

double OpString::StringToDouble(std::string inputStr) 
{
    return atof(inputStr.c_str());
} 

std::string OpString::DoubleToString(double inputDouble) 
{
    return std::to_string(inputDouble);
}

std::string OpString::StringExtract(std::string inputStr,char preStr) 
{
    std::string tempStr;
    for(int i=0;i<inputStr.size();i++)
    {
        if(inputStr[i]==preStr)
        {
            tempStr.push_back(inputStr[i]);
            i++;
            while(1)
            {
                if((int(inputStr[i])>=48&&int(inputStr[i])<=57)||int(inputStr[i])==46)
                {
                    tempStr.push_back(inputStr[i]);
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            continue;
        }
    }
    std::vector<std::string> variantT=OpString::StringSplit(tempStr,preStr);
    int tempPos=0;
    double vaule=0.0;
    for(int i=0;i<variantT.size();i++)
    {
        tempPos=OpString::StringToDouble(variantT[i]);
        vaule=OpString::StringToDouble(variantT[i]);
        //std::cout<<tempPos<<std::endl;
        variantT[i].insert(0,1,preStr);
        //std::cout<<variantT[i]<<std::endl;
        var.push_back({tempPos,variantT[i],inputStr.find(variantT[i]),variantT[i].size(),vaule});
    }
    return tempStr;
}

std::vector<std::string> OpString::StringSplit(std::string inputStr ,char splitMark) 
{
    if(inputStr[0]==splitMark)
    {
        inputStr.erase(0,1);
    }
    std::vector<std::string> outputStr;
    std::string outputStrTemp;
    if(inputStr.empty())
    {
        std::cout<<"[Warning]:There is on String to Split!"<<std::endl;
    }
    for(int i=0;i<inputStr.size();i++)
    {
        if(inputStr.at(i)==splitMark)
        {
            outputStr.push_back(outputStrTemp);
            outputStrTemp.clear();
            continue;
        }
        else
        {
            outputStrTemp.push_back(inputStr.at(i));
        }
    }
    outputStr.push_back(outputStrTemp);
    return outputStr;
}
