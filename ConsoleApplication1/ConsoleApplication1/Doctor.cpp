#include "Doctor.h"
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>    //使用stringstream需要引入这个头文件  
#include <stdlib.h>
using namespace std;

Doctor::Doctor(){
	d_head = NULL;
	loadFile();//当初始化的时候就加载文件到链表

}
void Doctor::Outputlist(struct PatientInfo *head, int flag)//链表结点的输出
{
	struct PatientInfo *p = head;
	if (p == NULL)
	{
		return;
	}
	if (flag == 1)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+++++++++++++++++++病人信息：++++++++++++++++++++++\n";
		cout << "\n";
		cout << "姓名" << "\t" << "身份证号码" << "\t" << "挂号" << "\t\t" << "费用" << "\t" << "病情以及病史" << "诊断结果" <<"\t"<<"药方"<< endl;
	}
	cout << p->name << "\t" << p->idcard << "\t\t" << p->m_num << "\t" << p->money<< "\t" << p->record << "\t" << p->result << p->medicine<<"\t"<<endl;

	Outputlist(p->next, 0);
}
void Doctor::insertinfo(string name, string idcard, string num, string money, string record, string result, string medicine)//链表结点的插入
{
	struct PatientInfo *p = NULL, *pr = d_head;
	p = (PatientInfo *)new(PatientInfo);


	if (p == NULL)
	{
		cout<<("申请内存失败");
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
		cout << "+++++++++++++++++++您的挂号信息：++++++++++++++++++++++\n";
		cout << "\n";
		cout << "姓名" << "\t" << "所挂号码" << "\t" << "身份证号码" << "\t\t" << "部门" << "\t" << "是否专家门诊" << "挂号费用" << endl;
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
	cout << "请输入药方" << endl;
	cin >> str;
	return str;
}
void Doctor::askInfo(string name,string num,string idcard)//询问病情写入链表
{
	cout << "您好，请出示您的挂号单，同时我将问您一些问题" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "请讲一下您的病情以及病史吧" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	string record, result;
	string moneyall,medicine;
	cin >> record;
	result = getResult();//获取诊断结果
	medicine = getmed();//开药
	
	//实例化药材库对象
	medicinal m1;
	//调用其检索方法
	m1.Outputlist(m1.Gethead(),1);
	int flag = m1.checkmedicinal();
	if (flag == 1){
		//如果有就求出总费用
		cout << "请输入总费用" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cin >> moneyall;
	}
	else{
		//如果没有就提示病人去别的地方去买
		cout << "很抱歉，医院目前没有该药了，请您前往别的药店购买。" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		moneyall = "0";
	}
	
	//最后将病人情况写入链表
	insertinfo(name, idcard, num, moneyall, record, result, medicine);
	//打印单子
	cout << "请您拿好您的挂号单，前往缴费处缴费" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++挂号单信息:++++++++++++++++++++++\n";
	cout << "\n";
	cout << "姓名" << "\t" << "身份证号码" << "\t" << "挂号" << "\t\t" << "费用" << "\t" << "病情以及病史" << "诊断结果" << "\t" << "药方" << endl;
	cout << name << "\t" << idcard << "\t\t" << num << "\t" << moneyall << "\t" << record << "\t" << result << medicine << "\t" << endl;
	//存入文件
	Savetofile();

}
string Doctor::getResult(){
	string str;
	cout << "请输入病情分析以及结果" << endl;
	cin >> str;
	return str;
}
void Doctor::Savetofile()	//将链表信息存入文件中
{

	ofstream in;
	in.open("patientinfo.txt", ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	struct PatientInfo *p = d_head;
	int i = 0;
	string str1;
	//存储的时候每一个数据后都有一个空格
	while (p != NULL)
	{
		in << p->name << "\t" << p->idcard << "\t" << p->m_num << "\t" << p->money << "\t" << p->record << "\t" << p->result << "\t" << p->medicine << "\n";
		p = p->next;
	}

	in.close();//关闭文件

}

void Doctor::loadFile()	//将文件信息读取到链表中
{


	ifstream inf;
	inf.open("patientinfo.txt");
	//头指针的别名p
	struct PatientInfo *p = d_head;

	string sline;//每一行
	string out;
	string  name, idcard, num, money, record, result, medicine;

	//逐行读取
	while (getline(inf, sline))
	{
		istringstream sin(sline);
		sin >> name>>idcard>> num>> money>> record>> result>> medicine >> money;
		insertinfo( name,  idcard,  num,  money,  record,  result,  medicine);//插入链表中
	}
	//Outputlist(d_head, 1);
	inf.close();
}