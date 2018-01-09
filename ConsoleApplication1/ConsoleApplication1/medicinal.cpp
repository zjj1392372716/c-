#include "medicinal.h"

#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //ʹ��stringstream��Ҫ�������ͷ�ļ�  
#include <stdlib.h>

medicinal::medicinal(){
	m_head = NULL;
	loadFile();//����ʼ����ʱ��ͼ����ļ�������
}

medicinal::~medicinal()
{
}



int medicinal::checkmedicinal()//����ҩ�ģ��ҵ�����1��û�ҵ�����0
{
	
	struct Medicinals *p = m_head;

	
	if (m_head == NULL)
	{
		cout<<"û�����ݲ���\n";
		return 0;
	}
	cout << "��������Ҫ���ҵ�ҩ����" << endl;
	string str;
	cin >> str;
	while (str!=p->name && p->next != NULL)
	{
		p = p->next;
	}
	if (str ==p->name)
	{
		cout << "���ҳɹ�" << endl;
		cout << "����" << "\t" <<"�۸�"<< endl;
		cout << p->name<<"\t" << p->price<<"\t" << endl;
		return 1;
	}
	else{
		cout << "����ʧ��" << endl;
		return 0;
	}
	
}
void medicinal::Savetofile()	//��������Ϣ�����ļ���
{
	ofstream in;
	in.open("medicinal.txt", ios::trunc); //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�
	struct Medicinals *p = m_head;
	int i = 0;
	string str1;
	//�洢��ʱ��ÿһ�����ݺ���һ���ո�
	while (p != NULL)
	{
		in << p->name << "\t" << p->price << "\t" << "\n";
		p = p->next;
	}

	in.close();//�ر��ļ�
}
void medicinal::insertinfo(string name, string price)//������Ĳ���
{
	struct Medicinals *p = NULL, *pr = m_head;
	p = (Medicinals *)new(Medicinals);


	if (p == NULL)
	{
		cout << ("�����ڴ�ʧ��");
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
void medicinal::Outputlist(struct Medicinals *head, int flag)			//���ҩ�Ŀ�����
{
	struct Medicinals *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++ҩ�Ŀ⣺++++++++++++++++++++++\n";
		cout << "\n";
		cout << "����" << "\t" << "����" << endl;
	}
	cout << p->name << "\t" << p->price << endl;

	Outputlist(p->next, 0);
}
void medicinal::loadFile()	//���ļ���Ϣ��ȡ��������
{
	ifstream inf;
	inf.open("medicinal.txt");
	//ͷָ��ı���p
	struct Medicinals *p = m_head;

	string sline;//ÿһ��
	string out;
	string  name, price;

	//���ж�ȡ
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name >> price;
		insertinfo(name, price);//����������
	}
	inf.close();
}