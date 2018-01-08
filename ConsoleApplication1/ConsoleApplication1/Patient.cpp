#include "Patient.h"
#include "Person.h"
Patient::Patient(string _name, int _age, string _illname, double _drug) :Person(_name, _age)
{
	m_strillname = _illname;
	m_ddrug = _drug;
}
void Patient::setContent(string _name, int _age, string _illname, double _drug){
	m_strillname = _illname;
	m_ddrug = _drug;
	Person::m_strname = _name;
	Person::age = _age;
}

string Patient::getillname(){
	return m_strillname;
}
void Patient::setillname(string illname){
	m_strillname = illname;
}
double Patient::getdrug(){
	return m_ddrug;
}
void Patient::setdrug(double drugmoney){
	m_ddrug = drugmoney;
}
string Patient::getidcard(){
	return m_idcard;
}
void Patient::setidcard(string idcard){
	m_idcard = idcard;
}
string Patient::getusername(){
	return m_username;
}
void Patient::setusername(string user){
	m_username = user;
}
string Patient::getpassword(){
	return m_password;
}
void Patient::setpassword(string password){
	m_password = password;
}
string Patient::getprescription(){
	return m_prescription;
}
void Patient::setprescription(string prescription){
	m_prescription = prescription;
}
int Patient::getid(){
	return m_id;
}
void Patient::setid(int id){
	m_id = id;
}
string Patient::getname(){
	return Person::m_strname;

}
int Patient::getage(){
	return Person::age;
}
Patient::~Patient()
{


}