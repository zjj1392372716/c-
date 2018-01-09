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
Patient p1;							//ȫ�ֲ��˶���


//���������� 
int  menu();						//��Ŀ¼�˵�
void start();						//��ӭҳ��
void Patient1(); 					//���������Ҫ���� 
void displayPatient();				//չʾ������Ϣ
void Outpatient();					//����
void toRegister();					//ע��ҽ�ƿ�
void saveDatatoReg(string name, string idcard, int age, string username, string password);//��ע�����ݴ洢�������� 
void Save();						//����ע�������е����ݵ��ļ���
void DisplayReg(struct Registers *head, int flag);//��ӡע�������е����� 
void inputinfo(long long n);					//����Һ���Ϣ
void toLogin();									//����ҽ�ƿ�ȥ��¼�Һ�
void DoctorDemo();								//ҽ��ģ��
int DoctorDismenu(Doctor *d1);					//ҽ��ģ��
void showmedicinal();							//չʾҩ�Ŀ�
void checkM(Doctor * p);						//����ҩƷ��
void FindInMedicalCard();						//ҽ�ƿ���ѯ������Ϣ
void exit();									//�˳�ϵͳ
int AdminDismenu();							//����Ա��Ŀ¼
void admin();									//����Ա����
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
	default:cout << "error\n";
	}


}
void DoctorDemo()								//ҽ��ģ��
{
	Doctor *d1 = new Doctor();//ʵ����һ��ҽ����
	d1->DoctorToLogin();//�����֤
	int flag;
	while (flag = DoctorDismenu(d1)){
		//��ʾ��Ŀ¼
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
int DoctorDismenu(Doctor *d1)								//ҽ��ģ��
{
	cout << "       *****************����������ѡ��********************\n";
	cout << "       **		1���鿴��ϲ���			**\n";
	cout << "       **		2���鿴ҩƷ�б�			**\n";
	cout << "       **		3������ҩƷ			**\n";
	cout << "       **		4��ҽ�ƿ���ѯ���˲���				**\n";
	cout << "       **		5���˳�						**\n";
	cout << "       **		�ף�����������ѡ��		**\n";
	
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

void toLogin()									//����ҽ�ƿ�ȥ��¼�Һ�
{
	C:
	string username, pwd;
	cout << "�����������û���" << endl;
	cin >> username;
	cout << "��������������" << endl;
	cin >> pwd;
	//�������м���Ƿ�������û���������
	List l2;
	//ʵ����һ��ע����
	int numm = l2.checkreglist(username, pwd);	//���ùҺ���ļ�鷽��
	if (numm == 0)
	{
		//���ȷ��ʧ�ܺ�
		cout << "����������һ��" << endl;
		goto C;
	}
	else if (numm == 1)
	{
		//���������true
		cout << "���ȷ�ϳɹ�����������ʼ�Һ�.....\n";
		cout << "�밴����ʾ�������Һ���Ϣ��\n";

	}
	
	//��ʾ����Һ���Ϣ
	Number n3;
	//ʵ����һ���Һ���

	//��ȡ�ļ����ݵ�������
	long long n = n3.Length();
	n = n + 1;
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

	n3.insertNum(name, idcard, number, department, money, isexport, 2);
	n3.Savetofile();
	cout << "���ĺ�����" << n << endl;
	//��ӡ�Һ���Ϣ
	cout << "��ϲ���Һųɹ���������������ȥ��ҽ���ɣ�" << endl;
	cout << "\n\n\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	//Ѱ��ҽ������
	Doctor d1;//ʵ����ҽ��
	d1.DoctorToLogin();//��¼---�û���Ϊdoctor����Ϊ0000
	string new_name, new_num, new_idcard;
	new_name = name;
	new_num = number;
	new_idcard = idcard;
	//ѯ�ʲ�����Ϣ
	d1.askInfo(new_name, new_num, new_idcard);
}
void toRegister()
{
	string name, idcard, username, password, repassword;
	string  age;
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
		regList.insertlist(name, idcard, age, username, password,1);
		
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
		cout << "�밴����ʾ���������Ϣ��д\n";
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
		d1.DoctorToLogin();//��¼---�û���Ϊdoctor����Ϊ0000
		string new_name, new_num, new_idcard;
		new_name = name;
		new_num = number;
		new_idcard = idcard;
		//ѯ�ʲ�����Ϣ
		d1.askInfo(new_name, new_num, new_idcard);
	}
	else{
		cout << "��������������벻һ��\n";
		goto B;
	}
}
void FindInMedicalCard()
{
	E:
	string username, pwd;
	//������ҽ�ƿ����û���������
	cout << "������ҽ�ƿ����û���\n";
	cin >> username;
	cout << "������ҽ�ƿ�������\n";
	cin >> pwd;
	List l3;//ʵ����ҽ�ƿ�ע�����
	string flag = l3.checkinfo(username, pwd);
	if (flag.length()!=0)
	{
		//���ŷ���ֵȥ������Ϣ���в���
		cout << "���ȷ�ϳɹ������Ե�.....\n";
		Doctor d1;
		d1.findByIdcard(flag);//���Ҳ�����Ϣ
	}
	else{
		cout << "�ܱ�Ǹ����ȷ�������û����������Ƿ���ȷ\n";
		goto E;
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
	cout<<"       *****************�������������********************\n";
	cout<<"       **		1������				**\n";
	cout<<"       **		2������Ա			**\n";
	cout<<"       **		3��ҽ��				**\n";
	cout<<"       **		0���˳�				**\n";
	cout<<"       **		�ף�����������ѡ��		**\n";
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
void admin()								//����Ա����
{
	F:
	//���ȵ�½��֤
	string username, pwd;
	cout << "�������û���" << endl;
	cin >> username;
	cout << "����������" << endl;
	cin >> pwd;
	if (username == "admin"&&pwd == "admin")
	{
		cout << "�����֤�ɹ�!!!" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++\n";
	}
	else{
		goto F;
	}
	int flag;
	while (flag = AdminDismenu()){
		//��ʾ��Ŀ¼
		if (flag == 0){
			break;
		}
	}
}
int AdminDismenu()							//����Ա��Ŀ¼
{
	cout << "       *****************����������ѡ��********************\n";
	cout << "       **		1���鿴����ע����Ϣ		**\n";
	cout << "       **		2���鿴�Һ���Ϣ			**\n";
	cout << "       **		0���˳�				**\n";
	cout << "       **		�ף�����������ѡ��		**\n";
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
void exit()				//�˳�ϵͳ
{
	exit(1);
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

	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"                       ***************************\n";
	cout<<"                          ��ӭʹ�ñ�ϵͳ\n";
	cout<<"                       ***************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout<<"       ***********************************************************\n";
	cout << "\n";
	cout << "\n";

}