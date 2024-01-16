//员工类
//公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责
//普通员工职责：完成经理交给的任务
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:
	//员工类构造函数
	Employee(int Id,string Name,int DeptId);

	//显示个人信息
	virtual void ShowInfo();

	//获取岗位名称
	virtual string GetDeptName();

	//员工类析构函数
	~Employee();
};
