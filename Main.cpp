#include "User.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	cout.flags(ios::left);//���������ʽΪ�����
	system("mode con cols=100 lines=25");//���ô��ڴ�С
	LPCWSTR str=TEXT("�༶�ۺ����ʲ�������ϵͳ");	//���ô��ڱ���
	SetConsoleTitle(str);//���ô��ڱ���
	User temp;//������ʱ����
	temp.Menu(temp.Login());//���ö���ĵ�½�������жϵ�½�û����ͣ�������Ӧ�Ķ���
	return 0;
}