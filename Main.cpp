#include "User.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	cout.flags(ios::left);//设置输出格式为左对齐
	system("mode con cols=100 lines=25");//设置窗口大小
	LPCWSTR str=TEXT("班级综合素质测评管理系统");	//设置窗口标题
	SetConsoleTitle(str);//设置窗口标题
	User temp;//创建临时对象
	temp.Menu(temp.Login());//调用对象的登陆函数，判断登陆用户类型，创建对应的对象
	return 0;
}