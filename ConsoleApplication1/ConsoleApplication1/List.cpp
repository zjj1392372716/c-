#include "List.h"
#include "Number.h"
#include <string>
#include<iostream>
#include <fstream>
using namespace std;
//初始化插入链表
void List::insertlist(string name, string idcard, int age, string username, string password) 
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
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++您的注册信息：++++++++++++++++++++++\n";
	cout << "\n";
	cout << "姓名" << "\t" << "年龄" << "\t" << "身份证号码" << "\t\t" << "账户" << "\t" << "密码" << endl;
	cout << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << endl;
	cout << "\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
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
		in << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << "\t";
		p = p->next;
	}

	in.close();//关闭文件
}
void List::loadFile()	//将文件信息读取到链表中
{
	ifstream ifs("com.txt");
	string str;
	int count = 0;

	while (ifs >> str)
	{
		cout << str << endl;
		count++;
	}
	ifs.close();
	
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
