#include "Doctor.h"
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //ʹ��stringstream��Ҫ�������ͷ�ļ�  
#include <stdlib.h>
using namespace std;

Doctor::Doctor(){
	d_head = NULL;
	loadFile();//����ʼ����ʱ��ͼ����ļ�������

}
void Doctor::Outputlist(struct PatientInfo *head, int flag)//����������
{
	struct PatientInfo *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++������Ϣ��++++++++++++++++++++++\n";
		cout << "\n";
		cout << "����" << "\t" << "���֤����" << "\t" << "�Һ�" << "\t\t" << "����" << "\t" << "�����Լ���ʷ" << "��Ͻ��" <<"\t"<<"ҩ��"<< endl;
	}
	cout << p->name << "\t" << p->idcard << "\t\t" << p->m_num << "\t" << p->money<< "\t" << p->record << "\t" << p->result << p->medicine<<"\t"<<endl;

	Outputlist(p->next, 0);
}
void Doctor::insertinfo(string name, string idcard, string num, string money, string record, string result, string medicine)//������Ĳ���
{
	struct PatientInfo *p = NULL, *pr = d_head;
	p = (PatientInfo *)new(PatientInfo);


	if (p == NULL)
	{
		cout<<("�����ڴ�ʧ��");
		return;
	}
	p->name = name;
	p->idcard = idcard;

	p->m_num = num;
	p->money = money;
	p->record = record;
	p->result = result;

	p->medicine = medicine;

	p->next = NULL;
	if (d_head == NULL)
	{
		d_head = p;
	}
	else {
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	/*if (flag == 2){
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++���ĹҺ���Ϣ��++++++++++++++++++++++\n";
		cout << "\n";
		cout << "����" << "\t" << "���Һ���" << "\t" << "���֤����" << "\t\t" << "����" << "\t" << "�Ƿ�ר������" << "�Һŷ���" << endl;
		cout << p->name << "\t" << p->m_num << "\t\t" << p->idcard << "\t" << p->department << "\t" << p->isexport << "\t" << p->money << endl;
		cout << "\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}*/

	//Savetofile();
	return;
}
Doctor::~Doctor()
{
}

string Doctor::getmed()
{
	string str;
	cout << "������ҩ��" << endl;
	cin >> str;
	return str;
}
void Doctor::askInfo(string name,string num,string idcard)//ѯ�ʲ���д������
{
	cout << "���ã����ʾ���ĹҺŵ���ͬʱ�ҽ�����һЩ����" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "�뽲һ�����Ĳ����Լ���ʷ��" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	string record, result;
	string moneyall,medicine;
	cin >> record;
	result = getResult();//��ȡ��Ͻ��
	medicine = getmed();//��ҩ
	
	//ʵ����ҩ�Ŀ����
	medicinal m1;
	//�������������
	m1.Outputlist(m1.Gethead(),1);
	int flag = m1.checkmedicinal();
	if (flag == 1){
		//����о�����ܷ���
		cout << "�������ܷ���" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cin >> moneyall;
	}
	else{
		//���û�о���ʾ����ȥ��ĵط�ȥ��
		cout << "�ܱ�Ǹ��ҽԺĿǰû�и�ҩ�ˣ�����ǰ�����ҩ�깺��" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		moneyall = "0";
	}
	
	//��󽫲������д������
	insertinfo(name, idcard, num, moneyall, record, result, medicine);
	//��ӡ����
	cout << "�����ú����ĹҺŵ���ǰ���ɷѴ��ɷ�" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++�Һŵ���Ϣ:++++++++++++++++++++++\n";
	cout << "\n";
	cout << "����" << "\t" << "���֤����" << "\t" << "�Һ�" << "\t\t" << "����" << "\t" << "�����Լ���ʷ" << "��Ͻ��" << "\t" << "ҩ��" << endl;
	cout << name << "\t" << idcard << "\t\t" << num << "\t" << moneyall << "\t" << record << "\t" << result << medicine << "\t" << endl;
	//�����ļ�
	Savetofile();

}
string Doctor::getResult(){
	string str;
	cout << "�����벡������Լ����" << endl;
	cin >> str;
	return str;
}
void Doctor::Savetofile()	//��������Ϣ�����ļ���
{

	ofstream in;
	in.open("patientinfo.txt", ios::trunc); //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�
	struct PatientInfo *p = d_head;
	int i = 0;
	string str1;
	//�洢��ʱ��ÿһ�����ݺ���һ���ո�
	while (p != NULL)
	{
		in << p->name << "\t" << p->idcard << "\t" << p->m_num << "\t" << p->money << "\t" << p->record << "\t" << p->result << "\t" << p->medicine << "\n";
		p = p->next;
	}

	in.close();//�ر��ļ�

}

void Doctor::loadFile()	//���ļ���Ϣ��ȡ��������
{


	ifstream inf;
	inf.open("patientinfo.txt");
	//ͷָ��ı���p
	struct PatientInfo *p = d_head;

	string sline;//ÿһ��
	string out;
	string  name, idcard, num, money, record, result, medicine;

	//���ж�ȡ
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name>>idcard>> num>> money>> record>> result>> medicine >> money;
		insertinfo( name,  idcard,  num,  money,  record,  result,  medicine);//����������
	}
	//Outputlist(d_head, 1);
	inf.close();
}