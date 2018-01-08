#include "Number.h"
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //ʹ��stringstream��Ҫ�������ͷ�ļ�  
#include <stdlib.h>
using namespace std;

void Number::insertNum(string name, string idcard, string num, string department, string money, string isexport,int flag)
{
	
	struct PNumber *p = NULL, *pr = n_head;
	p = (PNumber*)new(PNumber);


	if (p == NULL)
	{
		printf("�����ڴ�ʧ��");
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
		cout << "+++++++++++++++++++���ĹҺ���Ϣ��++++++++++++++++++++++\n";
		cout << "\n";
		cout << "����" << "\t" << "���Һ���" << "\t" << "���֤����" << "\t\t" << "����" << "\t" << "�Ƿ�ר������" << "�Һŷ���" << endl;
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


void Number::Outputlist(struct PNumber *head, int flag)//����������
{
	struct PNumber *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++���ĹҺ���Ϣ��++++++++++++++++++++++\n";
		cout << "\n";
		cout << "����" << "\t" << "���Һ���" << "\t" << "���֤����" << "\t\t" << "����" << "\t" << "�Ƿ�ר������" << "�Һŷ���" << endl;
	}
	cout << p->name << "\t" << p->m_num << "\t\t" << p->idcard << "\t" << p->department << "\t" << p->isexport << "\t" << p->money << endl;

	Outputlist(p->next, 0);
}

void Number::Savetofile()	//��������Ϣ�����ļ���
{

	ofstream in;
	in.open("num.txt", ios::trunc); //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�
	struct PNumber *p = n_head;
	int i = 0;
	string str1;
	//�洢��ʱ��ÿһ�����ݺ���һ���ո�
	while (p != NULL)
	{
		
		in << p->name << "\t" << p->m_num << "\t" << p->idcard << "\t" << p->department << "\t" << p->isexport<<"\t"<< p->money <<"\n";
		p = p->next;
	}

	in.close();//�ر��ļ�
}
Number::Number(){
	n_head = NULL;
	loadFile();//����ʼ����ʱ��ͼ����ļ�������
	
}
void Number::loadFile()	//���ļ���Ϣ��ȡ��������
{
	

	ifstream inf;
	inf.open("num.txt");
	//ͷָ��ı���p
	struct PNumber *p = n_head;
	
	string sline;//ÿһ��
	string out;
	string name, num, idcard, department, isexport, money;

	//���ж�ȡ
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name >> num >> idcard >> department >> isexport >> money;
		insertNum(name, idcard, num, department, money, isexport,1);//����������
		
		
	}
	//Outputlist(n_head, 1);
	inf.close();
}
Number::~Number()
{

}
