#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Medicinals{					//������Ϣ
	string name;					//��������
	string price;					//���֤����
	struct Medicinals * next; 		//ָ�������е���һ���ṹ 
};
class medicinal
{

public:
	Medicinals *m_head;							//ͷָ��
	medicinal();
	int checkmedicinal();						//����ҩ�ģ��ҵ�����1��û�ҵ�����0
	void Savetofile();							//��������Ϣ�����ļ���
	void insertinfo(string name, string price);	//������Ĳ���
	Medicinals *Gethead(){ return m_head; }
	void loadFile();					//���ļ���Ϣ��ȡ��������
	void medicinal::Outputlist(struct Medicinals *head, int flag);
	~medicinal();
};

