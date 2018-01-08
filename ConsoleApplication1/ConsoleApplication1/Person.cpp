#include "Person.h"

Person::Person(string _name, int _age)
{
	m_strname = _name;
	age = _age;
}

string Person::getname(){
	return m_strname;
}
Person::~Person()
{

}