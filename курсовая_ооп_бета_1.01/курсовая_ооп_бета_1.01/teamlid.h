#pragma once
#include "Supervisors.h"
class teamlid :	public Supervisors {
protected:
	int num_people;//���������� �����������
public:	
	teamlid();//����������� ��� ����������
	teamlid(const char*, const char*, const char*, double, int, int, int, int, int);
	//����������� � �����������
	int get_num_people();//��������� ���������� �����������
	void set_num_people(int);//������������� ���������� �����������
	
	void HEADER();//����� ��� �������
	void edit();//��������������
	const string get_file();//�������� ���� �����
	friend istream& operator> (istream& Cin, teamlid& point);//���������� �����
	friend ostream& operator< (ostream& Cin, teamlid& point);
	friend ofstream& operator<< (ofstream& out, teamlid& point);//���������� ������ ��� ������ � ����
	friend ifstream& operator>> (ifstream& Cin, teamlid& point);//���������� ����� ��� ������ � ����
};	