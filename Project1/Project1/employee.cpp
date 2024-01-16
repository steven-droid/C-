//公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责
//普通员工职责：完成经理交给的任务
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "employee.h"

//员工类构造函数
Employee::Employee(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}

//显示个人信息
void Employee::ShowInfo()
{
	cout << "职工的编号为：" << this->m_Id
		<< "\t职工的姓名为：" << this->m_Name
		<< "\t职工的岗位为：" << this->GetDeptName()
		<< "\t职工的职责为：完成经理交给的任务" << endl;
}

//获取岗位名称
string Employee::GetDeptName()
{
	return string("员工");
}

//员工类析构函数
Employee::~Employee()
{

}