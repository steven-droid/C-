//��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��
//��ͨԱ��ְ����ɾ�����������
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "employee.h"

//Ա���๹�캯��
Employee::Employee(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}

//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ���ı��Ϊ��" << this->m_Id
		<< "\tְ��������Ϊ��" << this->m_Name
		<< "\tְ���ĸ�λΪ��" << this->GetDeptName()
		<< "\tְ����ְ��Ϊ����ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::GetDeptName()
{
	return string("Ա��");
}

//Ա������������
Employee::~Employee()
{

}