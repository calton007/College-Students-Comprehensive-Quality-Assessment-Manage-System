#pragma once
#include <iostream>
#include <string>
using namespace std;
class Moral_t
{
private:
	string Account_get;//�÷���ѧ��
	string Account_give;//�����ѧ��
	float ch[3];//����÷�
public:
	Moral_t(string, string, float n[3]);//���캯��
	Moral_t(){}//���캯��
	string getAccount_get();//���ص÷���ѧ��
	string getAccount_give();//���ش����ѧ��
	float getsum();//�����ܷ�
	//���������
	friend istream& operator>>(istream &in, Moral_t &u);
	friend ostream& operator<<(ostream &out, const Moral_t &u);	
};