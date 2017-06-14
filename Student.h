#pragma once
#include "User.h"
#include <iostream>
#include <map>
using namespace std;
class Student:public User
{
protected:
	float study;//ѧϰ�ɼ�
	float gpa;//gpa
	float activity;//�����ɼ�
	float moral;//˼��Ʒ�³ɼ�
	float addition;//���ӷ�
	float total;//�۲�ɼ�
	int range;//����	
public:
	Student(string a, string n, string p, char i,char y,float st=0.0,float gp=0.0,float ac=0.0,float mo=0.0,float ad=0.0,float to=0.0,int ra=0);//���캯��
	Student();//���캯��
	static map<string, Student> TotalList;//�۲��ܱ� �ؼ���:ѧ��
	static void importTotalList();//�����۲��ܱ�
	static void exportTotalList();//�����۲��ܱ�	
	void MainMenu();//���˵�
	void MultiChoiceMenu(vector<string> Qs, int n);//�Ӳ˵�
	//˼��Ʒ����Ŀ
	void Moral();
	void gradeMoral();//˼��Ʒ�´��
	void modifyMoral();//�޸�˼��Ʒ�´��
	//��ѯ��Ŀ
	void Search();
	void searchStudy();//��ѯѧϰ�ɼ�
	void searchGPA();//��ѯGPA
	void searchActivity();//��ѯ�����ɼ�
	void searchMoral();//��ѯ˼��Ʒ�³ɼ�
	void searchAddition();//��ѯ���ӷ�
	void searchTotal();//��ѯ�۲��ܷ�
	void searchrange();//��ѯ����
	void searchall();//��ѯ����
	//������Ŀ
	void Activity();
	void newActivity();//¼�����
	void delActivity();//ɾ������
	void modifyActivity();//�޸Ŀ���
	void displayActivity();//��ӡ����

	//��ȡ����
	float getstudy();//��ȡѧϰ�ɼ�
	float getgpa();//��ȡgpa
	float getactivity();//��ȡ�����ɼ�
	float getmoral();//��ȡ˼��Ʒ�³ɼ�
	float getaddition();//��ȡ���ӷ�
	float gettotal();//��ȡ�۲�ɼ�
	int getrange();//��ȡ����
	//��������
	void instudy(float);//����ѧϰ�ɼ�
	void ingpa(float);//����gpa
	void inactivity(float);//��������ɼ�
	void inmoral(float);//����˼��Ʒ�³ɼ�
	void inaddition(float);//���븽�ӷ�
	void intotal();//�����۲�ɼ�
	void inrange(int);//��������
	//���������
	friend istream& operator>>(istream &in, Student &u);
	friend ostream& operator<<(ostream &out, const Student &u);
};
