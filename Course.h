#pragma once
#include <string>
#include <iostream>
using namespace std;
class Course
{
private:
	string Account;//ѧ��
	string Name;//�γ���
	float Credit;//ѧ��
	float Grade;//�ɼ�
public:	
	Course(string, string, float, float);//���캯��
	Course(){}//���캯��
	string getAccount();//����ѧ��
	float getCredit();//����ѧ��
	float getGrade();//���سɼ�
	//���������
	friend istream& operator>>(istream &in, Course &u);
	friend ostream& operator<<(ostream &out, const Course &u);	
};