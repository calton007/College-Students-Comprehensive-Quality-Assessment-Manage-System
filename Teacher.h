#pragma once
#include "User.h"
class Teacher :public User
{
public:
	Teacher(string a, string n, string p, char i,char y);//���캯��
	Teacher(){}//���캯��
	void MainMenu();//���˵�
	void MultiChoiceMenu(vector<string> Qs);//�Ӳ˵�
	void gradeMoral();//˼��Ʒ�´��
	void modifyMoral();//�޸�˼��Ʒ�´��	
};
