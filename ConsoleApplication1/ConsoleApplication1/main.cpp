#include <iostream>
#include <string>
#include "Patient.h" 
#include "List.h"
#include "Number.h"
#include <fstream>
#include<stdlib.h>  
#include "Doctor.h"
#include "medicinal.h"
using namespace std;
Patient p1;							//全局病人对象


//函数声明区 
int  menu();						//主目录菜单
void start();						//欢迎页面
void Patient1(); 					//病人身份主要函数 
void displayPatient();				//展示病人信息
void Outpatient();					//门诊
void toRegister();					//注册医疗卡
void saveDatatoReg(string name, string idcard, int age, string username, string password);//将注册数据存储到链表中 
void Save();						//保存注册链表中的数据到文件中
void DisplayReg(struct Registers *head, int flag);//打印注册链表中的数据 
void inputinfo(long long n);					//输入挂号信息
void toLogin();									//以有医疗卡去登录挂号
void DoctorDemo();								//医生模块
int DoctorDismenu(Doctor *d1);					//医生模块
void showmedicinal();							//展示药材库
void checkM(Doctor * p);						//检索药品库
void FindInMedicalCard();						//医疗卡查询病人信息
void exit();									//退出系统
int AdminDismenu();							//管理员子目录
void admin();									//管理员操作
//函数定义区 

void Outpatient()
{
	int m;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n";
	cout << "欢迎您来到医院门诊，您是否在本院已办理过医疗卡，如果没有请先在这里办一张医疗卡，谢谢配合!\n";
	cout << "\n";
	cout << "请输入您的选择：" << endl;
	cout << "1、已有\t\t\t2、没有\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cin >> m;
	switch (m){

	case 2:toRegister(); break;
	case 1:toLogin(); break;
	default:cout << "error\n";
	}


}
void DoctorDemo()								//医生模块
{
	Doctor *d1 = new Doctor();//实例化一个医生类
	d1->DoctorToLogin();//身份验证
	int flag;
	while (flag = DoctorDismenu(d1)){
		//显示子目录
		if (flag == 0){
			break;
		}
	}
}
void showmedicinal(){
	medicinal m1; m1.Outputlist(m1.Gethead(), 1);
}
void checkM(Doctor * p)
{
	p->checkmedicinal();

}
int DoctorDismenu(Doctor *d1)								//医生模块
{
	cout << "       *****************请输入您的选择********************\n";
	cout << "       **		1、查看诊断病例			**\n";
	cout << "       **		2、查看药品列表			**\n";
	cout << "       **		3、检索药品			**\n";
	cout << "       **		4、医疗卡查询病人病例				**\n";
	cout << "       **		5、退出						**\n";
	cout << "       **		亲，请输入您的选择：		**\n";
	
	int n;
	cin >> n;
	switch (n)
	{
	case 1: d1->Outputlist(d1->Gethead(), 1); break;
	case 2:	showmedicinal(); break;
	case 3:	checkM(d1); break;
	case 4: FindInMedicalCard(); break;
	case 5: return 0; break;
	}
	return 1;

}

