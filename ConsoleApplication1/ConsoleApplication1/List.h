#pragma once
#include <string>
using namespace std;
struct Registers{					//医疗卡注册信息链表
	string name;
	string idcard;
	int age;
	string username;
	string password;
	struct Registers * next; 		//指向链表中的下一个结构 
};
class List							//链表类
{
	
public:
	Registers *r_head;//头指针
	List(){ r_head = NULL; }
	void insertlist(string name, string idcard, int age, string username, string password);//链表结点的插入
	void Deletelist(int aDate);//链表结点的删除
	void Outputlist(struct Registers *head, int flag);//链表结点的输出
	Registers *Gethead(){ return r_head; }
	void Savetofile();//将链表信息读入文件
	void loadFile();	//将文件信息读取到链表中
	~List();
};

