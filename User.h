#pragma once
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>
#include "Course.h"
#include "ActAdd.h"
#include "Moral_s.h"
#include "Moral_t.h"
#include <fstream>
#include <iostream>


using namespace std;
class User
{
protected:
	string Account;//�˺�
	string Name;//����
	string Password;//����
	char Identify;//�û����ͣ�0:ѧ�� 1:������ 2:����С�飩
	char Yes;//ѧ���������Σ�˼��Ʒ���Ƿ��Ѵ�֣�0:δ��� 1:�Ѵ�֣� ����С�飺�۲�ɼ��Ƿ�����
	static map<string, User> LoginList; //�����û���Ϣ �ؼ���:ѧ��
	static multimap<string, Course> CourseList; //����γ���Ϣ �ؼ��֣�ѧ��
	static multimap<string, Moral_s> MoralList_sget; //����ѧ�������Ϣ �ؼ��֣��÷���ѧ��
	static multimap<string, Moral_s> MoralList_sgive; //����ѧ�������Ϣ �ؼ��֣������ѧ��
	static map<string, Moral_t>  MoralList_t;  //��������δ����Ϣ �ؼ���:�÷���ѧ��
	static multimap<string, ActAdd > Act_List; //���������Ϣ �ؼ��֣�ѧ��
	static multimap<string, ActAdd> Add_List;//���渽�ӷ���Ϣ �ؼ��֣�ѧ��
	
public:
	User(string,string,string,char,char);//���캯��
	User(){}//���캯��
	void display();//��ӡ����
	User Login();//��½
	void Menu(User);//���ݵ�½�û����ʹ�����Ӧ����
	void modifyPassword();//�޸�����
	void Save();//���ص�½����
	void Quit();//�˳�	
	//�ж�
	void line(int&, const int&);//�ж�����������Ƿ���ȷ
	void judge(float&,int);//�жϷ����Ƿ���ȷ
	void Grade(float*,int);//˼��Ʒ�´�֣�ͬʱ�жϷ����Ƿ���ȷ��
	//��ȡ
	string getAccount() ;//��ȡ�˺�
	void modifyAccount(string);//�޸��˺�
	string getPassword() ;//��ȡ����
	string getName() ;//��ȡ����
	char getIdentify() ;//��ȡ�û�����
	char getYes() ;//��ȡ�Ƿ���
	void modifyYes();//�޸Ĵ��״̬��δ���->�Ѵ�֣�
	void modify();
	void modifyNo();//�޸��۲�����״̬������->δ���ɣ�
	string searchName(string);//����ѧ�ŷ�������
	//���ݴ�ȡ
	void importLoginList();//�����û���Ϣ
	void importCourseList();//����γ���Ϣ
	void importAct_List();//���������Ϣ
	void importAdd_List();//���븽�ӷ���Ϣ
	void importMoralList_s();//����ѧ�������Ϣ
	void importMoralList_t();//��������δ����Ϣ
	void exportLoginList();//�����û���Ϣ
	void exportCourseList();//�����γ���Ϣ
	void exportAct_List();//����������Ϣ
	void exportAdd_List();//�������ӷ���Ϣ
	void exportMoralList_s();//����ѧ�������Ϣ
	void exportMoralList_s2();//����ѧ�������Ϣ
	void exportMoralList_t();//���������δ����Ϣ
	//���������
	friend istream& operator>>(istream &in, User &u);
	friend ostream& operator<<(ostream &out, const User &u);
	static void Close(ofstream&);//�ж��Ƿ��������ļ�
};
