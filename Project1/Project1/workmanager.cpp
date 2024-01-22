#include "workermanager.h"
using namespace std;

WorkManager::WorkManager()
{
	//��ʼ������
	this->m_EmpNum = 0;
	this->m_EmpArry = NULL;
}

void WorkManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);//�˳�
}

void WorkManager::addEmp()
{
	//����ӵ�����
	int addNum = 0;
	cout << "���������������";
	cin >> addNum;
	cout << endl;

	if (addNum > 0)
	{
		//���
		//������Ҫ��ӵĿռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�����ݿ������µĿռ�
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArry[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			system("cls");
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "λְ���ı�ţ�";
			cin >> id;
			cout << endl;

			cout << "�������" << i+1 << "λְ����������";
			cin >> name;
			cout << endl;

			cout << "�������" << i + 1 << "λְ���Ĳ��ţ�" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			cout << endl;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:worker = new Employee(id, name, 1);
				break;
			case 2:worker = new Manager(id, name, 2);
				break;
			case 3:worker = new Boss(id, name, 3);
			default:
				break;
			}

			//������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArry;

		//�����¿ռ��ָ��
		this->m_EmpArry = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//д���ļ�

		//��ʾ��ӳɹ�
		cout << "��ӳɹ���" << endl;
	}
	else
	{
		cout << "�������������" << endl;
	}

	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{

}