void toLogin()									//以有医疗卡去登录挂号
{
	C:
	string username, pwd;
	cout << "请输入您的用户名" << endl;
	cin >> username;
	cout << "请输入您的密码" << endl;
	cin >> pwd;
	//到链表中检查是否有这个用户名和密码
	List l2;
	//实例化一个注册类
	int numm = l2.checkreglist(username, pwd);	//调用挂号类的检查方法
	if (numm == 0)
	{
		//身份确认失败后
		cout << "请重新输入一次" << endl;
		goto C;
	}
	else if (numm == 1)
	{
		//如果返回是true
		cout << "身份确认成功！！即将开始挂号.....\n";
		cout << "请按照提示完成下面挂号信息：\n";

	}
	
	//提示输入挂号信息
	Number n3;
	//实例化一个挂号类

	//读取文件内容到链表中
	long long n = n3.Length();
	n = n + 1;
	string name, idcard, department;
	string money = "20.0";
	string isexport;
	int m;
	cout << "NO.1 请输入您的姓名" << endl;
	cin >> name;
	cout << "NO.2 请输入您要去的部门" << endl;
	cin >> department;
	cout << "NO.3 请输入您的身份证号码" << endl;
	cin >> idcard;
	cout << "NO.4 您是否要专家门诊？" << endl;
	cout << "1、是" << "\t" << "2、否" << endl;
	cin >> m;
	switch (m){
	case 1:isexport = "yes"; break;
	case 2:isexport = "no"; break;
	}
	char buffer[256];
	int counter = n;
	sprintf(buffer, "%04i", counter);
	std::string number = std::string(buffer);

	n3.insertNum(name, idcard, number, department, money, isexport, 2);
	n3.Savetofile();
	cout << "您的号码是" << n << endl;
	//打印挂号信息
	cout << "恭喜您挂号成功！！！！！请您去看医生吧！" << endl;
	cout << "\n\n\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	//寻找医生看病
	Doctor d1;//实例化医生
	d1.DoctorToLogin();//登录---用户名为doctor密码为0000
	string new_name, new_num, new_idcard;
	new_name = name;
	new_num = number;
	new_idcard = idcard;
	//询问病人信息
	d1.askInfo(new_name, new_num, new_idcard);
}
void toRegister()
{
	string name, idcard, username, password, repassword;
	string  age;
	cout << "NO.1 请输入您的姓名" << endl;
	cin >> name;
	cout << "NO.2 请输入您的年龄" << endl;
	cin >> age;
A:
	cout << "NO.3 请输入您的身份证号码" << endl;
	cin >> idcard;
	cout << "NO.4 请输入您的医疗卡用户名" << endl;
	cin >> username;
B:
	cout << "NO.5 请输入您的医疗卡密码" << endl;
	cin >> password;
	cout << "NO.6 请再次输入您的医疗卡密码" << endl;
	cin >> repassword;
	if (idcard.length() != 18){
		cout << "您输入的身份证号码格式不正确哦\n";
		goto A;
	}
	if (password == repassword){
		cout << "恭喜您注册成功!\n";
		
		//实例化一个注册链表类
		List regList;
		//将信息存入到注册的链表中 
		regList.insertlist(name, idcard, age, username, password,1);
		
		//regList.Outputlist(regList.Gethead(),1);
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\n";
		cout << "请填写挂号信息,谢谢合作" << endl;
		cout << "\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		Number n1;
		//实例化一个挂号类

		//读取文件内容到链表中
		long long n = n1.Length();
		n = n + 1;
		//通过length函数返回链表的长度---》挂号数目 = 长度加一
		//提示输入挂号信息
		string name, idcard, department;
		string money = "20.0";
		string isexport;
		int m;
		cout << "请按照提示完成下列信息填写\n";
		cout << "NO.1 请输入您的姓名" << endl;
		cin >> name;
		cout << "NO.2 请输入您要去的部门" << endl;
		cin >> department;
		cout << "NO.3 请输入您的身份证号码" << endl;
		cin >> idcard;
		cout << "NO.4 您是否要专家门诊？" << endl;
		cout << "1、是" << "\t" << "2、否" << endl;
		cin >> m;
		switch (m){
		case 1:isexport = "yes"; break;
		case 2:isexport = "no"; break;
		}
		char buffer[256];
		int counter = n;
		sprintf(buffer, "%04i", counter);
		std::string number = std::string(buffer);
		//将挂号信息传到链表中
		n1.insertNum(name, idcard, number, department, money, isexport,2);
		n1.Savetofile();
		cout << "您的号码是" <<n<< endl;
		//打印挂号信息
		cout << "恭喜您挂号成功！！！！！请您去看医生吧！" << endl;
		cout << "\n\n\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		//寻找医生看病
		Doctor d1;//实例化医生
		d1.DoctorToLogin();//登录---用户名为doctor密码为0000
		string new_name, new_num, new_idcard;
		new_name = name;
		new_num = number;
		new_idcard = idcard;
		//询问病人信息
		d1.askInfo(new_name, new_num, new_idcard);
	}
	else{
		cout << "您两次输入的密码不一致\n";
		goto B;
	}
}
void FindInMedicalCard()
{
	E:
	string username, pwd;
	//请输入医疗卡的用户名和密码
	cout << "请输入医疗卡的用户名\n";
	cin >> username;
	cout << "请输入医疗卡的密码\n";
	cin >> pwd;
	List l3;//实例化医疗卡注册表类
	string flag = l3.checkinfo(username, pwd);
	if (flag.length()!=0)
	{
		//拿着返回值去病人信息库中查找
		cout << "身份确认成功，请稍等.....\n";
		Doctor d1;
		d1.findByIdcard(flag);//查找病人信息
	}
	else{
		cout << "很抱歉，请确认您的用户名和密码是否正确\n";
		goto E;
	}
	

}

