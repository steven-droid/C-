#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:
	Boss(int Id, string Name, int DeptId);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetDeptName();

	~Boss();
};
