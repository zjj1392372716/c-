#pragma once
#include <iostream>
#include <string>
using namespace std;
struct PNumber{					//挂号链表
	string name;				//病人姓名
	string idcard;				//身份证号码
	string m_num;			//挂号id
	string department;			//就诊部门
	string money;				//挂号费用
	string isexport;				//是否专家门诊
	struct PNumber * next; 		//指向链表中的下一个结构 
};
class Number
{
public:
	PNumber *n_head;//头指针
	Number();
	void Savetofile();	//将链表信息存入文件中
	void loadFile();//加载文件
	void insertNum(string name, string idcard, string num, string department, string money, string isexport,int flag);//链表结点的插入
	PNumber *Gethead(){ return n_head; }//返回长度
	int Length();//链表的长度
	void Outputlist(struct PNumber *head, int flag);//链表结点的输出
	~Number();
};

