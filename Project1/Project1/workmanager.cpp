#include "workermanager.h"
using namespace std;

WorkManager::WorkManager()
{
	//打开文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//判断存在文件但是文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())//ifs.efo()为读到文件中的第一个字符为文件尾，若为true则代表文件为空
	{
		cout << "文件存在但为空" << endl;
		//初始化属性
		this->m_EmpArry = 0;
		this->m_EmpNum = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且有记录
	int num = getEmpNum();
	this->m_EmpNum = num;
	//this->m_EmpNum = this->getEmpNum();
	cout << "有" << num << "个职工记录！" << endl;

	//创建空间
	this->m_EmpArry = new Worker * [num];
	//将文件中的数据存储到数组
	this->initArray();

	//inieArray()测试代码
	for (int i = 0; i < num; i++)
	{
		cout << "编号：" << this->m_EmpArry[i]->m_Id << " "
			<< "姓名：" << this->m_EmpArry[i]->m_Name << endl;
	}
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
		Worker** newSpace = new Worker* [newSize];

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

			while (1)
			{
				cout << "请输入第" << i + 1 << "位职工的部门：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;
				if (0 < dSelect && dSelect > 3)
				{
					cout << "输入有误,请重新输入" << endl;
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
		this->save();
		this->fileIsEmpty = false;//文件中有数据

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

void WorkManager::save()
{
	ofstream ofs;
	//打开文件
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArry[i]->m_Id << " "
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

int WorkManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);


	int age;
	string name;
	int dId;
	int num = 0;//人数
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

	int index = 0;//数组下标
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
			//cout << "职工编号：" << m_EmpArry[i]->m_Id << " "
			//	<< "职工姓名：" << m_EmpArry[i]->m_Name << " "
			//	<< "职工部门：" << m_EmpArry[i]->GetDeptName() << endl;
			this->m_EmpArry[i]->ShowInfo();
		}
	}
	else
	{
		cout << "文件为空！" << endl;
	}

	system("pause");
	system("cls");
}

int WorkManager::isExist(int id)
{
	//返回数组下标
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
			cout << "请输入你要删除的员工编号(输入000退出)：";
			cin >> id;
			int index = this->isExist(id);

			if (id != 000 && index!=-1)
			{
				for (int i = index; i < this->m_EmpNum-1; i++)
				{
					this->m_EmpArry[i] = this->m_EmpArry[i + 1];
				}

				this->m_EmpNum--;//第一次误写为this->m_EmpArry--。不会报错但会发生异常
								 //原因是将保存的地址进行自减从而可能引发的溢出
				this->save();
				cout << "删除成功！" << endl;
			}
			else if(id==000)
			{
				break;
			}
		}
	}
	else
	{
		cout << "文件为空！" << endl;
	}

	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{

}