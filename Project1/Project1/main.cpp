//���ڶ�̬��ְ������ϵͳ
//��˾��ְ����Ϊ���ࣺ��ͨԱ���������ϰ壬��ʾ��Ϣʱ����Ҫ��ʾְ����š�ְ��������ְ����λ���Լ�ְ��
//��ͨԱ��ְ����ɾ�����������
//����ְ������ϰ彻�������񣬲��·������Ա��
//�ϰ�ְ�𣺹���˾��������

//����ϵͳ����Ҫʵ�ֵĹ������£�
//- �˳���������˳���ǰ����ϵͳ
//- ����ְ����Ϣ��ʵ���������ְ�����ܣ�����Ϣ¼�뵽�ļ��У�ְ����ϢΪ��ְ����š����������ű��
//- ��ʾְ����Ϣ����ʾ��˾�ڲ�����ְ������Ϣ
//- ɾ����ְְ�������ձ��ɾ��ָ����ְ��
//- �޸�ְ����Ϣ�����ձ���޸�ְ��������Ϣ
//- ����ְ����Ϣ������ְ���ı�Ż���ְ�����������в�����ص���Ա��Ϣ
//- ���ձ�����򣺰���ְ����ţ�������������������û�ָ��
//- ��������ĵ�������ļ��м�¼������ְ����Ϣ �����ǰ��Ҫ�ٴ�ȷ�ϣ���ֹ��ɾ��

#include <iostream>
using namespace std;
#include "workermanager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main()
{
	////���Դ���
	//Employee* worker1 = NULL;
	//worker1 = new Employee(1, "����", 1);
	//worker1->ShowInfo();

	//Manager* worker2 = NULL;
	//worker2 = new Manager(2, "����", 1);
	//worker2->ShowInfo();

	//Boss* worker3 = NULL;
	//worker3 = new Boss(3, "����", 1);
	//worker3->ShowInfo();

	WorkManager wm;

	//��¼�û�����
	int choice;

	while (1)
	{
		wm.ShowMenu();

		cout << "����������ѡ��";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 0:wm.ExitSystem(); //�˳�ϵͳ
			break;
		case 1:wm.addEmp(); //����Ա����Ϣ
			break;
		case 2:; //��ʾְ����Ϣ
			break;
		case 3:; //ɾ����ְְ��
			break;
		case 4:; //�޸�ְ����Ϣ
			break;
		case 5:; //����ְ����Ϣ
			break;
		case 6:; //���ձ������
			break;
		case 7:; //��������ĵ�
			break;
		default:system("cls"); //����
			break;
		}

	}

	system("pause");

	return 0;
}
