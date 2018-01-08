#include "Number.h"
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //使用stringstream需要引入这个头文件  
#include <stdlib.h>
using namespace std;

void Number::insertNum(string name, string idcard, string num, string department, string money, string isexport,int flag)
{
	
	struct PNumber *p = NULL, *pr = n_head;
	p = (PNumber*)new(PNumber);


	if (p == NULL)
	{
		printf("申请内存失败");
		return;
	}
	p->name = name;
	p->idcard = idcard;

	p->m_num = num;
	p->department = department;
	p->isexport = isexport;
	p->money = money;
	p->next = NULL;
	if (n_head == NULL)
	{
		n_head = p;
	}
	else {
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	if (flag == 2){
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++您的挂号信息：++++++++++++++++++++++\n";
		cout << "\n";
		cout << "姓名" << "\t" << "所挂号码" << "\t" << "身份证号码" << "\t\t" << "部门" << "\t" << "是否专家门诊" << "挂号费用" << endl;
		cout << p->name << "\t" << p->m_num << "\t\t" << p->idcard << "\t" << p->department << "\t" << p->isexport << "\t" << p->money << endl;
		cout << "\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}
	
	Savetofile();
	return;
}
int Number::Length()
{
	int cnt = 0;
	PNumber *p = n_head;
	while (p != NULL){
		p = p->next;
		++cnt;
	}
	return cnt;
}


void Number::Outputlist(struct PNumber *head, int flag)//链表结点的输出
{
	struct PNumber *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++您的挂号信息：++++++++++++++++++++++\n";
		cout << "\n";
		cout << "姓名" << "\t" << "所挂号码" << "\t" << "身份证号码" << "\t\t" << "部门" << "\t" << "是否专家门诊" << "挂号费用" << endl;
	}
	cout << p->name << "\t" << p->m_num << "\t\t" << p->idcard << "\t" << p->department << "\t" << p->isexport << "\t" << p->money << endl;

	Outputlist(p->next, 0);
}

void Number::Savetofile()	//将链表信息存入文件中
{

	ofstream in;
	in.open("num.txt", ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	struct PNumber *p = n_head;
	int i = 0;
	string str1;
	//存储的时候每一个数据后都有一个空格
	while (p != NULL)
	{
		
		in << p->name << "\t" << p->m_num << "\t" << p->idcard << "\t" << p->department << "\t" << p->isexport<<"\t"<< p->money <<"\n";
		p = p->next;
	}

	in.close();//关闭文件
}
Number::Number(){
	n_head = NULL;
	loadFile();//当初始化的时候就加载文件到链表
	
}
void Number::loadFile()	//将文件信息读取到链表中
{
	

	ifstream inf;
	inf.open("num.txt");
	//头指针的别名p
	struct PNumber *p = n_head;
	
	string sline;//每一行
	string out;
	string name, num, idcard, department, isexport, money;

	//逐行读取
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name >> num >> idcard >> department >> isexport >> money;
		insertNum(name, idcard, num, department, money, isexport,1);//插入链表中
		
		
	}
	//Outputlist(n_head, 1);
	inf.close();
}
Number::~Number()
{

}
