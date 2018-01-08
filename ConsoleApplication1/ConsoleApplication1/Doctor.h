#pragma once
#include "medicinal.h"
#include <iostream>
#include <string>
using namespace std;
struct PatientInfo{					//������Ϣ
	string name;					//��������
	string idcard;					//���֤����
	string m_num;					//�Һ�id
	string money;					//�Һŷ���
	string record;					//��ʷ
	string result;					//������
	string medicine;				//����ҩ��Ŀǰֻ��һ��ҩ
	struct PatientInfo * next; 		//ָ�������е���һ���ṹ 
};
//�̳�ҩ�Ŀ���
class Doctor:public medicinal
{
public:
	PatientInfo *d_head;//ͷָ��
	Doctor();
	void Savetofile();	//��������Ϣ�����ļ���
	void insertinfo(string name, string idcard, string num, string money, string record, string result, string medicine);//������Ĳ���
	PatientInfo *Gethead(){ return d_head; }
	~Doctor();
	void askInfo(string name, string num, string idcard);//ѯ�ʲ���д������
	void Outputlist(struct PatientInfo *head, int flag);//����������
	void loadFile();
	string getResult();
	string getmed();
};

