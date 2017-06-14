#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Group.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
ifstream ifile;
ofstream ofile;

map<string, User> User::LoginList;
multimap<string, Course> User::CourseList;
multimap<string, Moral_s> User::MoralList_sget;
multimap<string, Moral_s> User::MoralList_sgive;
map<string, Moral_t> User::MoralList_t;
multimap<string, ActAdd> User::Act_List;
multimap<string, ActAdd> User::Add_List;

User::User(string a,string n,string p,char i,char y)
{
	Account = a;
	Name = n;
	Password = p;
	Identify = i;
	Yes = y;
}
void User::display()
{
	system("cls");
	cout << "*****************************************************" << endl
		<< "**                                                 **" << endl
		<< "**         ��ӭ����༶�ۺ����ʲ�������ϵͳ        **" << endl
		<< "**                                                 **" << endl
		<< "*****************************************************" << endl;
}
User User::Login()
{
	importLoginList();
	display();
	string password, account;
	while (1)
	{
		cout << "�˺�:";
		cin >> account;
		cout << "����:";
		cin >> password;
		User u = LoginList[account];
		if (password == u.getPassword())
		{
			cout << "��½�ɹ���" << endl;
			system("pause");
			return u;
		}
		else
			cout << "�û������������" << endl;
	}
}
void User::Menu(User u)
{
	switch (u.getIdentify())
	{
	case '0':
	{
		Student s(u.getAccount(), u.getName(), u.getPassword(), u.getIdentify(), u.getYes());
		break;
	}
	case '1':
	{
		Teacher t(u.getAccount(), u.getName(), u.getPassword(), u.getIdentify(), u.getYes());
		break;
	}
	case '2':
	{
		Group g(u.getAccount(), u.getName(), u.getPassword(), u.getIdentify(), u.getYes());
		break;
	}
	}
}
void User::modifyPassword()
{
	display();
	string s1, s2;
	while (1)
	{
		cout << "������ԭ����:";
		cin >> s1;
		if (s1 == Password)
			break;
		else
			cout << "ԭ����������������룡\n";
	}
	while (1)
	{
		while (1)
		{
			cout << "������������:";
			cin >> s1;
			if (s1 != Password)
				break;
			else
				cout << "��ԭ������ͬ�����������룡" << endl;
		}
		
		cout << "��������һ��:";
		cin >> s2;
		if (s1 == s2)
		{

			Password = s1;
			LoginList[this->getAccount()] = *this;
			exportLoginList();
			cout << "�޸ĳɹ���\n";
			system("pause");
			break;
		}
		else
			cout << "������������벻��ͬ�����������룡\n";
	}
}
void User::Save()
{
	exportAct_List();
	exportAdd_List();
	exportLoginList();
	exportCourseList();
	exportMoralList_s();
	exportMoralList_t();
	Menu(Login());
}
void User::Quit()
{
	exportAct_List();
	exportAdd_List();
	exportLoginList();
	exportCourseList();
	exportMoralList_s();
	exportMoralList_t();
	Student::exportTotalList();
	exit(0);
}
void User::line(int &a, const int &b)
{
	a = 0;
	//��������ѭ��
	while (1)
	{
		cout << "����������(����������0):";
		cin.sync();//������뻺����
		cin >> a;
		if (cin.rdstate() == ios::goodbit)//�������������
		{
			if (a >= 0 && a <= b)//�ж������Ƿ����Ҫ�󣨲���bΪ����������
				break;
		}
		cin.sync();//������뻺����
		cin.clear();//ʹ�������ָ�����
		cout << "��������ȷ������!" << endl;		
	}
}
void User::judge(float &f, int n)//1��ѧ�� 2:ѧϰ�ɼ� 3:���ӷ� 4:�����ɼ�
{
	bool flag = false;//��־�����Ƿ���ȷ
	while (1)
	{
		switch (n)//�ж����������
		{
		case 1:cout << "ѧ��(0.5-10):";  break;
		case 2:cout << "\n�ɼ�(0-100):"; break;
		case 3:cout << "����(0.5-5):"; break;
		case 4:cout << "����(0.5-20):"; break;
		}
		cin.sync();//������뻺����
		cin >> f;//�������
		if (cin.rdstate() == ios::goodbit)//�������������
		{
			switch (n)//�ж����������
			{
			case 1:
			{
				if (f>=0.5&&f<=10)//�ж�ѧ���Ƿ�Ϊ0.5-10֮��
					flag = true;
			}break;
			case 2:
			{
				if (f >= 0 && f <= 100)//�жϳɼ��Ƿ�Ϊ0-100֮��
					flag = true;
			}break;
			case 3:
			{
				if (f >= 0.5 && f <= 5)//�жϸ��ӷ��Ƿ�Ϊ0.5-5֮��
					flag = true;
			}break;
			case 4:
			{
				if (f >= 0.5 && f <= 20)//�жϿ����ɼ��Ƿ�Ϊ0.5-20֮��
					flag = true;
			}break;

			}
			if (flag == true)//���������ȷ������ѭ��
				break;
		}
		else
		{
			//�������쳣
			cin.sync();//������뻺����
			cin.clear();//ʹ�������ָ�����
		}
		switch (n)//�����������ͣ����������Ϣ
		{
		case 1:cout << "������0.5-10֮��ķ���!" << endl; break;
		case 2:cout << "������0-100֮��ķ���!" << endl; break;
		case 3:cout << "������0.5-5֮��ķ���!" << endl; break;
		case 4:cout << "������0.5-20֮��ķ���!" << endl; break;
		}
		cout << "����������:" << endl;

	}
}
void User::Grade(float*a, int n)
{
	//aΪ�����ֵ�����
	//n��������Ĵ�С��ͬʱ3��ʾ�����δ�֣�9��ʾѧ�����
	float t;
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			cout << "��" << i + 1 << "��(0-10)" << endl;//�����ǰ�ǵڼ���
			switch (n)
			{
			case 3://�����δ��
				switch (i + 1)
				{
				case 1:cout << "ѧ���ճ�ѧϰ������Ͽγ����ʣ�ѧϰ����̶�:"; break;
				case 2:cout << "ѧ��ƽʱ������������ɡ��������:"; break;
				case 3:cout << "ѧ�������ἰ�༶�������:"; break;
				}break;
			case 9://ѧ�����
				switch (i + 1)
				{
				case 1:cout << "�ϸ�����У��У�ͼ�ѧԺ��������ƶ�:"; break;
				case 2:cout << "�������ʵ�����ڷ�ѧϰ:"; break;
				case 3:cout << "�����ſ���ʱ�䣬��ʱ��ϰ����������Ϸ���������õ���:"; break;
				case 4:cout << "������ӽ�Լ��Ϊ�˳�ʵ����:"; break;
				case 5:cout << "ע�Ᵽ�ָ�������������������ά������:"; break;
				case 6:cout << "������ϲ��μӰ༶��ѧԺ��֯�ĸ����������θ�:"; break;
				case 7:cout << "�����μ���������:"; break;
				case 8:cout << "�����������ʣ������μӸ������ʵ�����־Ը����:"; break;
				case 9:cout << "��ʦ�������ļ��壬������ò���Ž�ͬѧ����������:"; break;
				}break;
			}
			cin.sync();//������뻺����
			cin.clear();//ʹ����������
			cin >> t;//�������
			if (cin.rdstate() == ios::goodbit)//�������������
			{
				if (t >= 0 && t <= 10)//�ж�����ķ����Ƿ�Ϊ0-10֮��
				{
					a[i] = t;//��������
					break;
				}
			}
			else
			{
				cin.sync();//������뻺����
				cin.clear();//ʹ����������
			}
			cout << "������0-10֮��ķ���!" << endl;
		}
	}
}
string User::getAccount() 
{
	return Account;
}
void User::modifyAccount(string str)
{
	Account = str;
}
string User::getPassword() 
{
	return Password;
}
string User::getName() 
{
	return Name;
}
char User::getIdentify() 
{
	return Identify;
}
char User::getYes() 
{
	return Yes;
}
void User::modifyYes()
{
	Yes = '1';
}
void User::modify()
{
	importLoginList();
	map<string, User>::iterator iter;
	for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
	{
		if (iter->second.getIdentify() == '2')
		{
			iter->second.modifyNo();
			exportLoginList();
			importLoginList();
			break;
		}
	}
}
void User::modifyNo()
{
	Yes = '0';
}
string User::searchName(string s)
{
	return LoginList[s].getName();
}
void User::importLoginList()
{
	LoginList.clear();
	ifile.open("User.txt");
	try
	{
		if (!ifile)
			throw 1;
	}
	catch (int)
	{
		cout << "�ļ�����ʧ��!" << endl;
		system("pause");
		exit(1);
	}
	int lines;
	ifile >> lines;
	int i;
	for (i = 0; i < lines; i++)
	{
		User u;
		ifile >> u;
		LoginList.insert(pair<string, User>(u.getAccount(), u));
	}
	ifile.close();
}
void User::importCourseList()
{
	CourseList.clear();
	ifile.open("Course.txt");
	int lines;
	ifile >> lines;
	int i;
	for (i = 0; i < lines; i++)
	{
		Course c;
		ifile >> c;
		CourseList.insert(pair<string, Course>(c.getAccount(), c));
	}
	ifile.close();

}
void User::importAct_List()
{
	Act_List.clear();//�������
	ifile.open("Act.txt");//���ļ�
	//������ȡ����������ļ������ڴ�ʧ�ܣ������forѭ������ִ��
	//����Ϊ�գ����Բ���Ҫ�ж��ļ��Ƿ����
	int lines;
	ifile >> lines;//���ļ��ж�������������Ϊ��¼����
	int i;
	for (i = 0; i < lines; i++)
	{
		ActAdd c;
		ifile >> c;//���ļ�����ȡ����>>������Ѿ����أ�
		Act_List.insert(pair<string, ActAdd>(c.getAccount(), c));//��������
	}
	ifile.close();//�ر��ļ�
}
void User::importAdd_List()
{
	Add_List.clear();
	ifile.open("Add.txt");
	int lines;
	ifile >> lines;
	int i;
	for (i = 0; i < lines; i++)
	{
		ActAdd c;
		ifile >> c;
		Add_List.insert(pair<string, ActAdd>(c.getAccount(), c));
	}
	ifile.close();
}
void User::importMoralList_s()
{
	MoralList_sget.clear();
	MoralList_sgive.clear();
	ifile.open("Moral_s.txt");
	int lines;
	ifile >> lines;
	int i;
	for (i = 0; i < lines; i++)
	{
		Moral_s s;
		ifile >> s;
		MoralList_sget.insert(pair<string,Moral_s>(s.getAccount_get(), s));
		MoralList_sgive.insert(pair<string, Moral_s>(s.getAccount_give(), s));
	}
	ifile.close();

}
void User::importMoralList_t()
{
	MoralList_t.clear();
	ifile.open("Moral_t.txt");
	int lines;
	ifile >> lines;
	int i;
	for (i = 0; i < lines; i++)
	{
		Moral_t s;
		ifile >> s;
		MoralList_t.insert(pair<string,Moral_t>(s.getAccount_get(), s));
	}
	ifile.close();
}
void User::exportLoginList()
{
	ofile.open("User.txt");
	Close(ofile);
	map<string, User>::iterator iter;
	ofile << LoginList.size() << endl;
	for (iter = LoginList.begin(); iter != LoginList.end(); ++iter)
	{
		ofile << iter->second;
	}
	ofile.close();
}
void User::exportCourseList()
{
	ofile.open("Course.txt");
	Close(ofile);
	multimap<string, Course>::iterator iter;
	ofile << CourseList.size() << endl;
	for (iter = CourseList.begin(); iter != CourseList.end(); ++iter)
	{
		ofile << iter->second;
	}
	ofile.close();
}
void User::exportAct_List()
{
	ofile.open("Act.txt");//���ļ�
	Close(ofile);//�ж��ļ��Ƿ�򿪳ɹ�
	multimap<string, ActAdd>::iterator iter;
	ofile << Act_List.size() << endl;//�����¼��
	//��������еļ�¼
	for (iter = Act_List.begin(); iter != Act_List.end(); ++iter)
	{
		ofile << iter->second; //<<�����������
	}
	ofile.close();//�ر��ļ�
}
void User::exportAdd_List()
{
	ofile.open("Add.txt");
	Close(ofile);
	multimap<string, ActAdd>::iterator iter;
	ofile << Add_List.size() << endl;
	for (iter = Add_List.begin(); iter != Add_List.end(); ++iter)
	{
		ofile << iter->second;
	}
	ofile.close();
}
void User::exportMoralList_s()
{
	ofile.open("Moral_s.txt");
	Close(ofile);
	multimap<string, Moral_s>::iterator iter;
	ofile << MoralList_sget.size() << endl;
	for (iter = MoralList_sget.begin(); iter != MoralList_sget.end(); ++iter)
	{
		ofile << iter->second;
	}
	ofile.close();
}
void User::exportMoralList_s2()
{
	ofile.open("Moral_s.txt");
	Close(ofile);
	multimap<string, Moral_s>::iterator iter;
	ofile << MoralList_sgive.size() << endl;
	for (iter = MoralList_sgive.begin(); iter != MoralList_sgive.end(); ++iter)
	{
		ofile << iter->second;
	}
	ofile.close();
}
void User::exportMoralList_t()
{
	ofile.open("Moral_t.txt");
	Close(ofile);
	map<string, Moral_t>::iterator iter;
	ofile << MoralList_t.size() << endl;
	for (iter = MoralList_t.begin(); iter != MoralList_t.end(); ++iter)
	{
		ofile << iter->second;
	}
	ofile.close();
}
istream& operator>>(istream &in, User &u)
{
	in >> u.Account >> u.Name >> u.Password >> u.Identify >> u.Yes;
	return in;
}
ostream& operator<<(ostream &out, const User &u)
{
	out << u.Account << '\t' << u.Name << '\t' << u.Password << '\t' << u.Identify << '\t' << u.Yes << endl;
	return out;
}

void User::Close(ofstream &o)
{
	try
	{
		if (!o)//�ж��ļ��Ƿ�򿪳ɹ�
			throw 1;//�򿪲��ɹ����׳��쳣
	}
	catch (int)//�����쳣
	{
		cout << "�ļ���ʧ��!" << endl;
		system("pause");
		exit(1);//�˳�����
	}
}

