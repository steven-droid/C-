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

	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArry;

	//���ְ��
	void addEmp();

	~WorkManager();
};
