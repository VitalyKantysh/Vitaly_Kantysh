#pragma once
#include "Company.h"
class Supervisors :	public Company {
protected:
	int num_project;//����� ������� 
	int profit;//�������
	int solary;//�����
public:
	Supervisors();//����������� ��� ����������
	Supervisors(const char*, const char*, char*, double, int, int, int, int);
	//����������� � �����������
	int get_solary();//��������� ����� ������� 
	int get_profit();//��������� �������
	int get_num_project();//��������� �����
	void set_num_project(int);//������������� ����� �������
	void set_solary(int);//������������� �������
	void set_profit(int);//������������� �����
	void print_solary();//������� �������� ���� �����������
	friend ifstream& operator>> (ifstream& Cin, Supervisors& point);
	friend istream& operator> (istream& Cin, Supervisors& point);//���������� �����
	friend ostream& operator< (ostream& Cin, Supervisors& point);//���������� �����
};