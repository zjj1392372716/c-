#pragma once
#include <iostream>
#include <string>
using namespace std;
struct PNumber{					//�Һ�����
	string name;				//��������
	string idcard;				//���֤����
	string m_num;			//�Һ�id
	string department;			//���ﲿ��
	string money;				//�Һŷ���
	string isexport;				//�Ƿ�ר������
	struct PNumber * next; 		//ָ�������е���һ���ṹ 
};
class Number
{
public:
	PNumber *n_head;//ͷָ��
	Number();
	void Savetofile();	//��������Ϣ�����ļ���
	void loadFile();//�����ļ�
	void insertNum(string name, string idcard, string num, string department, string money, string isexport,int flag);//������Ĳ���
	PNumber *Gethead(){ return n_head; }//���س���
	int Length();//����ĳ���
	void Outputlist(struct PNumber *head, int flag);//����������
	~Number();
};

