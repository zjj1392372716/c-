#include "List.h"
#include "Number.h"
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //ʹ��stringstream��Ҫ�������ͷ�ļ�  
#include <stdlib.h>
using namespace std;
//��ʼ����������
void List::insertlist(string name, string idcard, string age, string username, string password,int flag) 
{
	struct Registers *p = NULL, *pr = r_head;
	p = (Registers*)new(Registers);
	

	if (p == NULL)
	{
		printf("�����ڴ�ʧ��");
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
		cout << "+++++++++++++++++++����ע����Ϣ��++++++++++++++++++++++\n";
		cout << "\n";
		cout << "����" << "\t" << "����" << "\t" << "���֤����" << "\t\t" << "�˻�" << "\t\t" << "����" << endl;
		cout << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t\t" << p->password << endl;
		cout << "\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}
	Savetofile();//�浽�ļ���
	//��ʼ�Һ�
	

	return;
}
void List::Deletelist(int aDate)//�������ɾ��
{

}
void List::Savetofile()	//��������Ϣ�����ļ���
{
	
	ofstream in;
	in.open("com.txt", ios::trunc); //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�
	struct Registers *p = r_head;
	int i = 0;


	//�洢��ʱ��ÿһ�����ݺ���һ���ո�
	while (p != NULL){
		in << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << "\n";
		p = p->next;
	}

	in.close();//�ر��ļ�
}
void List::loadFile()	//���ļ���Ϣ��ȡ��������
{
	ifstream inf;
	inf.open("com.txt");
	//ͷָ��ı���p
	struct Registers *p = r_head;

	string sline;//ÿһ��
	string out;
	string name, age, idcard, username, password;

	//���ж�ȡ
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name >>age>> idcard>> username>>password;
		insertlist(name, age, idcard, username, password,2);//����������
	}
	inf.close();
	
}
void List::Outputlist(struct Registers *head, int flag)//������Ϣ�Ĵ�ӡ���
{

	struct Registers *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "����" << "\t" << "����" << "\t" << "���֤����" << "\t\t" << "�˻�" << "\t" << "����" << endl;
	}
	cout << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << endl;

	Outputlist(p->next, 0);
}
//��������
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
int List::checkreglist(string username,string pwd)//����ע����Ϣ���ҵ�����1��û�ҵ�����0
{

	struct Registers *p = r_head;


	if (r_head == NULL)
	{
		cout << "�ܱ�Ǹ������ʧ�ܣ���ȷ�������˻��������Ƿ���ȷ\n";
		return 0;
	}
	
	while (username != p->username && pwd!=p->password && p->next != NULL)
	{
		p = p->next;
	}
	if (username == p->username && pwd ==p->password)
	{
		cout << "��¼�ɹ�����" << endl;
		return 1;
	}
	else{
		cout << "�ܱ�Ǹ������ʧ�ܣ���ȷ�������˻��������Ƿ���ȷ" << endl;
		return 0;
	}
	

}