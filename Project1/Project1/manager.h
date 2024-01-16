//经理类
//需要显示职工编号、职工姓名、职工岗位、以及职责
//经理职责：完成老板交给的任务，并下发任务给员工
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Manager :public Worker
{
public:
	Manager(int Id, string Name, int DeptId);

	//显示个人信息
	virtual void ShowInfo();

	//获取岗位名称
	virtual string GetDeptName();

	~Manager();
};
