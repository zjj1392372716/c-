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
	~Patient();//析构函数
	string getillname();//病情
	void setillname(string illname);
	double getdrug();//药费
	void setdrug(double drugmoney);
	string getidcard();//idcard
	void setidcard(string idcard);
	string getusername();//用户名
	void setusername(string user);
	string getpassword();//密码
	void setpassword(string password);
	string getprescription();//药方
	void setprescription(string prescription);
	int getid();//id挂号
	void setid(int id);

	string getname();
	int getage(); 

protected:
	string m_strillname;//病情
	double m_ddrug;//药费 
	string m_idcard;//身份证号码
	string m_password;//医疗卡密码
	string m_username;//医疗卡用户名 
	string m_prescription;//药方
	int m_id;//挂号

};

#endif