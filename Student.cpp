#include "Student.h"
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
extern ifstream ifile;
extern ofstream ofile;

map<string, Student> Student::TotalList;
Student::Student(string a, string n, string p, char i, char y, float st, float gp, float ac, float mo, float ad, float to, int ra) :User(a, n, p, i, y)
{
	//��������
	importMoralList_s();
	importLoginList();
	importAct_List();
	study = st;
	gpa = gp;
	activity = ac;
	moral = mo;
	addition = ad;
	total = to;
	range = ra;
	display();//�������
	cout << "��ӭ��" << getAccount() << ' ' << getName() << "!���:ѧ��\n";
	system("pause");
	MainMenu();

}
Student::Student()
{
	study = 0.0;
	gpa = 0.0;
	activity = 0.0;
	moral = 0.0;
	addition = 0.0;
	total = 0.0;
	range = 0;
}
void Student::importTotalList()
{
	ifile.open("Total.txt");
	int lines=0;
	ifile >> lines;
	if (lines == 0)
	{
		map<string, User>::iterator iter;
		for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
		{
			if (iter->second.getIdentify() == '0')
			{
				Student s;
				s.modifyAccount(iter->first);
				TotalList.insert(pair<string, Student>(s.getAccount(), s));
			}
			
		}
	}
	else
	{
		int i;
		for (i = 0; i < lines; i++)
		{
			Student s;
			ifile >> s;
			TotalList.insert(pair<string, Student>(s.getAccount(), s));
		}	
	}
	ifile.close();
}
void Student::exportTotalList()
{
	ofile.open("Total.txt");
	Close(ofile);
	map<string, Student>::iterator iter;
	ofile << TotalList.size() << endl;
	for (iter = TotalList.begin(); iter != TotalList.end(); ++iter)
	{
		ofile << iter->second;
	}
	ofile.close();
}
void Student::MainMenu()
{
	vector<string> questions;
	questions.push_back("˼��Ʒ����Ŀ");
	questions.push_back("������Ŀ");
	questions.push_back("��ѯ");
	questions.push_back("�޸�����");
	questions.push_back("���ص�½����");
	questions.push_back("�˳�ϵͳ");
	(MultiChoiceMenu(questions, 0));
}
void Student::MultiChoiceMenu(vector<string> Qs, int n)
{
	display();
	int num = Qs.size();
	for (int i = 0; i < num; ++i)
	{
		cout << '[' << i + 1 << "] " << Qs[i] << endl;
	}
	cout << "��ѡ��:";
	char choice;
	cin.sync();
	cin >> choice;

	switch (n)
	{
	case 0:
		switch (choice)
		{
		case '1':Moral(); break;
		case '2':Activity(); break;
		case '3':Search(); break;
		case '4':modifyPassword(); MainMenu(); break;
		case '5':Save(); break;
		case '6':Quit(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); MainMenu(); break;
		}break;
	case 1:
		switch (choice)
		{
		case '1':gradeMoral(); break;
		case '2':modifyMoral(); break;
		case '3':MainMenu(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); Moral(); break;
		}break;
	case 2:
		switch (choice)
		{
		case '1':newActivity(); break;
		case '2':modifyActivity(); break;
		case '3':delActivity(); break;
		case '4':displayActivity(); break;
		case '5':MainMenu(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); Activity(); break;
		}break;
	case 3:
		switch (choice)
		{
		case '1':searchStudy(); break;
		case '2':searchActivity(); break;
		case '3':searchMoral(); break;
		case '4':searchAddition(); break;
		case '5':searchTotal(); break;
		case '6':searchrange(); break;
		case '7':searchall(); break;
		case '8':MainMenu(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); Search(); break;
		}break;
	}
}
void Student::Moral()
{
	vector<string> questions;
	questions.push_back("˼��Ʒ�´��");
	questions.push_back("�޸�˼��Ʒ�´��");
	questions.push_back("����");
	(MultiChoiceMenu(questions, 1));
}
void Student::gradeMoral()
{
	if (Yes == '1')
	{
		cout << "�Ѵ��!" << endl;
		system("pause");
		Moral();
	}
	else
	{
		display();
		map<string, User>::iterator iter;
		for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
		{
			if ((iter->second).getIdentify() == '0')
			{
				float a[9];
				display();
				cout << "���" << (iter->second).getName() << "���" << endl;
				Grade(a, 9);				
				Moral_s temp((iter->second).getAccount(), Account, a);
				MoralList_sget.insert(pair<string, Moral_s>(iter->second.getAccount(), temp));
			}
		}
		Yes = '1';
		LoginList[Account].modifyYes();
		exportMoralList_s();
		importMoralList_s();
		exportLoginList();
		importLoginList();
		cout << "������!" << endl;

	}
	system("pause");
	Moral();
}
void Student::modifyMoral()
{
	if (Yes == '1')
	{
		typedef multimap<string, Moral_s>::iterator Iter;
		pair<Iter, Iter> iter = MoralList_sgive.equal_range(Account);
		int i = 1, t = 1;
		display();
		cout << "����\t�÷���\t�����" << endl;
		while (iter.first != iter.second)
		{
			cout << '[' << i << "]\t" << iter.first->second;
			i++;
			iter.first++;
		}
		while (1)
		{
			line(i, t);
			if (i == 0)
				Moral();
			display();
			iter = MoralList_sgive.equal_range(Account);
			for (i = i - 1; i > 0; i--, iter.first++);
			float a[9];
			cout << "���" << searchName((iter.first->second).getAccount_get()) << "���" << endl;
			Grade(a, 9);
			Moral_s temp((iter.first->second).getAccount_get(), Account, a);
			iter.first->second = temp;
			exportMoralList_s2();
			importMoralList_s();
			modify();
			cout << "�޸ĳɹ�!" << endl;
			system("pause");
			display();
			i = 1;
			cout << "\t�÷���\t�����" << endl;
			iter = MoralList_sgive.equal_range(Account);
			while (iter.first != iter.second)
			{
				cout << '[' << i << "]\t" << iter.first->second;
				i++;
				iter.first++;
			}
		}
	}
	else
	{
		cout << "˼��Ʒ��δ��֣�" << endl;
		system("pause");
		Moral();
	}

}
void Student::Search()
{
	map<string, User>::iterator iter;
	for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
	{
		if (iter->second.getIdentify() == '2')
			break;
	}
	if (iter->second.getYes() == '0')
	{
		cout << "��δ�����۲�ɼ�,�޷���ѯ!" << endl;
		system("pause");
		MainMenu();
	}
	importTotalList();
	vector<string> questions;
	questions.push_back("��ѯѧϰ�ɼ�");
	questions.push_back("��ѯ�����ɼ�");
	questions.push_back("��ѯ˼��Ʒ�³ɼ�");
	questions.push_back("��ѯ���ӷ�");
	questions.push_back("��ѯ�۲��ܷ�");
	questions.push_back("��ѯ����");
	questions.push_back("��ѯ����");
	questions.push_back("����");
	(MultiChoiceMenu(questions, 3));
}
void Student::searchStudy()
{
	cout << "����ѧϰ�ɼ�Ϊ:" << TotalList[Account].getstudy() << endl;
	system("pause");
	Search();
}
void Student::searchGPA()
{
	cout << "����GPAΪ:" << TotalList[Account].getgpa() << endl;
	system("pause");
	Search();
}
void Student::searchActivity()
{
	cout << "���Ŀ����ɼ�Ϊ:" << TotalList[Account].getactivity() << endl;
	system("pause");
	Search();
}
void Student::searchMoral()
{
	cout << "����˼��Ʒ�³ɼ�Ϊ:" << TotalList[Account].getmoral() << endl;
	system("pause");
	Search();
}
void Student::searchAddition()
{
	cout << "���ĸ��ӷ�Ϊ:" << TotalList[Account].getaddition() << endl;
	system("pause");
	Search();
}
void Student::searchTotal()
{
	cout << "�����۲�ɼ�Ϊ:" << TotalList[Account].gettotal() << endl;
	system("pause");
	Search();
}
void Student::searchrange()
{
	cout << "��������Ϊ:" << TotalList[Account].getrange() << endl;
	system("pause");
	Search();
}
void Student::searchall()
{
	cout.flags(ios::left);
	cout<<setw(8) << "ѧ��" << setw(12) << "ѧϰ�ɼ�" << setw(7) << "gpa" << setw(14)
		<< "�����ɼ�" << setw(14) << "˼��Ʒ�³ɼ�" << setw(10) << "���ӷ�" << setw(12) 
		<< "�۲�ɼ�" << setw(8) << "����" << endl;
	cout << TotalList[Account] << endl;
	system("pause");
	Search();
}
void Student::Activity()
{
	vector<string> questions;
	questions.push_back("¼�����");
	questions.push_back("�޸Ŀ���");
	questions.push_back("ɾ������");
	questions.push_back("��ѯ����");
	questions.push_back("����");
	(MultiChoiceMenu(questions, 2));
}
void Student::newActivity()
{
	display();//��ӡ����
	string name;
	float grade;
	cout << "�����:";
	cin >> name;
	judge(grade, 4);//������������жϷ����Ƿ���ȷ
	ActAdd temp(getAccount(), name, "����", grade, "δ���");//������ʱ����
	Act_List.insert(pair<string, ActAdd>(getAccount(), temp));//��������Act_List
	modify();//�����޸ģ��۲�ɼ���Ҫ��������
	//��������
	exportAct_List();
	importAct_List();
	cout << "¼��ɹ�!" << endl;
	system("pause");
	Activity();//���ز˵�
}
void Student::delActivity()
{
	typedef multimap<string, ActAdd>::iterator Iter;
	pair<Iter, Iter> iter = Act_List.equal_range(Account);//�ҵ�ѧ��ΪAccount��Ӧ�Ŀ�����Ŀ��Ϣ
	if (iter.first != iter.second)//�ж��Ƿ��ж�Ӧ����Ϣ
	{
		int i = 1, t = 0;
		display();//��ӡ����
		//��ӡ������Ŀ��Ϣ
		cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
		while (iter.first != iter.second)
		{
			cout << setw(8) << i << iter.first->second;
			i++;
			t++;//��������
			iter.first++;
		}
		//����ɾ����ѭ��
		while (1)
		{
			line(i, t);//�������������ж�����������Ƿ���ȷ
			if (i == 0)//�������������Ϊ0�����ز˵�
				Activity();
			iter = Act_List.equal_range(Account);//�ҵ�ѧ��ΪAccount��Ӧ�Ŀ�����Ŀ��Ϣ
			for (i = i - 1; i > 0; i--, iter.first++);//��iter.firstָ����Ҫɾ������Ŀ
			//�ж�ɾ������Ŀ�Ƿ��Ѿ�ͨ����ˣ��Ѿ�ͨ����˵���Ŀ����ɾ��
			if (iter.first->second.getGet() == "δ���" || iter.first->second.getGet() == "���δͨ��")
			{
				Act_List.erase(iter.first);//ɾ��
				//��������
				exportAct_List();
				importAct_List();
				modify();//�����޸ģ��۲�ɼ���Ҫ��������
				cout << "ɾ���ɹ�!" << endl;
				system("pause");
				display();//��ӡ����
				//��ӡɾ����Ľ��
				iter = Act_List.equal_range(Account);//�ҵ�ѧ��ΪAccount��Ӧ�Ŀ�����Ŀ��Ϣ
				i = 1;
				cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
				while (iter.first != iter.second)
				{
					cout << setw(8) << i << iter.first->second;
					i++;
					iter.first++;
				}
			}
			else
			{
				cout << "�����ͨ����Ŀ����ɾ��!" << endl;
				system("pause");
			}
		}
	}
	else
	{
		cout << "û�п���ɾ������Ŀ!" << endl;
		system("pause");
		Activity();
	}
}
void Student::modifyActivity()
{
	typedef multimap<string, ActAdd>::iterator Iter;
	pair<Iter, Iter> iter = Act_List.equal_range(Account);//�ҵ�ѧ��ΪAccount��Ӧ�Ŀ�����Ŀ��Ϣ
	if (iter.first != iter.second)
	{
		int i = 1, t = 0;
		display();//��ӡ����
		//��ӡ������Ŀ��Ϣ
		cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
		while (iter.first != iter.second)
		{
			cout << setw(8) << i << iter.first->second;
			i++;
			t++;
			iter.first++;
		}
		//�����޸ĵ�ѭ��
		while (1)
		{
			line(i, t);//����������ͬʱ�ж������Ƿ���ȷ
			if (i == 0)//��������Ϊ0�����ز˵�
				Activity();
			iter = Act_List.equal_range(Account);//�ҵ�ѧ��ΪAccount��Ӧ�Ŀ�����Ŀ��Ϣ
			for (i = i - 1; i > 0; i--, iter.first++);//��iter.firstָ����Ҫɾ������Ŀ
			//�жϿ����Ƿ��Ѿ����ͨ�������ͨ������Ŀ�����޸�
			if (iter.first->second.getGet() == "δ���" || iter.first->second.getGet() == "���δͨ��")
			{
				string name;
				float grade;
				cout << "�����:";
				cin >> name;
				judge(grade, 4);//���������ͬʱ�жϷ����Ƿ���ȷ
				ActAdd temp(getAccount(), name, "����", grade, "δ���");//������ʱ����
				iter.first->second = temp;//�޸�����Act_List�ж�Ӧ����Ŀ
				//��������
				exportAct_List();
				importAct_List();
				modify();//�����޸ģ��۲�ɼ���Ҫ��������
				cout << "�޸ĳɹ�!" << endl;
				system("pause");
				display();//��ӡ����
				iter = Act_List.equal_range(Account);//�ҵ�ѧ��ΪAccount��Ӧ�Ŀ�����Ŀ��Ϣ
				i = 1;
				//��ӡ������Ŀ��Ϣ
				cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
				while (iter.first != iter.second)
				{
					cout << setw(8) << i << iter.first->second;
					i++;
					iter.first++;
				}

			}
			else
			{
				cout << "�����ͨ����Ŀ�����޸�!" << endl;
				system("pause");
			}
		}
	}
	else
	{
		cout << "û�п����޸ĵ���Ŀ!" << endl;
		system("pause");
		Activity();
	}
}
void Student::displayActivity()
{
	typedef multimap<string, ActAdd>::iterator Iter;
	pair<Iter, Iter> iter = Act_List.equal_range(Account);//�ҵ�ѧ��ΪAccount��Ӧ�Ŀ�����Ŀ��Ϣ
	if (iter.first != iter.second)//�ж��Ƿ��ж�Ӧ����Ϣ
	{
		int i = 1;
		display();//��ӡ����
		//��ӡ������Ϣ
		cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
		while (iter.first != iter.second)
		{
			cout << setw(8) << i << iter.first->second;
			i++;
			iter.first++;
		}
	}
	else
	{
		cout << "û�ж�Ӧ����Ŀ!" << endl;
	}
	system("pause");
	Activity();//���ز˵�
}
float Student::getstudy()
{
	return study;
}
float Student::getgpa()
{
	return gpa;
}
float Student::getactivity()
{
	return activity;
}
float Student::getmoral()
{
	return moral;
}
float Student::getaddition()
{
	return addition;
}
float Student::gettotal()
{
	return total;
}
int Student::getrange()
{
	return range;
}
void Student::instudy(float t)
{
	study = t;
}
void Student::ingpa(float t)
{
	gpa = t;
}
void Student::inactivity(float t)
{
	activity = t;
}
void Student::inmoral(float t)
{
	moral = t;
}
void Student::inaddition(float t)
{
	addition = t;
}
void Student::intotal()
{
	total = study*0.7f+activity*0.15f+moral*0.15f+addition;
	if (total > 100)
		total = 100;
	else
	{
		total *= 100;
		total = int(total);
		total /= 100;
	}
}
void Student::inrange(int t)
{
	range = t;
}
istream& operator>>(istream &in, Student &u)
{
	in >> u.Account >> u.study >> u.gpa >> u.activity >> u.moral >> u.addition >> u.total >> u.range;
	return in;
}
ostream& operator<<(ostream &out, const Student &u)
{
	out.flags(ios::left);
	out << setw(8) << u.Account << setw(12) << u.study << setw(7) << u.gpa << setw(14) << u.activity << setw(14) << u.moral << setw(10) << u.addition << setw(12) << u.total << setw(8) << u.range << endl;
	return out;
}


