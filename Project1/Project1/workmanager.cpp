#include "workermanager.h"
using namespace std;

WorkManager::WorkManager()
{
	//���ļ�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�жϴ����ļ������ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())//ifs.efo()Ϊ�����ļ��еĵ�һ���ַ�Ϊ�ļ�β����Ϊtrue������ļ�Ϊ��
	{
		cout << "�ļ����ڵ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpArry = 0;
		this->m_EmpNum = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ��������м�¼
	int num = getEmpNum();
	this->m_EmpNum = num;
	//this->m_EmpNum = this->getEmpNum();
	cout << "��" << num << "��ְ����¼��" << endl;

	//�����ռ�
	this->m_EmpArry = new Worker * [num];
	//���ļ��е����ݴ洢������
	this->initArray();

	//inieArray()���Դ���
	for (int i = 0; i < num; i++)
	{
		cout << "��ţ�" << this->m_EmpArry[i]->m_Id << " "
			<< "������" << this->m_EmpArry[i]->m_Name << endl;
	}
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
		Worker** newSpace = new Worker* [newSize];

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

			while (1)
			{
				cout << "�������" << i + 1 << "λְ���Ĳ��ţ�" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dSelect;
				if (0 < dSelect && dSelect > 3)
				{
					cout << "��������,����������" << endl;
					continue;
				}
				cout << endl;
				break;
			}

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
		this->save();
		this->fileIsEmpty = false;//�ļ���������

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

void WorkManager::save()
{
	ofstream ofs;
	//���ļ�
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArry[i]->m_Id << " "
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

int WorkManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);


	int age;
	string name;
	int dId;
	int num = 0;//����
	while (ifs >> age && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkManager::initArray()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;//�����±�
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArry[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkManager::showEmp()
{
	if (!this->fileIsEmpty)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//cout << "ְ����ţ�" << m_EmpArry[i]->m_Id << " "
			//	<< "ְ��������" << m_EmpArry[i]->m_Name << " "
			//	<< "ְ�����ţ�" << m_EmpArry[i]->GetDeptName() << endl;
			this->m_EmpArry[i]->ShowInfo();
		}
	}
	else
	{
		cout << "�ļ�Ϊ�գ�" << endl;
	}

	system("pause");
	system("cls");
}

int WorkManager::isExist(int id)
{
	//���������±�
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArry[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkManager::delEmp()
{
	if (!this->fileIsEmpty)
	{
		int id = 0;
		while (1)
		{
			cout << "��������Ҫɾ����Ա�����(����000�˳�)��";
			cin >> id;
			int index = this->isExist(id);

			if (id != 000 && index!=-1)
			{
				for (int i = index; i < this->m_EmpNum-1; i++)
				{
					this->m_EmpArry[i] = this->m_EmpArry[i + 1];
				}

				this->m_EmpNum--;//��һ����дΪthis->m_EmpArry--�����ᱨ���ᷢ���쳣
								 //ԭ���ǽ�����ĵ�ַ�����Լ��Ӷ��������������
				this->save();
				cout << "ɾ���ɹ���" << endl;
			}
			else if(id==000)
			{
				break;
			}
		}
	}
	else
	{
		cout << "�ļ�Ϊ�գ�" << endl;
	}

	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{

}