void Patient1()
{
	string m_name;
	int age;
	string m_illname;
	cout << "Please enter your name：\n";
	cin >> m_name;
	cout << "Please enter your age：\n";
	cin >> age;
	cout << "Please enter your illname：\n";//病情
	cin >> m_illname;
	p1.setContent(m_name, age, m_illname, 0.0);//修改病人对象的数据
	displayPatient();
}
int  menu()							//主目录菜单 
{
	int n;
	cout<<"       *****************请输入您的身份********************\n";
	cout<<"       **		1、病人				**\n";
	cout<<"       **		2、管理员			**\n";
	cout<<"       **		3、医生				**\n";
	cout<<"       **		0、退出				**\n";
	cout<<"       **		亲，请输入您的选择：		**\n";
	cin >> n;
	switch (n)
	{
	case 1:Patient1(); break;
	case 2:admin();break;
	case 3:DoctorDemo();break;
	case 0:exit(); break;
	default:cout << "error\n";
	}
	return n;
}
void admin()								//管理员操作
{
	F:
	//首先登陆验证
	string username, pwd;
	cout << "请输入用户名" << endl;
	cin >> username;
	cout << "请输入密码" << endl;
	cin >> pwd;
	if (username == "admin"&&pwd == "admin")
	{
		cout << "身份验证成功!!!" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++\n";
	}
	else{
		goto F;
	}
	int flag;
	while (flag = AdminDismenu()){
		//显示子目录
		if (flag == 0){
			break;
		}
	}
}
int AdminDismenu()							//管理员子目录
{
	cout << "       *****************请输入您的选择********************\n";
	cout << "       **		1、查看病人注册信息		**\n";
	cout << "       **		2、查看挂号信息			**\n";
	cout << "       **		0、退出				**\n";
	cout << "       **		亲，请输入您的选择：		**\n";
	int n;
	List l1;
	Number n1;
	cin >> n;
	switch (n)
	{
	case 1: l1.Outputlist(l1.Gethead(), 1); break;
	case 2:	n1.Outputlist(n1.Gethead(), 1); break;
	case 0: return 0; break;
	}
	return 1;
}
void exit()				//退出系统
{
	exit(1);
}
void displayPatient(){
	int n;
	cout << "\n\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "您的信息为：" << endl;
	cout << "姓名：" << p1.getname() << "\t" << "年龄：" << p1.getage() << endl;
	cout << "病情：" << p1.getillname() << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\n";
	cout << "您是否前往医院找医生看病?请选择：" << endl;
	cout << "1、前往\t\t\t2、拒绝\n";
	cout << "-------------------------------------------------------\n";
	cin >> n;
	switch (n)
	{
		//继续这里
	case 1:Outpatient(); break;
	case 2:cout << "请选择您的身份\n"; break;
	}
}
int main() {
	//system("color 3f");											//设置颜色主题
	start();													//欢迎页面 
	while (menu()){
		//循环目录 
	}
	system("pause");
	return 0;
}

void start(){

	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"                       ***************************\n";
	cout<<"                          欢迎使用本系统\n";
	cout<<"                       ***************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout << "\n";
	cout << "\n";

}