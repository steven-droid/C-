//������
//��Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��
//����ְ������ϰ彻�������񣬲��·������Ա��
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Manager :public Worker
{
public:
	Manager(int Id, string Name, int DeptId);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetDeptName();

	~Manager();
};
