#pragma once
#include <iostream>
#include <string>
using namespace std;
class Moral_s
{
private:
	string Account_get;//�÷���ѧ��
	string Account_give;//�����ѧ��
	float ch[9];//����÷�
public:
	Moral_s(string, string, float a[9]);//���캯��
	Moral_s(){}//���캯��
	string getAccount_get();//���ص÷���ѧ��
	string getAccount_give();//���ش����ѧ��
	float getsum();//�����ܷ�
	//���������
	friend istream& operator>>(istream &in, Moral_s &u);
	friend ostream& operator<<(ostream &out, const Moral_s &u);	
};