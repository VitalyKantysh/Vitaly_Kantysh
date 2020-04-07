#pragma once
#include "Company.h"
class Workers :public Company {
protected:
	char current_project[N];//������� ������
	int award;//������
	int missing_day;//���-�� ����������� ����
public:
	Workers();//����������� ��� ����������
	Workers(const char*, const char*, char*, double, int, const char*, int, int);
	//����������� � �����������
	char* get_current_project();//��������� ������� ������
	int get_award();//��������� ������
	int get_missing_day();//��������� ���-�� ����������� ����
	void set_missing_day(int);//������������� ������� ������
	void set_award(int);//������������� ������
	void set_current_project(const char*);//������������� ������� ������
	void print_solary();//������� �������� ��� ���� �����������
	friend ifstream& operator>> (ifstream& Cin, Workers& point);
	friend istream& operator> (istream& Cin, Workers& point);//���������� �����
	friend ostream& operator< (ostream& Cin, Workers& point);//���������� �����
};