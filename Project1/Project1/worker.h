//公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责
#pragma once
#include <iostream>
#include <string>
using namespace std;

//抽象基类
class Worker
{
public:

	//显示个人信息
	virtual void ShowInfo() = 0;

	//获取岗位名称
	virtual string GetDeptName() = 0;

	int m_Id;//编号
	string m_Name;//姓名
	int m_DeptId;//部门编号
};