#pragma once
#include "Workers.h"
class middle : public Workers {
protected:
	int num_of_projects;//���������� ��������
public:	
	middle();//����������� ��� ����������
	middle(const char*, const char*,  const char*, double, int, const char*, int, int, int);
	//����������� � �����������
	int get_num_of_projects();//�������� ���������� ��������
	void set_num_of_projects(int);//�������� ���������� ��������
	
	void HEADER();//����� ��� �������
	void edit();//��������������
	const string get_file();//�������� ���� �����
	friend istream& operator> (istream& Cin, middle& point);//���������� �����
	friend ostream& operator< (ostream& Cout, middle& point);//���������� �����
	friend ofstream& operator<< (ofstream& out, middle& point);//���������� ������ ��� ������ � ����
	friend ifstream& operator>> (ifstream& Cin, middle& point);//���������� ����� ��� ������ � ����
};