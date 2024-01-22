#include "workermanager.h"
using namespace std;

WorkManager::WorkManager()
{
	//初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArry = NULL;
}

void WorkManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);//退出
}

void WorkManager::addEmp()
{
	//新添加的人数
	int addNum = 0;
	cout << "请输入添加人数：";
	cin >> addNum;
	cout << endl;

	if (addNum > 0)
	{
		//添加
		//计算需要添加的空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来数据拷贝到新的空间
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArry[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			system("cls");
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "位职工的编号：";
			cin >> id;
			cout << endl;

			cout << "请输入第" << i+1 << "位职工的姓名：";
			cin >> name;
			cout << endl;

			cout << "请输入第" << i + 1 << "位职工的部门：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

			//将创建职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArry;

		//更改新空间的指向
		this->m_EmpArry = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//写入文件

		//提示添加成功
		cout << "添加成功！" << endl;
	}
	else
	{
		cout << "输入的数量有误" << endl;
	}

	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{

}