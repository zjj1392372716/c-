#pragma once
#ifndef PATIENT_H
#define PATIENT_H
#include <string> 
#include "Person.h"
class Patient :public Person
{
public:
	Patient(string _name="", int _age=0, string _illname="", double _drug=0.0);
	void setContent(string _name, int _age, string _illname, double _drug);
	~Patient();//��������
	string getillname();//����
	void setillname(string illname);
	double getdrug();//ҩ��
	void setdrug(double drugmoney);
	string getidcard();//idcard
	void setidcard(string idcard);
	string getusername();//�û���
	void setusername(string user);
	string getpassword();//����
	void setpassword(string password);
	string getprescription();//ҩ��
	void setprescription(string prescription);
	int getid();//id�Һ�
	void setid(int id);

	string getname();
	int getage(); 

protected:
	string m_strillname;//����
	double m_ddrug;//ҩ�� 
	string m_idcard;//���֤����
	string m_password;//ҽ�ƿ�����
	string m_username;//ҽ�ƿ��û��� 
	string m_prescription;//ҩ��
	int m_id;//�Һ�

};

#endif