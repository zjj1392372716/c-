#pragma once
#include <string>
using namespace std;
struct Registers{					//ҽ�ƿ�ע����Ϣ����
	string name;
	string idcard;
	int age;
	string username;
	string password;
	struct Registers * next; 		//ָ�������е���һ���ṹ 
};
class List							//������
{
	
public:
	Registers *r_head;//ͷָ��
	List(){ r_head = NULL; }
	void insertlist(string name, string idcard, int age, string username, string password);//������Ĳ���
	void Deletelist(int aDate);//�������ɾ��
	void Outputlist(struct Registers *head, int flag);//����������
	Registers *Gethead(){ return r_head; }
	void Savetofile();//��������Ϣ�����ļ�
	void loadFile();	//���ļ���Ϣ��ȡ��������
	~List();
};

