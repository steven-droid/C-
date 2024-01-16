#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:
	Boss(int Id, string Name, int DeptId);

	//显示个人信息
	virtual void ShowInfo();

	//获取岗位名称
	virtual string GetDeptName();

	~Boss();
};
