#include <iostream>
#include <string>
#include "Patient.h" 
#include "List.h"
#include "Number.h"
#include <fstream>
#include<stdlib.h>  
#include "Doctor.h"
using namespace std;
Patient p1;							//全局病人对象

struct Registers * r_head = NULL;	//注册链表头指针
struct Registers * r_prev = NULL, *r_current = NULL;
struct id{							//挂号链表
	string name;
	string idcard;
	int m_id;
	struct id * next; 				//指向链表中的下一个结构 
};
//struct id * id_head = NULL;			//挂号链表头指针
//struct id * id_prev = NULL, *id_current = NULL;
//函数声明区 
int  menu();						//主目录菜单
void start();						//欢迎页面
void Patient1(); 					//病人身份主要函数 
void displayPatient();				//展示病人信息
void Outpatient();					//门诊
void toRegister();					//注册医疗卡
void saveDatatoReg(string name, string idcard, int age, string username, string password);//将注册数据存储到链表中 
void Save();						//保存注册链表中的数据到文件中
void DisplayReg(struct Registers *head, int flag);	//打印注册链表中的数据 
void inputinfo(long long n);					//输入挂号信息
void toLogin();									//以有医疗卡去登录挂号
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

	}


}
void toLogin()									//以有医疗卡去登录挂号
{
	string username, pwd;
	cout << "请输入您的用户名" << endl;
	cin >> username;
	cout << "请输入您的密码" << endl;
	cin >> pwd;
	//到链表中检查是否有这个用户名和密码
	//实例化一个注册类

	//调用挂号类的检查方法
	
	//如果返回是true
	//提示输入挂号信息
	/*
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

	n2.insertNum(name, idcard, number, department, money, isexport, 2);
	n2.Savetofile();
	cout << "您的号码是" << n << endl;
	//打印挂号信息
	cout << "恭喜您挂号成功！！！！！请您去看医生吧！" << endl;
	*/
}
void toRegister()
{
	string name, idcard, username, password, repassword;
	int age;
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
		regList.insertlist(name, idcard, age, username, password);
		
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
		string new_name, new_num, new_idcard;
		new_name = p1.getname();
		new_num = n;
		new_idcard = p1.getidcard();
		//询问病人信息
		d1.askInfo(new_name, new_num, new_idcard);
	}
	else{
		cout << "您两次输入的密码不一致\n";
		goto B;
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
	/*List l1;
	l1.loadFile();
	l1.Outputlist(l1.Gethead(), 1);*/
	
	puts("       *****************请输入您的身份********************\n");
	puts("       **		1、病人				**\n");
	puts("       **		2、管理员			**\n");
	puts("       **		3、医生				**\n");
	puts("       **		0、退出				**\n");
	puts("       **		亲，请输入您的选择：		**\n");
	cin >> n;
	switch (n)
	{
	case 1:Patient1(); break;
		//		case 2:;break;
		//		case 3:deleteStudents();break;

	}
	return n;
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

	puts("       ***********************************************************");
	puts("       ***********************************************************");
	puts("       ***********************************************************");
	puts("                       ***************************");
	printf("                            欢迎使用本系统\n");
	puts("                       ***************************");
	puts("       ***********************************************************");
	puts("       ***********************************************************");
	puts("       ***********************************************************");
	printf("\n");
	printf("\n");

}