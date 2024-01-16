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

//显示个人信息
void Boss::ShowInfo()
{
	cout << "职工的编号为：" << this->m_Id
		<< "\t职工的姓名为：" << this->m_Name
		<< "\t职工的岗位为：" << this->GetDeptName()
		<< "\t职工的职责为：管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::GetDeptName()
{
	return string("老板");
}

Boss::~Boss()
{

}