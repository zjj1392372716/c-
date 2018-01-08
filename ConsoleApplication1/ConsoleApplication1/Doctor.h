#pragma once
#include "medicinal.h"
#include <iostream>
#include <string>
using namespace std;
struct PatientInfo{					//病人信息
	string name;					//病人姓名
	string idcard;					//身份证号码
	string m_num;					//挂号id
	string money;					//挂号费用
	string record;					//病史
	string result;					//诊断情况
	string medicine;				//开的药，目前只开一种药
	struct PatientInfo * next; 		//指向链表中的下一个结构 
};
//继承药材库类
class Doctor:public medicinal
{
public:
	PatientInfo *d_head;//头指针
	Doctor();
	void Savetofile();	//将链表信息存入文件中
	void insertinfo(string name, string idcard, string num, string money, string record, string result, string medicine);//链表结点的插入
	PatientInfo *Gethead(){ return d_head; }
	~Doctor();
	void askInfo(string name, string num, string idcard);//询问病情写入链表
	void Outputlist(struct PatientInfo *head, int flag);//链表结点的输出
	void loadFile();
	string getResult();
	string getmed();
};

