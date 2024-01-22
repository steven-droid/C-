#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

class WorkManager
{
public:
	WorkManager();

	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArry;

	//添加职工
	void addEmp();

	~WorkManager();
};
