#pragma once
#include "Workers.h"
class junior : public Workers {
protected:
	char education[N];//�����������
public:
	junior();//����������� ��� ����������
	junior(const char*, const char*, const char*, double, int, const char*, int, int, const char*);
	//����������� � �����������
	char* get_education();//��������� �����������
	void set_education(const char*);//������������� �����������

	void HEADER();//����� ��� �������
	void edit();//��������������
	const string get_file();//�������� ���� �����
	friend istream& operator> (istream& Cin, junior& point);//���������� �����
	friend ostream& operator< (ostream& Cin, junior& point);
	friend ofstream& operator<< (ofstream& out, junior& point);//���������� ������ ��� ������ � ����
	friend ifstream& operator>> (ifstream& Cin, junior& point);//���������� ����� ��� ������ � ����
};