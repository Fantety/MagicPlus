/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-26 20:33:54
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-12-01 17:27:58
 */
#include "DataBase.hpp"

DataBase::DataBase() 
{
    sqlite3_os_init();
    int rc=sqlite3_open_v2(dataPath,&dataBase,SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_NOMUTEX | SQLITE_OPEN_SHAREDCACHE, NULL);
    if(rc==SQLITE_OK)
    {
        //std::cout<<"[Prompt]:Open DataBase Successed!"<<std::endl;
    }
    else
    {
        std::cout<<"[Prompt]:Open DataBase Failed!"<<std::endl;
    }
    const char *sqlSentence = "create table if not exists formula(id integer PRIMARY KEY autoincrement,date TEXT,formula TEXT,result DOUBLE);";
    sqlite3_stmt *stmt = nullptr;
    int rcs = sqlite3_prepare_v2(dataBase, sqlSentence, -1, &stmt, NULL);
    sqlite3_step(stmt);
    sqlSentence="create table if not exists count(id integer PRIMARY KEY autoincrement,date TEXT,formula TEXT,result DOUBLE);";
    stmt=nullptr;
    rcs = sqlite3_prepare_v2(dataBase, sqlSentence, -1, &stmt, NULL);
    sqlite3_step(stmt);

}

DataBase::~DataBase() 
{
    if (dataBase) {
        sqlite3_close_v2(dataBase);
        dataBase = nullptr;
    }
}

int DataBase::InsertData(std::string date,std::string formula,double result) 
{
    sqlite3_stmt *stmt = nullptr;
    std::string resultStr=OpString::DoubleToString(result);
    std::string quote="'";
    std::string sql="INSERT INTO formula(date,formula,result) VALUES("+quote+date+quote+","+quote+formula+quote+","+quote+resultStr+quote+");";
    int rc = sqlite3_prepare_v2(dataBase, sql.c_str(), -1, &stmt, NULL);
    if (rc == SQLITE_OK) 
    {
        //std::cout<< "添加数据语句OK\n";
        sqlite3_step(stmt);
    }
    else 
    {
        std::cout<< "添加数据语句有问题\n";
        return -1;
    }
    sqlite3_finalize(stmt);
    return 0;
}

int DataBase::GetAllData() 
{
    //std::cout<<"sdsdsdsdsdsd"<<std::endl;  
    const char *sqlSentence = "SELECT * FROM formula";    //SQL语句
    sqlite3_stmt *stmt = nullptr;    // stmt语句句柄
    
    std::vector<std::string> rowTemp;
    //std::cout<<"sdsdsdsdsdsd"<<std::endl;
     //进行查询前的准备工作——检查语句合法性
     //-1代表系统会自动计算SQL语句的长度
    int result = sqlite3_prepare_v2(dataBase, sqlSentence, -1, &stmt, NULL);
    //std::cout<<"sdsdsdsdsdsd"<<std::endl;
    if (result == SQLITE_OK) {
        //std::clog <<  "查询语句OK\n";
        // 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            rowTemp.push_back(std::to_string((sqlite3_column_int(stmt, 0))));
            rowTemp.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            //int age = sqlite3_column_int(stmt, 1);
            rowTemp.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
            rowTemp.push_back(OpString::DoubleToString(sqlite3_column_double(stmt, 3)));
            formulaData.push_back(rowTemp);
            rowTemp.clear();
        }
    }
    else {
        std::clog << "查询语句有问题";
        return -1;
    }
     //清理语句句柄，准备执行下一个语句
    sqlite3_finalize(stmt);
    return 0;
}

void DataBase::ShowAllData() 
{
    GetAllData();
    std::cout<<std::setfill(' ')<<std::setw(10)<<std::left<<"id";
    //std::cout.width(29);
    //std::cout.fill(' ');
    std::cout<<std::setfill(' ')<<std::setw(34)<<std::left<<"date";
    //std::cout.width(29);
    //std::cout.fill(' ');
    std::cout<<std::setfill(' ')<<std::setw(20)<<std::left<<"formula";
    //std::cout.width(29);
    //std::cout.fill(' ');
    std::cout<<std::setfill(' ')<<std::setw(15)<<std::left<<"result";
    std::cout<<std::endl;
    for(int i=0;i<formulaData.size();i++){
        std::cout<<std::setfill(' ')<<std::setw(10)<<std::left<<formulaData[i][0];
        std::cout<<std::setfill(' ')<<std::setw(40)<<std::left<<formulaData[i][1];
        std::cout<<std::setfill(' ')<<std::setw(20)<<std::left<<formulaData[i][2];
        std::cout<<std::setfill(' ')<<std::setw(15)<<std::left<<formulaData[i][3];
            //std::cout.width(29);
            //std::cout.fill(' ');
        std::cout<<"\n";
    }
}

double DataBase::GetLastResult() 
{
    const char *sqlSentence = "select * from formula order by id desc limit 1;";
    sqlite3_stmt *stmt = nullptr;
    double result;
    int rc = sqlite3_prepare_v2(dataBase, sqlSentence, -1, &stmt, NULL);
    sqlite3_step(stmt);
    if (rc == SQLITE_OK) {
        result=sqlite3_column_double(stmt,3);
        return result;
    }
    else{
        return 0.0;
    }
}

double DataBase::GetAssignResult(int i)
{
    std::string pos=std::to_string(i);
    std::string sqlSentence = "select * from formula where id="+pos+";";
    sqlite3_stmt *stmt = nullptr;
    double result;
    int rc = sqlite3_prepare_v2(dataBase, sqlSentence.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    if (rc == SQLITE_OK) {
        result=sqlite3_column_double(stmt,3);
        return result;
    }
    else{
        return 0.0;
    }
}
std::string DataBase::gettime() 
{
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%Y年%m月%d日%H时%M分%S秒");
    std::string str_time = ss.str();
    return str_time;
}
