#pragma once
#include "Supervisors.h"
class senior : public Supervisors {
protected:
	char current_role[N];//������� ����
public:
	senior();//����������� ��� ����������
	senior(const char*, const char*, const char*, double, int, int, int, int, const char*);
	//����������� � �����������
	char* get_current_role();//��������� ������� ����
	void set_current_role(const char*);//���������� ������� ����
	
	void edit();//��������������	
	const string get_file();//�������� ���� �����
	void HEADER();//����� ��� �������
	friend istream& operator> (istream& Cin, senior& point);//���������� �����
	friend ostream& operator< (ostream& Cout, senior& point);
	friend ofstream& operator<< (ofstream& out, senior& point);//���������� ������ ��� ������ � ����
	friend ifstream& operator>> (ifstream& Cin, senior& point);//���������� ����� ��� ������ � ����
};