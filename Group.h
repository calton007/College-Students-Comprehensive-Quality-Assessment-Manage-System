#pragma once
#include <string>
#include "User.h"
#include "Student.h"
class Group :public User
{
public:
	Group(string a, string n, string p, char i,char y);//���캯��
	Group(){}//���캯��
	void MainMenu();//���˵�
	void MultiChoiceMenu(vector<string> Qs, int n);//�Ӳ˵�
	//ѧϰ�ɼ�����
	void study();
	void newStudy();//¼��ѧϰ�ɼ�
	void delStudy();//ɾ��ѧϰ�ɼ�
	void modifyStudy();//�޸�ѧϰ�ɼ�	
	//���ӷֹ���
	void addition();
	void newAddition();//¼�븽�ӷ�
	void modifyAddition();//�޸ĸ��ӷ�
	void delAddition();//ɾ�����ӷ�
	//�۲�ɼ�����
	void buildMoral();//����˼��Ʒ�³ɼ�
	void checkActivity();	//��˿���
	void buildActivity();//���ɿ����ɼ�
	void buildAddition();//���ɸ��ӷ�
	void getGPA();//����GPA
	void buildStudy();//����ѧϰ�ɼ�
	void buildTotal();//�����۲��ܷ�	
	//��ѯ
	void search();
	void searchStudy();//��ѯѧϰ�ɼ�
	void searchGPA();//��ѯGPA
	void searchActivity();//��ѯ�����ɼ�
	void searchMoral();//��ѯ˼��Ʒ�³ɼ�
	void searchAddition();//��ѯ���ӷ�
	void searchTotal();//��ѯ�۲�ɼ�
	void searchall();//��ѯ����
	bool exist(string);//�жϲ��ҵ��˺��Ƿ����
};