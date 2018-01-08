#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
public:
	
	Person(string _name, int _age);
	~Person();
	string getname();
protected:
	string m_strname;//ĞÕÃû 
	int age; //ÄêÁä 

};

#endif