#include <iostream>
#include <string>
#include "Patient.h" 
#include "List.h"
#include "Number.h"
#include <fstream>
#include<stdlib.h>  
#include "Doctor.h"
using namespace std;
Patient p1;							//ȫ�ֲ��˶���

struct Registers * r_head = NULL;	//ע������ͷָ��
struct Registers * r_prev = NULL, *r_current = NULL;
struct id{							//�Һ�����
	string name;
	string idcard;
	int m_id;
	struct id * next; 				//ָ�������е���һ���ṹ 
};
//struct id * id_head = NULL;			//�Һ�����ͷָ��
//struct id * id_prev = NULL, *id_current = NULL;
//���������� 
int  menu();						//��Ŀ¼�˵�
void start();						//��ӭҳ��
void Patient1(); 					//���������Ҫ���� 
void displayPatient();				//չʾ������Ϣ
void Outpatient();					//����
void toRegister();					//ע��ҽ�ƿ�
void saveDatatoReg(string name, string idcard, int age, string username, string password);//��ע�����ݴ洢�������� 
void Save();						//����ע�������е����ݵ��ļ���
void DisplayReg(struct Registers *head, int flag);	//��ӡע�������е����� 
void inputinfo(long long n);					//����Һ���Ϣ
void toLogin();									//����ҽ�ƿ�ȥ��¼�Һ�
//���������� 

void Outpatient()
{
	int m;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n";
	cout << "��ӭ������ҽԺ������Ƿ��ڱ�Ժ�Ѱ����ҽ�ƿ������û�������������һ��ҽ�ƿ���лл���!\n";
	cout << "\n";
	cout << "����������ѡ��" << endl;
	cout << "1������\t\t\t2��û��\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cin >> m;
	switch (m){

	case 2:toRegister(); break;
	case 1:toLogin(); break;

	}


}
void toLogin()									//����ҽ�ƿ�ȥ��¼�Һ�
{
	string username, pwd;
	cout << "�����������û���" << endl;
	cin >> username;
	cout << "��������������" << endl;
	cin >> pwd;
	//�������м���Ƿ�������û���������
	//ʵ����һ��ע����

	//���ùҺ���ļ�鷽��
	
	//���������true
	//��ʾ����Һ���Ϣ
	/*
	string name, idcard, department;
	string money = "20.0";
	string isexport;
	int m;
	cout << "NO.1 ��������������" << endl;
	cin >> name;
	cout << "NO.2 ��������Ҫȥ�Ĳ���" << endl;
	cin >> department;
	cout << "NO.3 �������������֤����" << endl;
	cin >> idcard;
	cout << "NO.4 ���Ƿ�Ҫר�����" << endl;
	cout << "1����" << "\t" << "2����" << endl;
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
	cout << "���ĺ�����" << n << endl;
	//��ӡ�Һ���Ϣ
	cout << "��ϲ���Һųɹ���������������ȥ��ҽ���ɣ�" << endl;
	*/
}
void toRegister()
{
	string name, idcard, username, password, repassword;
	int age;
	cout << "NO.1 ��������������" << endl;
	cin >> name;
	cout << "NO.2 ��������������" << endl;
	cin >> age;
A:
	cout << "NO.3 �������������֤����" << endl;
	cin >> idcard;
	cout << "NO.4 ����������ҽ�ƿ��û���" << endl;
	cin >> username;
B:
	cout << "NO.5 ����������ҽ�ƿ�����" << endl;
	cin >> password;
	cout << "NO.6 ���ٴ���������ҽ�ƿ�����" << endl;
	cin >> repassword;
	if (idcard.length() != 18){
		cout << "����������֤�����ʽ����ȷŶ\n";
		goto A;
	}
	if (password == repassword){
		cout << "��ϲ��ע��ɹ�!\n";
		
		//ʵ����һ��ע��������
		List regList;
		//����Ϣ���뵽ע��������� 
		regList.insertlist(name, idcard, age, username, password);
		
		//regList.Outputlist(regList.Gethead(),1);
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\n";
		cout << "����д�Һ���Ϣ,лл����" << endl;
		cout << "\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		Number n1;
		//ʵ����һ���Һ���

		//��ȡ�ļ����ݵ�������
		long long n = n1.Length();
		n = n + 1;
		//ͨ��length������������ĳ���---���Һ���Ŀ = ���ȼ�һ
		//��ʾ����Һ���Ϣ
		string name, idcard, department;
		string money = "20.0";
		string isexport;
		int m;
		cout << "NO.1 ��������������" << endl;
		cin >> name;
		cout << "NO.2 ��������Ҫȥ�Ĳ���" << endl;
		cin >> department;
		cout << "NO.3 �������������֤����" << endl;
		cin >> idcard;
		cout << "NO.4 ���Ƿ�Ҫר�����" << endl;
		cout << "1����" << "\t" << "2����" << endl;
		cin >> m;
		switch (m){
		case 1:isexport = "yes"; break;
		case 2:isexport = "no"; break;
		}
		char buffer[256];
		int counter = n;
		sprintf(buffer, "%04i", counter);
		std::string number = std::string(buffer);
		//���Һ���Ϣ����������
		n1.insertNum(name, idcard, number, department, money, isexport,2);
		n1.Savetofile();
		cout << "���ĺ�����" <<n<< endl;
		//��ӡ�Һ���Ϣ
		cout << "��ϲ���Һųɹ���������������ȥ��ҽ���ɣ�" << endl;
		cout << "\n\n\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		//Ѱ��ҽ������
		Doctor d1;//ʵ����ҽ��
		string new_name, new_num, new_idcard;
		new_name = p1.getname();
		new_num = n;
		new_idcard = p1.getidcard();
		//ѯ�ʲ�����Ϣ
		d1.askInfo(new_name, new_num, new_idcard);
	}
	else{
		cout << "��������������벻һ��\n";
		goto B;
	}
}


