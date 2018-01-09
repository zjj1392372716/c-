#include "List.h"
#include "Number.h"
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //使用stringstream需要引入这个头文件  
#include <stdlib.h>
using namespace std;
//初始化插入链表
void List::insertlist(string name, string idcard, string age, string username, string password,int flag) 
{
	struct Registers *p = NULL, *pr = r_head;
	p = (Registers*)new(Registers);
	

	if (p == NULL)
	{
		printf("申请内存失败");
		return;
	}
	p->age = age;
	p->idcard = idcard;
	p->name = name;
	p->username = username;
	p->password = password;
	p->next = NULL;
	if (r_head == NULL)
	{
		r_head = p;
	}
	else {
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	if (flag == 1)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++您的注册信息：++++++++++++++++++++++\n";
		cout << "\n";
		cout << "姓名" << "\t" << "年龄" << "\t" << "身份证号码" << "\t\t" << "账户" << "\t\t" << "密码" << endl;
		cout << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t\t" << p->password << endl;
		cout << "\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}
	Savetofile();//存到文件后
	//开始挂号
	

	return;
}
void List::Deletelist(int aDate)//链表结点的删除
{

}
void List::Savetofile()	//将链表信息存入文件中
{
	
	ofstream in;
	in.open("com.txt", ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	struct Registers *p = r_head;
	int i = 0;


	//存储的时候每一个数据后都有一个空格
	while (p != NULL){
		in << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << "\n";
		p = p->next;
	}

	in.close();//关闭文件
}
void List::loadFile()	//将文件信息读取到链表中
{
	ifstream inf;
	inf.open("com.txt");
	//头指针的别名p
	struct Registers *p = r_head;

	string sline;//每一行
	string out;
	string name, age, idcard, username, password;

	//逐行读取
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name >>age>> idcard>> username>>password;
		insertlist(name, age, idcard, username, password,2);//插入链表中
	}
	inf.close();
	
}
void List::Outputlist(struct Registers *head, int flag)//链表信息的打印输出
{

	struct Registers *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "姓名" << "\t" << "年龄" << "\t" << "身份证号码" << "\t\t" << "账户" << "\t" << "密码" << endl;
	}
	cout << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << endl;

	Outputlist(p->next, 0);
}
//析构函数
List::~List()
{

}

string List::checkinfo(string username, string pwd){
	struct Registers *p = r_head;
	if (r_head == NULL)
	{
		
		return "";
	}
	
	
	while ( username != p->username && pwd!=p->password && p->next != NULL)
	{
		p = p->next;
	}
	if (username == p->username && pwd == p->password)
	{
		
		return p->idcard;
	}
	else{
	
		return "";
	}
}
int List::checkreglist(string username,string pwd)//检索注册信息，找到返回1，没找到返回0
{

	struct Registers *p = r_head;


	if (r_head == NULL)
	{
		cout << "很抱歉，查找失败，请确认您的账户跟密码是否正确\n";
		return 0;
	}
	
	while (username != p->username && pwd!=p->password && p->next != NULL)
	{
		p = p->next;
	}
	if (username == p->username && pwd ==p->password)
	{
		cout << "登录成功！！" << endl;
		return 1;
	}
	else{
		cout << "很抱歉，查找失败，请确认您的账户跟密码是否正确" << endl;
		return 0;
	}
	

}