//��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��
#pragma once
#include <iostream>
#include <string>
using namespace std;

//�������
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string GetDeptName() = 0;

	int m_Id;//���
	string m_Name;//����
	int m_DeptId;//���ű��
};