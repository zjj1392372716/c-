#include "List.h"
#include "Number.h"
#include <string>
#include<iostream>
#include <fstream>
using namespace std;
//��ʼ����������
void List::insertlist(string name, string idcard, int age, string username, string password) 
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
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++����ע����Ϣ��++++++++++++++++++++++\n";
	cout << "\n";
	cout << "����" << "\t" << "����" << "\t" << "���֤����" << "\t\t" << "�˻�" << "\t" << "����" << endl;
	cout << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << endl;
	cout << "\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
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
		in << p->name << "\t" << p->age << "\t" << p->idcard << "\t" << p->username << "\t" << p->password << "\t";
		p = p->next;
	}

	in.close();//�ر��ļ�
}
void List::loadFile()	//���ļ���Ϣ��ȡ��������
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
