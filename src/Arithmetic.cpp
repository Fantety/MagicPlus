/*
 * @Descripttion: 
 * @version: 
 * @Author: Fantety
 * @Date: 2020-11-27 23:18:13 
 * @LastEditors: Fantety
 * @LastEditTime: 2020-12-05 22:24:48
 */
#include "Arithmetic.hpp"
using namespace std;
double Arithmetic::postfixExpression(const string &str)
{
    string s = ".0123456789+-*/";
	string empty = " ";
	string numbers = ".0123456789";
	string c = "+-*/";

	stack<double> mystack;    //栈空间
	double firstnum;
	double secondnum;
	double sum;

	for(unsigned int i=0; i<str.size(); )
	{
		string::size_type start = str.find_first_of(s,i);     //查找第一个数字或算术符号
		string::size_type end = str.find_first_of(empty,i);   //查找第一个空格	
        string tempstr = str.substr(start, end-start); 
		//判断元素
		if(tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/")
		{
			secondnum = mystack.top();    
			mystack.pop();
			firstnum = mystack.top();
			mystack.pop();
			if(tempstr == "+")
			{
				sum = firstnum + secondnum;
				mystack.push(sum);
			}
			if(tempstr == "-")
			{
				sum = firstnum - secondnum;
				mystack.push(sum);
			}
			if(tempstr == "*")
			{
				sum = firstnum * secondnum;
				mystack.push(sum);
			}
			if(tempstr == "/")
			{
				sum = firstnum / secondnum;
				mystack.push(sum);
			}
		}
		else
		{
			double num = stod(tempstr);
			mystack.push(num);
		}

		//控制迭代
		i = end + 1;
	}
	return mystack.top();
}

int Arithmetic::priority(const string str)  
{
	const char *op = str.c_str();
    switch(*op)  
    {
    case ')':
        return 0;  
    case '+':  
    case '-':  
        return 1;  
    case '*':  
    case '/':  
        return 2; 
	case '(':
		return 3;
    default :  
        return -1;  
    }  
}  

string Arithmetic::InfixToPostfi(const string &str)
{
	string operatorstr = "*-/+()";      //用于string搜索
	string numbers = "0123456789.";

	
	vector<string> Inputvec;   //存储切片结果
	for(unsigned int i=0; i<str.size(); )
	{
		string::size_type operatorindex = str.find_first_of(operatorstr,i);     //搜索str中从i开始的第一个操作符
		if(operatorindex != string::npos)
		{
			//如果从i开始搜索到了操作符
			if(operatorindex == i)
			{
				string tempstr = str.substr(operatorindex,1);
				Inputvec.push_back(tempstr);
				i = i+1;
			}
			else
			{
				Inputvec.push_back(str.substr(i,operatorindex-i));
				Inputvec.push_back(str.substr(operatorindex,1));
				i = operatorindex+1;
			}
		}
		else
		{
			
			Inputvec.push_back(str.substr(i,str.size()-i));
			i = str.size();
		}
	}

	//遍历切片结果vector中每个元素
	stack<string> operatorstack;     //创建空栈，用来存储操作符
	vector<string> PostfiOutvec;     //存储中缀输出
	for(int i=0; i<Inputvec.size(); i++)
	{
		//如果当前元素是操作符
		if(Inputvec[i].find_first_of(operatorstr) != string::npos)
		{
			if(operatorstack.empty())     
			{
				operatorstack.push(Inputvec[i]);      //如果操作符栈空，则直接入栈
			}
			else
			{
				if(Inputvec[i] == ")")     //如果当前操作符是右括号
				{
					while(operatorstack.top() != "(")
					{
						PostfiOutvec.push_back(operatorstack.top());     //将栈顶操作符输出
						operatorstack.pop();    //删除栈顶元素
					}
					operatorstack.pop();    //删除栈顶元素
				}
				else
				{
					int curpri = priority(Inputvec[i]);     //获取操作符的优先级

					
					while(!operatorstack.empty())
					{
						string top = operatorstack.top();     //返回栈顶元素
						int toppor = priority(top);     //栈顶元素优先级

						if((curpri <= toppor) && top!="(")       //左括号优先级最大，但是它只有遇到右括号才输出
						{
							PostfiOutvec.push_back(top);
							operatorstack.pop();    //删除栈顶元素
						}
						else
							break;
					}
					operatorstack.push(Inputvec[i]);
				}
			}
		}
		//如果当前元素是操作数，直接输出
		else
		{
			PostfiOutvec.push_back(Inputvec[i]);
		}
	}
	while(!operatorstack.empty())
	{
		PostfiOutvec.push_back(operatorstack.top());      //输出操作符栈中的其他操作符
		operatorstack.pop();
	}

	//在输出中插入空格
	vector<string>::const_iterator itr=PostfiOutvec.begin()+1;
	while(itr!=PostfiOutvec.end())
	{
		itr = PostfiOutvec.insert(itr," ");      
		itr+=2;
	}
	
	PostfiOutvec.push_back(" ");     //添加最后一个空格

	
	string result;
	for(int i=0; i<PostfiOutvec.size(); i++)
	{
		result.append(PostfiOutvec[i]);
	}

	return result;
}

void Arithmetic::out() 
{
	if(str.empty()) {std::cout<<"[Error]:Have something worry!"<<std::endl;exit(-1);}
	preDeal();
	//std::cout<<"sdsdsdsdsdsd"<<std::endl;
	try{
		result=postfixExpression(InfixToPostfi(this->str));
	}
	catch(...){
		std::cout<<"[Error]:Your formula is not right!"<<std::endl;
		return ;
	}
	std::cout<<"[Result]:"<<result<<std::endl;
}

void Arithmetic::outS() 
{
	if(str.empty()) std::cout<<"[Error]:Have something worry!";
	preDeal();
	try{
		result=postfixExpression(InfixToPostfi(this->str));
	}
	catch(...){
		std::cout<<"[Error]:Your formula is not right!"<<std::endl;
		return ;
	}
	std::cout<<"[Result]:"<<result<<std::endl;
	WriteDatabase();
}

void Arithmetic::preDeal() 
{
	if(str.at(0)=='-')
	{
		str.insert(0,"0");
	}
	//std::cout<<str<<std::endl;
	if(str.find('i')!=std::string::npos)
	{
		//std::cout<<"sdsdsdsds"<<std::endl;
		OpString opStr;
		opStr.StringExtract(str,'i');
		for(int i=0;i<opStr.var.size();i++)
		{
			std::string tempS;
			if(opStr.var[i].dataPos==0)
			{
				tempS=to_string(db->GetLastResult());
			}
			else
			{
				tempS=to_string(db->GetAssignResult(opStr.var[i].dataPos));
			}
			//std::cout<<opStr.var[i].length<<std::endl;
			str.replace(str.find(opStr.var[i].str),opStr.var[i].length,tempS);
		}
	}
	if(str.find('s')!=std::string::npos)
	{
		OpString opStr;
		Formula f;
		opStr.StringExtract(str,'s');
		for(int i=0;i<opStr.var.size();i++)
		{
			std::string tempS;
			tempS=f.GetCircleArea(opStr.var[i].vaule);
			//std::cout<<opStr.var[i].length<<std::endl;
			str.replace(str.find(opStr.var[i].str),opStr.var[i].length,tempS);
		}
	}
	if(str.find('c')!=std::string::npos)
	{
		OpString opStr;
		Formula f;
		opStr.StringExtract(str,'c');
		for(int i=0;i<opStr.var.size();i++)
		{
			std::string tempS;
			tempS=f.GetCircleCircumference(opStr.var[i].vaule);
			//std::cout<<opStr.var[i].length<<std::endl;
			str.replace(str.find(opStr.var[i].str),opStr.var[i].length,tempS);
		}
	}
	//std::cout<<db->GetLastResult()<<std::endl;

}
void Arithmetic::WriteDatabase() 
{
	db->InsertData(db->gettime(),str,result);
}
Arithmetic::Arithmetic(const char* cmd)
{
	db=new DataBase;
	this->str=cmd;
}

Arithmetic::~Arithmetic() 
{
	delete cmdAnaly;
	delete db;
}



