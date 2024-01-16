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

//显示个人信息
void Manager::ShowInfo()
{
	cout << "职工的编号为：" << this->m_Id
		<< "\t职工的姓名为：" << this->m_Name
		<< "\t职工的岗位为：" << this->GetDeptName()
		<< "\t职工的职责为：完成老板交给的任务，并下发任务给员工" << endl;
}

//获取岗位名称
string Manager::GetDeptName()
{
	return string("经理");
}

Manager::~Manager()
{

}
