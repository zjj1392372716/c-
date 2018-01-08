#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Medicinals{					//病人信息
	string name;					//病人姓名
	string price;					//身份证号码
	struct Medicinals * next; 		//指向链表中的下一个结构 
};
class medicinal
{

public:
	Medicinals *m_head;							//头指针
	medicinal();
	int checkmedicinal();						//检索药材，找到返回1，没找到返回0
	void Savetofile();							//将链表信息存入文件中
	void insertinfo(string name, string price);	//链表结点的插入
	Medicinals *Gethead(){ return m_head; }
	void loadFile();					//将文件信息读取到链表中
	void medicinal::Outputlist(struct Medicinals *head, int flag);
	~medicinal();
};