void Patient1()
{
	string m_name;
	int age;
	string m_illname;
	cout << "Please enter your name��\n";
	cin >> m_name;
	cout << "Please enter your age��\n";
	cin >> age;
	cout << "Please enter your illname��\n";//����
	cin >> m_illname;
	p1.setContent(m_name, age, m_illname, 0.0);//�޸Ĳ��˶��������
	displayPatient();
}
int  menu()							//��Ŀ¼�˵� 
{
	int n;
	/*List l1;
	l1.loadFile();
	l1.Outputlist(l1.Gethead(), 1);*/
	
	puts("       *****************�������������********************\n");
	puts("       **		1������				**\n");
	puts("       **		2������Ա			**\n");
	puts("       **		3��ҽ��				**\n");
	puts("       **		0���˳�				**\n");
	puts("       **		�ף�����������ѡ��		**\n");
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
	cout << "������ϢΪ��" << endl;
	cout << "������" << p1.getname() << "\t" << "���䣺" << p1.getage() << endl;
	cout << "���飺" << p1.getillname() << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n\n";
	cout << "���Ƿ�ǰ��ҽԺ��ҽ������?��ѡ��" << endl;
	cout << "1��ǰ��\t\t\t2���ܾ�\n";
	cout << "-------------------------------------------------------\n";
	cin >> n;
	switch (n)
	{
		//��������
	case 1:Outpatient(); break;
	case 2:cout << "��ѡ���������\n"; break;
	}
}
int main() {
	//system("color 3f");											//������ɫ����
	start();													//��ӭҳ�� 
	while (menu()){
		//ѭ��Ŀ¼ 
	}
	system("pause");
	return 0;
}

void start(){

	puts("       ***********************************************************");
	puts("       ***********************************************************");
	puts("       ***********************************************************");
	puts("                       ***************************");
	printf("                            ��ӭʹ�ñ�ϵͳ\n");
	puts("                       ***************************");
	puts("       ***********************************************************");
	puts("       ***********************************************************");
	puts("       ***********************************************************");
	printf("\n");
	printf("\n");

}