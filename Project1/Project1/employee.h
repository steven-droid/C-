//Ա����
//��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��
//��ͨԱ��ְ����ɾ�����������
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:
	//Ա���๹�캯��
	Employee(int Id,string Name,int DeptId);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetDeptName();

	//Ա������������
	~Employee();
};
