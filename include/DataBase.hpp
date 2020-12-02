/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-26 20:34:09
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-02 15:23:23
 */
#ifndef DATABASE_HPP 
#define DATABASE_HPP

#include <vector>
#include <string>
#include <iostream>
#include "sqlite3.h"
#include "OpString.hpp"

class DataBase
{
    private:
    std::vector<std::vector<std::string>> formulaData;
    const char* dataPath="../database/database.db";
    sqlite3 *dataBase=nullptr;

    public:
    DataBase();
    ~DataBase();
    int InsertData(std::string date,std::string formula,double result);
    int GetAllData();
    void ShowAllData();
    double GetLastResult();
    double GetAssignResult(int i);
    std::string gettime();

};

#endif // DATABASE_HPP 



