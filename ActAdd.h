#pragma once
#include <string>
using namespace std;
class ActAdd
{
private:
	string Account;//ѧ��
	string Name;//���
	string Type;//���ͣ������򸽼ӷ֣�
	float Grade;//����
	string Get;//״̬��"δ���""���ͨ��""���δͨ��"��
public:	
	ActAdd(string, string, string, float, string);//���캯��
	ActAdd(){};//���캯��
	string getAccount();//����ѧ��
	string getType();//��������
	float getGrade();//���ط���
	string getGet();//����״̬
	void modifyGet(int);//�޸�״̬����˵�ʱ���ã�	
	//���������
	friend istream& operator>>(istream &in, ActAdd &u);
	friend ostream& operator<<(ostream &out, const ActAdd &u);
};