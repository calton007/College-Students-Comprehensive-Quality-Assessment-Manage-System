#include "Teacher.h"
#include "Student.h"
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <iostream>
Teacher::Teacher(string a, string n, string p, char i,char y) :User(a, n, p, i,y)
{
	importMoralList_t();
	importLoginList();
	display();//�������
	cout << "��ӭ��" << getAccount() << ' ' << getName() << "!���:������\n";
	system("pause");
	MainMenu();
}
void Teacher::MainMenu()
{
	vector<string> questions;
	questions.push_back("˼��Ʒ�´��");
	questions.push_back("�޸�˼��Ʒ�´��");
	questions.push_back("�޸�����");
	questions.push_back("���ص�½����");
	questions.push_back("�˳�ϵͳ");
	MultiChoiceMenu(questions);
}
void Teacher::MultiChoiceMenu(vector<string> Qs)
{
	display();//�������
	int num = Qs.size();
	for (int i = 0; i < num; ++i)
	{
		cout << '[' << i + 1 << "] " << Qs[i] << endl;
	}
	cout << "��ѡ��:";
	char choice;
	cin.sync();
	cin >> choice;//����ѡ��
	switch (choice)
	{
	case '1':gradeMoral(); break; //˼��Ʒ�´��
	case '2':modifyMoral(); break;//�޸�˼��Ʒ�´��
	case '3':modifyPassword(); MainMenu(); break;//�޸����벢�ҷ������˵�
	case '4':Save(); break;//���ص�½����
	case '5':Quit(); break;//�˳�
	default:cout << "������������,����������!" << endl;  system("pause"); MainMenu();
	}
}
void Teacher::gradeMoral()
{
	//�ж��Ƿ��Ѿ����
	if (Yes == '1')
	{
		//�Ѿ����
		cout << "�Ѵ��!" << endl;
		system("pause");
		MainMenu();
	}
	else
	{
		display();
		//û�д��
		map<string, User>::iterator iter; //��LoginList�л�ȡѧ������
		for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
		{
			if (iter->second.getIdentify() == '0')//�ж��Ƿ���ѧ��
			{
				float a[3];
				display();
				cout << "���" << (iter->second).getName() << "���" << endl;//��ȡ����
				Grade(a, 3);//����˼��Ʒ�´�ֺ���
				Moral_t temp((iter->second).getAccount(), Account, a);//������ʱ����
				MoralList_t.insert(pair<string, Moral_t>(iter->second.getAccount(), temp));//����MoralList_t
			}
		}
		cout << "������!\n";
		Yes = '1';//�޸Ķ���״̬Ϊ�Ѵ��
		LoginList[Account].modifyYes();//�޸�LoginList�ж�Ӧ�Ķ���״̬Ϊ�Ѵ��
		//��������
		exportMoralList_t();
		importMoralList_t();
		exportLoginList();
		importLoginList();
	}
	system("pause");
	MainMenu();
}
void Teacher::modifyMoral()
{
	if (Yes == '1')
	{
		multimap<string, Moral_t>::iterator iter;
		int i = 1, t = 0;
		//��ӡ
		display();
		cout << "����\t�÷���\t�����" << endl;
		for (iter = MoralList_t.begin(); iter != MoralList_t.end(); iter++)
		{
			cout << '[' << i << "]\t" << iter->second;
			i++;
			t++;//��������
		}
		while (1)
		{
			line(i, t);//�����������ж������Ƿ���ȷ
			if (i == 0)//���������Ϊ0������
				MainMenu();
			display();
			iter = MoralList_t.begin();
			for (i = i - 1; i > 0; i--, iter++);//��iterָ��Ҫ�޸ĵ��У�����Ӧ�����еĶ���
			float a[3];
			cout << "���" << searchName(iter->first) << "���" << endl;//�����˺Ż�ȡ����
			Grade(a, 3);//����˼��Ʒ�´�ֺ���
			Moral_t temp(iter->first, Account, a);//������ʱ����
			iter->second = temp;//�޸������еĶ���
			//��������
			exportMoralList_t();
			importMoralList_t();
			modify();//�����޸ģ��۲�ɼ���Ҫ��������
			cout << "�޸ĳɹ�!" << endl;
			system("pause");
			display();
			//��ӡ
			i = 1;
			cout << "\t�÷���\t�����" << endl;
			iter = MoralList_t.begin();
			for (iter = MoralList_t.begin(); iter != MoralList_t.end(); iter++)
			{
				cout << '[' << i << "]\t" << iter->second;
				i++;
			}
		}
	}
	else
	{
		cout << "˼��Ʒ��δ���!" << endl;
		system("pause");
	}
	MainMenu();
}
