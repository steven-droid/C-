#pragma once
#include<iostream>
#include <string>
using namespace std;
#include"boss.h"

Boss::Boss(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}

//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ���ı��Ϊ��" << this->m_Id
		<< "\tְ��������Ϊ��" << this->m_Name
		<< "\tְ���ĸ�λΪ��" << this->GetDeptName()
		<< "\tְ����ְ��Ϊ������˾��������" << endl;
}

//��ȡ��λ����
string Boss::GetDeptName()
{
	return string("�ϰ�");
}

Boss::~Boss()
{

}