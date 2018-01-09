#include "medicinal.h"

#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //使用stringstream需要引入这个头文件  
#include <stdlib.h>

medicinal::medicinal(){
	m_head = NULL;
	loadFile();//当初始化的时候就加载文件到链表
}

medicinal::~medicinal()
{
}



int medicinal::checkmedicinal()//检索药材，找到返回1，没找到返回0
{
	
	struct Medicinals *p = m_head;

	
	if (m_head == NULL)
	{
		cout<<"没有数据查找\n";
		return 0;
	}
	cout << "请输入您要查找的药材名" << endl;
	string str;
	cin >> str;
	while (str!=p->name && p->next != NULL)
	{
		p = p->next;
	}
	if (str ==p->name)
	{
		cout << "查找成功" << endl;
		cout << "名称" << "\t" <<"价格"<< endl;
		cout << p->name<<"\t" << p->price<<"\t" << endl;
		return 1;
	}
	else{
		cout << "查找失败" << endl;
		return 0;
	}
	
}
void medicinal::Savetofile()	//将链表信息存入文件中
{
	ofstream in;
	in.open("medicinal.txt", ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	struct Medicinals *p = m_head;
	int i = 0;
	string str1;
	//存储的时候每一个数据后都有一个空格
	while (p != NULL)
	{
		in << p->name << "\t" << p->price << "\t" << "\n";
		p = p->next;
	}

	in.close();//关闭文件
}
void medicinal::insertinfo(string name, string price)//链表结点的插入
{
	struct Medicinals *p = NULL, *pr = m_head;
	p = (Medicinals *)new(Medicinals);


	if (p == NULL)
	{
		cout << ("申请内存失败");
		return;
	}
	p->name = name;
	p->price = price;
	p->next = NULL;
	if (m_head == NULL)
	{
		m_head = p;
	}
	else {
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}

	return;
}
void medicinal::Outputlist(struct Medicinals *head, int flag)			//输出药材库内容
{
	struct Medicinals *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++药材库：++++++++++++++++++++++\n";
		cout << "\n";
		cout << "名称" << "\t" << "单价" << endl;
	}
	cout << p->name << "\t" << p->price << endl;

	Outputlist(p->next, 0);
}
void medicinal::loadFile()	//将文件信息读取到链表中
{
	ifstream inf;
	inf.open("medicinal.txt");
	//头指针的别名p
	struct Medicinals *p = m_head;

	string sline;//每一行
	string out;
	string  name, price;

	//逐行读取
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name >> price;
		insertinfo(name, price);//插入链表中
	}
	inf.close();
}