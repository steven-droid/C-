#pragma once
#include <iostream>
#include<string>
using namespace std;
#include "manager.h"

Manager::Manager(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}

//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ���ı��Ϊ��" << this->m_Id
		<< "\tְ��������Ϊ��" << this->m_Name
		<< "\tְ���ĸ�λΪ��" << this->GetDeptName()
		<< "\tְ����ְ��Ϊ������ϰ彻�������񣬲��·������Ա��" << endl;
}

//��ȡ��λ����
string Manager::GetDeptName()
{
	return string("����");
}

Manager::~Manager()
{

}
