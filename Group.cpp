#include "Group.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
typedef map<string, Student> StudentMap;
Group::Group(string a, string n, string p, char i,char y) :User(a, n, p, i,y)
{
	//��������
	importCourseList();
	importMoralList_s();
	importMoralList_t();
	importLoginList();
	importAct_List();
	importAdd_List();
	Student::importTotalList();
	display();//�������
	cout << "��ӭ��" << getAccount() << ' ' << getName() << "!���:����С���Ա\n";
	system("pause");
	MainMenu();
}
void Group::MainMenu()
{
	vector<string> questions;
	questions.push_back("ѧϰ�ɼ�����");
	questions.push_back("���ӷֹ���");
	questions.push_back("��˿����ӷ�");
	questions.push_back("��ѯ��Ŀ");
	questions.push_back("�۲�ɼ�����");
	questions.push_back("�޸�����");
	questions.push_back("���ص�½����");
	questions.push_back("�˳�ϵͳ");
	MultiChoiceMenu(questions, 0);
}
void Group::MultiChoiceMenu(vector<string> Qs, int n)
{
	display();//�������
	int num = Qs.size();
	for (int i = 0; i < num; ++i)
	{
		cout << '[' << i + 1 << "] " << Qs[i] << endl;
	}
	cout << "��ѡ��:";
	cin.sync();
	char choice;
	cin >> choice;//����ѡ��
	//n��ʾ�˵����� choice��ʾ�˵�ѡ��
	switch (n)
	{
	case 0:
		switch (choice)
		{
		case '1': study(); break;
		case '2': addition(); break;
		case '3': checkActivity(); break;
		case '4': search(); break;
		case '5': buildTotal(); break;
		case '6': modifyPassword(); MainMenu(); break;
		case '7': Save(); break;
		case '8': Quit(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); MainMenu(); break;
		}break;
	case 1:
		switch (choice)
		{
		case '1': newStudy(); break;
		case '2': modifyStudy(); break;
		case '3': delStudy(); break;
		case '4': MainMenu(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); study(); break;
		}break;
	case 2:
		switch (choice)
		{
		case '1': newAddition(); break;
		case '2': modifyAddition(); break;
		case '3': delAddition(); break;
		case '4': MainMenu(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); addition(); break;
		}break;
	case 4:
		switch (choice)
		{
		case '1': searchGPA(); break;
		case '2': searchStudy(); break;
		case '3': searchActivity(); break;
		case '4': searchMoral(); break;
		case '5': searchAddition(); break;
		case '6': searchTotal(); break;
		case '7': searchall(); break;
		case '8': MainMenu(); break;
		default:cout << "������������,����������!" << endl;  system("pause"); search(); break;
		}break;
	}
}
void Group::study()
{	
	vector<string> questions;
	questions.push_back("¼��ѧϰ�ɼ�");
	questions.push_back("�޸�ѧϰ�ɼ�");
	questions.push_back("ɾ��ѧϰ�ɼ�");
	questions.push_back("����");
	(MultiChoiceMenu(questions, 1));
}
void Group::newStudy()
{
	string str, str2;
	float n, m;
	string f;
	display();
	cout << "1:����¼��ɼ� 2:����¼��ɼ� ����:����" << endl;//���ѡ��
	cin.sync();
	cout << "��ѡ��:";
	cin >> f;//����ѡ��
	//�ж������ѡ��
	if (f == "2")
	{
		display();
		//����¼��ɼ�
		while (1)
		{
			cout << "¼��ѧ����ѧ��:";
			cin >> str;
			if (exist(str)) //�ж������ѧ�Ŷ�Ӧ��ѧ���Ƿ����
				break;
		}		
		while (1)
		{
			display();
			cout << "¼��<" << searchName(str) << ">�ĳɼ�" << endl;//��ȡѧ������
			cout << "�γ���:";
			cin >> str2;
			judge(n, 1);//����ѧ�֣��ж�ѧ���Ƿ���ȷ
			judge(m, 2);//����ɼ����жϳɼ��Ƿ���ȷ
			Course c(str, str2, n, m);//����Course�����
			CourseList.insert(pair<string, Course>(str, c));//����CourseList
			//��������
			exportCourseList();
			importCourseList();
			modify();//�����޸ģ��۲�ɼ���Ҫ��������
			cout << "¼��ɹ�!" << endl;
			system("pause");
			display();
			cout << "1:����¼�� ����:¼�����" << endl;
			cout << "��ѡ��:";
			cin.sync();
			cin >> f;
			//�ж��Ƿ����¼��
			if (f != "1")
				break;			
		}
	}
	if (f == "1")
	{
		display();
		//����¼��ɼ�
		map<string, User>::iterator iter;
		while (1)
		{
			display();
			cout << "�γ���:";
			cin >> str2;
			judge(n, 1);//����ѧ�֣��ж�ѧ���Ƿ���ȷ
			for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
			{
				if (iter->second.getIdentify() == '0')
				{
					cout << iter->second.getName() << "�ĳɼ�:";//��ȡ����
					judge(m, 2);//����ɼ����ж�ѧ�ֳɼ��Ƿ���ȷ
					Course c(iter->first, str2, n, m);//������ʱ����
					CourseList.insert(pair<string, Course>(iter->first, c));//����CourseList				
				}
			}
			//��������
			exportCourseList();
			importCourseList();
			modify();//�����޸ģ��۲�ɼ���Ҫ��������
			cout << "¼��ɹ�!" << endl;
			system("pause");
			display();
			cout << "1:��������¼�� ����:¼�����" << endl;
			cout << "��ѡ��:";
			cin.sync();
			cin >> f;
			//�ж��Ƿ����¼��
			if (f != "1")
				break;
		}
	}
	//��������ѡ���򷵻ز˵�
	system("pause");
	study();
}
void Group::delStudy()
{
	//�ж��Ƿ��п���ɾ������Ŀ
	if (CourseList.size() > 0)
	{
		display();
		multimap<string, Course>::iterator iter;
		string account;
		//��ӡ
		int i = 1,t=0;
		cout <<setw(8)<<"�к�"<< setw(10) << "ѧ��" << setw(20) << "�γ���" << setw(8) << "ѧ��" << setw(8) << "�ɼ�" <<endl;
		for (iter = CourseList.begin(); iter != CourseList.end(); iter++)
		{
			cout << setw(8) << i << iter->second;
			i++;
			t++;//����������
		}
		while (1)
		{
			line(i, t);//������Ҫɾ�����������ж������Ƿ���ȷ
			if (i == 0)//�������Ϊ0���򷵻�
				study();
			iter = CourseList.begin();
			for (i = i - 1; i > 0; i--, iter++);//��iterָ��Ҫɾ���Ķ���
			CourseList.erase(iter);//ɾ��
			//����
			exportCourseList();
			importCourseList();
			modify();//�����޸ģ��۲�ɼ���Ҫ��������
			cout << "ɾ���ɹ�!" << endl;
			system("pause");
			display();
			//��ӡ
			iter = CourseList.begin();
			i = 1;
			cout << setw(8) << "�к�" << setw(10) << "ѧ��" << setw(20) << "�γ���" << setw(8) << "ѧ��" << setw(8) << "�ɼ�" << endl;
			for (iter = CourseList.begin(); iter != CourseList.end(); iter++)
			{
				cout << setw(8) << i << iter->second;
				i++;
			}
		}
	}
	else
		cout << "û�п���ɾ������Ŀ!" << endl;
	system("pause");
	study();
}
void Group::modifyStudy()
{
	//�ж��Ƿ��п����޸ĵ���Ŀ
	if (CourseList.size() > 0)
	{
		display();
		multimap<string, Course>::iterator iter;
		string account, name;
		float credit, grade;
		//��ӡ
		int i = 1,t=0;
		cout << setw(8) << "�к�" << setw(10) << "ѧ��" << setw(20) << "�γ���" << setw(8) << "ѧ��" << setw(8) << "�ɼ�" << endl;
		for (iter = CourseList.begin(); iter != CourseList.end(); iter++)
		{
			cout << setw(8) << i << iter->second;
			i++;
			t++;//��������
		}
		while (1)
		{
			line(i, t);//������Ҫ�޸ĵ������������ж��Ƿ���ȷ
			if (i == 0)//�������0���򷵻�
				study();
			iter = CourseList.begin();
			for (i = i - 1; i > 0; i--, iter++);
			while (1)
			{
				cout << "ѧ��:";
				cin >> account;
				if (exist(account))//�ж������ѧ�Ŷ�Ӧ��ѧ���Ƿ����
					break;
				else
					cout << "û��ѧ��Ϊ" << account << "��ѧ��!" << endl;
			}
			cout << "�γ���:";
			cin >> name;
			judge(credit, 1);//����ѧ�֣������ж��Ƿ���ȷ
			judge(grade, 2);//����ɼ��������ж��Ƿ���ȷ
			Course temp(account, name, credit, grade);//������ʱ����
			iter->second = temp;//�޸�CourseList�ж�Ӧ�Ķ���
			//��������
			exportCourseList();
			importCourseList();
			modify();//�����޸ģ��۲�ɼ���Ҫ��������
			cout << "�޸ĳɹ�!" << endl;
			system("pause");
			display();
			//��ӡ
			iter = CourseList.begin();
			i = 1;
			cout << setw(8) << "�к�" << setw(10) << "ѧ��" << setw(20) << "�γ���" << setw(8) << "ѧ��" << setw(8) << "�ɼ�" << endl;
			for (iter = CourseList.begin(); iter != CourseList.end(); iter++)
			{
				cout << setw(8) << i << iter->second;
				i++;
			}
		}
	}
	else
		cout << "û�п����޸ĵ���Ŀ!" << endl;
	system("pause");
	study();
}
void Group::addition()
{
	vector<string> questions;
	questions.push_back("¼�븽�ӷ�");
	questions.push_back("�޸ĸ��ӷ�");
	questions.push_back("ɾ�����ӷ�");
	questions.push_back("����");
	(MultiChoiceMenu(questions, 2));
}
void Group::newAddition()
{
	display();
	string i;
	string name;
	float grade;
	cout << "1:¼�뼯����Ŀ 2:¼�������Ŀ ����:����" << endl;
	cout << "��ѡ��:";
	cin.sync();
	cin >> i;
	
	//¼�뼯����Ŀ
	if (i == "1")
	{
		display();
		map<string, User>::iterator iter;
		cout << "��Ŀ����:";
		cin >> name;
		judge(grade, 3);//���븽�ӷ֣������ж��Ƿ���ȷ
		for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
		{
			if (iter->second.getIdentify() == '0')
			{
				ActAdd temp(iter->second.getAccount(), name, "���ӷ�", grade, "���ͨ��");//������ʱ����
				Add_List.insert(pair<string, ActAdd>(getAccount(), temp));//����Add_List
			}
		}
		//��������
		exportAdd_List();
		importAdd_List();
		modify();//�����޸ģ��۲�ɼ���Ҫ��������
		cout << "¼��ɹ�!" << endl;
	}
	//¼�������Ŀ
	if (i == "2")
	{
		display();
		string account;
		while (1)
		{
			cout << "ѧ��:";
			cin >> account;
			if (exist(account))//�ж�ѧ�Ŷ�Ӧ��ѧ���Ƿ����
				break;
		}

		cout << "��Ŀ����:";
		cin >> name;
		judge(grade, 3);//���븽�ӷ֣��ж�������Ƿ���ȷ
		ActAdd temp(account, name, "���ӷ�", grade, "���ͨ��");//������ʱ����
		Add_List.insert(pair<string, ActAdd>(account, temp));//����Add_List��
		//��������
		exportAdd_List();
		importAdd_List();
		modify();//�����޸ģ��۲�ɼ���Ҫ��������
		cout << "¼��ɹ�!" << endl;
	}
	system("pause");
	addition();
}
void Group::modifyAddition()
{
	if (Add_List.size() > 0)
	{
		display();
		multimap<string, ActAdd>::iterator iter;
		string account, name;
		int i = 1, t = 0;
		cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
		for (iter = Add_List.begin(); iter != Add_List.end(); iter++)
		{
			cout << setw(8) << i << iter->second;
			i++;
			t++;
		}
		while (1)
		{
			line(i, t);
			if (i == 0)
				addition();
			iter = Add_List.begin();
			for (i = i - 1; i > 0; i--, iter++);
			float grade;
			cout << "ѧ��:";
			cin >> account;
			cout << "��Ŀ����:";
			cin >> name;
			judge(grade, 3);
			ActAdd temp(account, name, "���ӷ�", grade, "���ͨ��");
			iter->second = temp;
			exportAdd_List();
			importAdd_List();
			modify();
			cout << "�޸ĳɹ�!" << endl;
			system("pause");
			display();
			iter = Add_List.begin();
			i = 1;
			cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
			for (iter = Add_List.begin(); iter != Add_List.end(); iter++)
			{
				cout << setw(8) << i << iter->second;
				i++;
			}
		}

	}
	else
		cout << "û�п����޸ĵ���Ŀ!" << endl;
	system("pause");
	addition();
}
void Group::delAddition()
{
	if (Add_List.size() > 0)
	{
		display();
		multimap<string, ActAdd>::iterator iter;
		string account;
		int i = 1, t = 0;
		cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
		for (iter = Add_List.begin(); iter != Add_List.end(); iter++)
		{
			cout << setw(8) << i << iter->second;
			i++;
			t++;
		}
		while (1)
		{
			line(i, t);
			if (i == 0)
				addition();
			display();
			iter = Add_List.begin();
			for (i = i - 1; i > 0; i--, iter++);
			Add_List.erase(iter);
			exportAdd_List();
			importAdd_List();
			modify();
			cout << "ɾ���ɹ�!" << endl;
			system("pause");
			display();
			iter = Add_List.begin();
			i = 1;
			cout << setw(8) << "����" << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
			for (iter = Add_List.begin(); iter != Add_List.end(); iter++)
			{
				cout << setw(8) << i << iter->second;
				i++;
			}
		}

	}
	cout << "û�п���ɾ������Ŀ!" << endl;
	system("pause");
	addition();
}
void Group::buildMoral()
{
	Student::importTotalList();
	typedef multimap<string, Moral_s>::iterator Iter;
	pair<Iter, Iter> iter1;
	map<string, User>::iterator iter2;
	multimap<float, string> temp;
	map<float, string>::reverse_iterator iter3;

	float sum = 0.0;
	int n = 0;
	string str;
	for (iter2 = LoginList.begin(); iter2 != LoginList.end(); iter2++)
	{
		if (iter2->second.getYes() == '0'&&iter2->second.getIdentify() != '2')
		{
			n++;
			cout << searchName(iter2->first) << ' ';
		}
	}
	if (n != 0)
	{
		cout << "˼��Ʒ��δ���!" << endl;
		system("pause");
		MainMenu();
	}
	for (iter2 = LoginList.begin(); iter2 != LoginList.end(); iter2++)
	{
		if (iter2->second.getIdentify() == '0')
		{
			iter1 = MoralList_sget.equal_range(iter2->first);
			while (iter1.first != iter1.second)
			{
				sum += (iter1.first->second.getsum());
				n += 10;
				iter1.first++;
			}
			sum += (MoralList_t[iter2->first].getsum());
			sum /= (n + 3);
			
			temp.insert(pair<float, string>(sum, iter2->first));
		}

		sum = 0.0;
		n = 0;
	}

	float s = 100;

	for (iter3 = temp.rbegin(); iter3 != temp.rend(); iter3++, s--)
	{

		Student stu = Student::TotalList[iter3->second];
		stu.inmoral(s);
		Student::TotalList[iter3->second] = stu;
	}

	Student::exportTotalList();
	Student::importTotalList();

}
void Group::checkActivity()
{
	multimap<string, ActAdd>::iterator iter;
	ActAdd temp;
	int i = 0, t;
	string ch;
	//�ж��ж��ٿ�����Ŀδ���
	for (iter = Act_List.begin(); iter != Act_List.end(); iter++)
	{
		if (iter->second.getGet() == "δ���")
			i++;
	}
	if (i > 0)//����п���δ���
	{
		//��˹���
		t = i;
		for (iter = Act_List.begin(); iter != Act_List.end(); iter++)
		{
			display();//��ӡ����				
			cout << "����<" << t << ">��δ���" << endl;//��ӡʣ���δ�������
			if (iter->second.getGet() == "δ���")//�ҵ�δ��˵���Ŀ
			{
				//���δ��˵���Ŀ
				
				cout << setw(10) << "ѧ��" << setw(20) << "���" << setw(12) << "����" << setw(8) << "����" << setw(14) << "״̬" << endl;
				cout << iter->second;
				temp = iter->second;//�������еĶ���ֵ����ʱ����
				while (1)
				{
					cout << "1:���ͨ��  2:���δͨ��" << endl;
					cout << "��ѡ��:";
					cin.sync();//������뻺����
					cin >> ch;//����ѡ��
					if (ch == "1")
					{
						temp.modifyGet(1);//�޸���ʱ����Ϊ���ͨ��
						break;
					}
					if (ch == "2")
					{
						temp.modifyGet(2);//�޸���ʱ����Ϊ���δͨ��
						break;
					}
					cout << "������������!" << endl;
				}
				iter->second = temp;//�޸������ж�Ӧ�Ķ���
				cout << "�����ɹ�" << endl;
				system("pause");
				t--;//ʣ����Ŀ����1
			}
		}
		//����
		exportAct_List();
		importAct_List();
	}
	else
	{
		cout << "û����Ҫ��˵���Ŀ" << endl;
		system("pause");
	}
	
	MainMenu();
}
void Group::buildActivity()
{
	Student::importTotalList();
	map<string, User>::iterator iter1;
	typedef multimap<string, ActAdd>::iterator Iter;
	pair<Iter, Iter> iter2;
	multimap<string, ActAdd>::iterator iter3;
	int i = 0;
	for (iter3 = Act_List.begin(); iter3 != Act_List.end(); iter3++)
	{
		if (iter3->second.getGet() == "δ���")
			i++;
	}
	if (i != 0)
	{
		cout << "����δ��˵Ŀ����������!" << endl;
		system("pause");
		checkActivity();
	}
	float sum = 0.0;
	for (iter1 = LoginList.begin(); iter1 != LoginList.end(); iter1++)
	{
		if (iter1->second.getIdentify() == '0')
		{
			iter2 = Act_List.equal_range(iter1->first);
			while (iter2.first != iter2.second)
			{
				sum += iter2.first->second.getGrade();
				iter2.first++;
			}
			Student::TotalList[iter1->first].inactivity(sum);
			sum = 0.0;
		}
	}
	Student::exportTotalList();
	Student::importTotalList();
}
void Group::buildAddition()
{
	Student::importTotalList();
	map<string, User>::iterator iter1;
	typedef multimap<string, ActAdd>::iterator Iter;
	pair<Iter, Iter> iter2;
	multimap<string, ActAdd>::iterator iter3;
	float sum = 0.0;
	for (iter1 = LoginList.begin(); iter1 != LoginList.end(); iter1++)
	{
		if (iter1->second.getIdentify() == '0')
		{
			iter2 = Add_List.equal_range(iter1->first);
			while (iter2.first != iter2.second)
			{
				sum += iter2.first->second.getGrade();
				iter2.first++;
			}
			if (sum > 5)
				sum = 5;
			Student temp = Student::TotalList[iter1->first];
			temp.inaddition(sum);
			Student::TotalList[iter1->first] = temp;
			sum = 0.0;
		}
	}
	Student::exportTotalList();
	Student::importTotalList();
}
void Group::getGPA()
{
	Student::importTotalList();
	importCourseList();
	map<string, User>::iterator iter;
	typedef multimap<string, Course>::iterator Iter;
	for (iter = LoginList.begin(); iter != LoginList.end(); iter++)
	{
		if (iter->second.getIdentify() == '0')
		{
			pair<Iter, Iter> iter2 = CourseList.equal_range(iter->second.getAccount());
			float gpa = 0.0, gredit = 0.0;
			while (iter2.first != iter2.second)
			{
				float a = iter2.first->second.getGrade();
				float b = iter2.first->second.getCredit();
				if (a <= 100 && a >= 90)
				{
					gredit += b;
					gpa += b*4.0f;
				}
				if (a < 90 && a >= 85)
				{
					gredit += b;
					gpa += b*3.7f;
				}
				if (a < 85 && a >= 82)
				{
					gredit += b;
					gpa += b*3.3f;
				}
				if (a <82 && a >= 78)
				{
					gredit += b;
					gpa += b*3.0f;
				}
				if (a <78 && a >= 75)
				{
					gredit += b;
					gpa += b*2.7f;
				}
				if (a <75 && a >= 72)
				{
					gredit += b;
					gpa += b*2.3f;
				}
				if (a <72 && a >= 68)
				{
					gredit += b;
					gpa += b*2.0f;
				}
				if (a <68 && a >= 64)
				{
					gredit += b;
					gpa += b*1.5f;
				}
				if (a <64 && a >= 60)
				{
					gredit += b;
					gpa += b*1.0f;
				}
				if (a < 60){
					gredit += b;
					gpa += 0.0f;
				}
				iter2.first++;
			}
			if (gredit != 0.0)
			{
				gpa /= gredit;
				gpa*=100;
				gpa = int(gpa);
				gpa /= 100;
				Student::TotalList[iter->second.getAccount()].ingpa(gpa);
			}
			else
				Student::TotalList[iter->second.getAccount()].ingpa(0.0);

		}
		float gpa = 0.0;
		float gredit = 0.0;
	}
	Student::exportTotalList();
	Student::importTotalList();
}
void Group::buildStudy()
{	
	Student::importTotalList();
	getGPA();
	map<string, Student>::iterator iter;
	float gpa=0.0;
	for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
	{
		gpa = iter->second.getgpa();
		gpa *= 25;
		gpa *= 100;
		gpa = int(gpa);
		gpa /= 100;
		iter->second.instudy(gpa);
		gpa = 0.0;
	}
	Student::exportTotalList();
	Student::importTotalList();
}
void Group::buildTotal()
{
	buildMoral();
	buildActivity();
	buildAddition();
	buildStudy();
	Student::importTotalList();
	map<string, Student>::iterator iter;
	multimap<float, Student> rank;
	float sum = 0.0;
	for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
	{
		Student temp = iter->second;
		temp.intotal();
		iter->second = temp;
		rank.insert(pair<float, Student>(temp.gettotal(), temp));
	}
	ofstream ofile;
	ofile.open("Total.txt");
	Close(ofile);
	multimap<float, Student>::iterator iter2;
	ofile << rank.size() << endl;
	int i=rank.size();
	for (iter2 = rank.begin(); iter2 != rank.end(); ++iter2,i--)
	{
		iter2->second.inrange(i);
		ofile << iter2->second;
	}
	ofile.close();
	LoginList[Account].modifyYes();
	exportLoginList();
	importLoginList();
	Student::importTotalList();
	cout << "���ɳɹ���"<<endl;
	system("pause");
	MainMenu();
}
void Group::search()
{
	if (LoginList[Account].getYes() == '0')
	{
		cout << "��δ�����۲�ɼ�,�޷���ѯ!" << endl;
		system("pause");
		MainMenu();
	}
	Student::importTotalList();
	vector<string> questions;
	questions.push_back("��ѯGPA");
	questions.push_back("��ѯѧϰ�ɼ�");
	questions.push_back("��ѯ�����ɼ�");
	questions.push_back("��ѯ˼��Ʒ�³ɼ�");
	questions.push_back("��ѯ���ӷ�");
	questions.push_back("��ѯ�۲�ɼ�");
	questions.push_back("��ѯ����");
	questions.push_back("����");
	(MultiChoiceMenu(questions, 4));
}
void Group::searchStudy()
{
	string f;
	display();
	cout << "1:��ѯȫ�� 2:��ѯ����ѧ�� ����:����" << endl;
	
	cout << "��ѡ��:";
	cin.sync();
	cin >> f;
	display();
	if (f == "1")
	{
		cout << setw(20) << "����" << setw(8) << "ѧϰ�ɼ�" << endl;
		map<string, Student>::iterator iter;
		for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
		{
			cout << setw(20) << searchName(iter->first) <<setw(8)<< iter->second.getstudy()<<endl;
		}

	}
	if (f == "2")
	{
		string s;
		cout << "�������ѯ��ѧ��(����������0):";
		cin >> s;
		if (s == "0")
			search();
		if (exist(s))
		{
			cout << searchName(s) << "��ѧϰ�ɼ�Ϊ:" << Student::TotalList[s].getstudy() << endl;
		}
	}
	system("pause");
	search();
}
void Group::searchGPA()
{
	string f;
	display();
	cout << "1:��ѯȫ�� 2:��ѯ����ѧ�� ����:����" << endl;
	cin.sync();
	cout << "��ѡ��:";
	cin >> f;
	display();
	if (f == "1")
	{
		cout << setw(20) << "����" << setw(7) << "GPA" << endl;
		map<string, Student>::iterator iter;
		for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
		{
			cout << setw(20) << searchName(iter->first) << setw(7) << iter->second.getgpa() << endl;
		}

	}
	if (f == "2")
	{
		string s;
		cout << "�������ѯ��ѧ��(����������0):";
		cin >> s;
		if (s == "0")
			search();
		if (exist(s))
		{
			cout << searchName(s) << "��GPAΪ:" << Student::TotalList[s].getgpa() << endl;
		}
	}
	system("pause");
	search();
}
void Group::searchActivity()
{
	string f;
	display();//��ӡ����
	cout << "1:��ѯȫ�� 2:��ѯ����ѧ�� ����:����" << endl;
	cin.sync();
	cout << "��ѡ��:";
	cin >> f;
	display();//��ӡ����
	if (f == "1")//��ѯȫ��
	{
		//�������
		cout << setw(20) << "����" << setw(16) << "�����ɼ�" << endl;
		map<string, Student>::iterator iter;
		//��ӡ����ѧ���ɼ�
		for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
		{
			cout << setw(20) << searchName(iter->first) << setw(16) << iter->second.getactivity() << endl;
		}

	}
	if (f == "2")//��ѯ����ѧ��
	{
		string s;
		cout << "�������ѯ��ѧ��(����������0):";
		cin >> s;
		if (s == "0")//�������0�����ز˵�
			search();
		if (exist(s))//�ж������ѧ���Ƿ���ڣ��Ƿ���ѧ��
		{
			cout << searchName(s) << "�Ŀ����ɼ�Ϊ:" << Student::TotalList[s].getactivity() << endl;
		}
	}
	system("pause");
	search();//���ز˵�
}
void Group::searchMoral()
{
	string f;
	display();
	cout << "1:��ѯȫ�� 2:��ѯ����ѧ�� ����:����" << endl;
	cin.sync();
	cout << "��ѡ��:";
	cin >> f;
	display();
	if (f == "1")
	{
		cout << setw(20) << "����" << setw(16) << "˼��Ʒ�³ɼ�" << endl;
		map<string, Student>::iterator iter;
		for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
		{
			cout << setw(20) << searchName(iter->first) << setw(16) << iter->second.getmoral() << endl;
		}

	}
	if (f == "2")
	{
		string s;
		cout << "�������ѯ��ѧ��(����������0):";
		cin >> s;
		if (s == "0")
			search();
		if (exist(s))
		{
			cout << searchName(s) << "��˼��Ʒ�³ɼ�Ϊ:" << Student::TotalList[s].getmoral() << endl;
		}
	}
	system("pause");
	search();
}
void Group::searchAddition()
{
	string f;
	display();
	cout << "1:��ѯȫ�� 2:��ѯ����ѧ�� ����:����" << endl;
	cin.sync();
	cout << "��ѡ��:";
	cin >> f;
	display();
	if (f == "1")
	{
		cout << setw(20) << "����" << setw(10) << "���ӷ�" << endl;
		map<string, Student>::iterator iter;
		for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
		{
			cout << setw(20) << searchName(iter->first) << setw(10) << iter->second.getaddition() << endl;
		}

	}
	if (f == "2")
	{
		string s;
		cout << "�������ѯ��ѧ��(����������0):";
		cin >> s;
		if (s == "0")
			search();
		if (exist(s))
		{
			cout << searchName(s) << "�ĸ��ӷ�Ϊ:" << Student::TotalList[s].getaddition() << endl;
		}
	}
	system("pause");
	search();
}
void Group::searchTotal()
{
	string f;
	display();
	cout << "1:��ѯȫ�� 2:��ѯ����ѧ�� ����:����" << endl;
	cin.sync();
	cout << "��ѡ��:";
	cin >> f;
	display();
	if (f == "1")
	{
		cout << setw(20) << "����" << setw(12) << "�۲�ɼ�" << endl;
		map<string, Student>::iterator iter;
		for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
		{
			cout << setw(20) << searchName(iter->first) << setw(12) << iter->second.gettotal() << endl;
		}

	}
	if (f == "2")
	{
		string s;
		cout << "�������ѯ��ѧ��(����������0):";
		cin >> s;
		if (s == "0")
			search();
		if (exist(s))
		{
			cout << searchName(s) << "���۲�ɼ�Ϊ:" << Student::TotalList[s].gettotal() << endl;
		}
	}
	system("pause");
	search();
}
void Group::searchall()
{
	display();
	cout <<setw(10) <<"����"<< setw(8) << "ѧ��" << setw(12) << "ѧϰ�ɼ�" << setw(7) << "GPA" << setw(14)
		<< "�����ɼ�" << setw(14) << "˼��Ʒ�³ɼ�" << setw(10) << "���ӷ�" << setw(12)
		<< "�۲�ɼ�" << setw(8) << "����" << endl;
	map<string, Student>::iterator iter;
	for (iter = Student::TotalList.begin(); iter != Student::TotalList.end(); iter++)
	{		
		cout <<setw(10)<<searchName(iter->first)<< iter->second;
	}
	system("pause");
	search();
}
bool Group::exist(string s)
{
	//��LoginList�û���Ϣ�в��ң��ж��Ƿ�Ϊѧ��
	if (LoginList[s].getIdentify() != '0')//����ѧ��
	{
		//�ж��Ƿ�Ϊ�����κͲ���С��
		if (LoginList[s].getIdentify() != '1'&&LoginList[s].getIdentify() != '2')
			LoginList.erase(s);//������ǣ�ɾ��
		//�������ԣ�ִ��LoginList[s]����ʱ������������в��Ҳ���
		//���������������һ��������û���Ϣ�����³���������Ҫɾ��
		cout << "û��ѧ��Ϊ" << s << "��ѧ��!" << endl;
		return false;//���ز���ʧ��
	}
	return true;//���ز��ҳɹ�
}