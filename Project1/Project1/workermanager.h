#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//文件交互
#include<fstream>
#define FILENAME "empFile.txt"

class WorkManager
{
public:
	WorkManager();

	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArry;
	//判断文件是否为空标志
	bool fileIsEmpty;

	//展示菜单
	void ShowMenu();
	//退出系统
	void ExitSystem();
	//添加职工
	void addEmp();
	//保存数据
	void save();
	//获得文本中记录的数量
	int getEmpNum();
	//初始化
	void initArray();
	//显示职工信息
	void showEmp();
	//删除职工信息
	void delEmp();
	//判断职工是否存在
	int isExist(int id);
	//修改职工信息
	void modEmp();
	//查找职工信息
	void findEmp();
	//排序
	void sortEmp();
	//清空操作
	void clearFile();

	~WorkManager();
};
