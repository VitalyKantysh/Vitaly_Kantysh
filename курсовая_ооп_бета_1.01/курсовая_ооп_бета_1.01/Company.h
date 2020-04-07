#pragma once
#include "Header.h"
class Company {
protected:
	char firstname[N];//���
	char lastname[N];//�������
	char post[N];//���������� ���������
	int num_days;//���-�� ����������� ����
	double daily_zp;//������� ��
public:
	Company();//����������� ��� ����������
	Company(const char*, const char*, char*, double, int);
	//����������� � �����������
	char* get_last_name();//��������� �������
	char* get_first_name();//��������� ���
	char* get_post();//��������� ���������
	double get_daily_zp();//��������� ������� ��
	int get_num_days();//��������� ���-�� ������������ ����
	void set_lastname(const char*);//������������� �������
	void set_firstname(const char*);//������������� ���
	void set_post(const char*);//������������� ����
	void set_daily_zp(double);//������������� ������� ��
	void set_num_days(int);//������������� ���-�� ������������ ����
	void HEADER_SOLARY();//����� ��� ������ �������� ���� �����������
	friend ifstream& operator>> (ifstream& Cin, Company& point);
	friend istream& operator> (istream& Cin, Company& point);//���������� ����� 
	friend ostream& operator< (ostream& Cin, Company& point);//���������� ����� 

};