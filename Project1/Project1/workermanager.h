#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//�ļ�����
#include<fstream>
#define FILENAME "empFile.txt"

class WorkManager
{
public:
	WorkManager();

	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArry;
	//�ж��ļ��Ƿ�Ϊ�ձ�־
	bool fileIsEmpty;

	//չʾ�˵�
	void ShowMenu();
	//�˳�ϵͳ
	void ExitSystem();
	//���ְ��
	void addEmp();
	//��������
	void save();
	//����ı��м�¼������
	int getEmpNum();
	//��ʼ��
	void initArray();
	//��ʾְ����Ϣ
	void showEmp();
	//ɾ��ְ����Ϣ
	void delEmp();
	//�ж�ְ���Ƿ����
	int isExist(int id);
	//�޸�ְ����Ϣ
	void modEmp();
	//����ְ����Ϣ
	void findEmp();
	//����
	void sortEmp();
	//��ղ���
	void clearFile();

	~WorkManager();
};
