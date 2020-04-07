#include "Company.h"
#include "Header.h"
void Company::HEADER_SOLARY() {//����� ��� �������
	cout << " ____________________________________________________________\n";
	cout << "|    �������    |      ���      |  ���-�� ����  |  ��������  |\n";
	cout << "|---------------|---------------|---------------|------------|\n";
}

ostream& operator< (ostream& Cin, Company& point) {
	Cin << "|" << setw(3) << " " << left << setw(10) << point.lastname << "|"
		<< setw(3) << " " << left << setw(10) << point.firstname << "|" << setw(4)
		<< " " << left << setw(10) << point.post << "|"
		<< setw(1) << " " << left << setw(4) << point.num_days
		<< "|" << setw(4) << " " << left << setw(8)
		<< point.daily_zp << "|";
	return Cin;
}

ifstream& operator>> (ifstream& Cin, Company& point) {
	char buf[NAME_SIZE];
	int num;
	Cin.getline(buf, strlen(buf) + 1, '/');
	point.set_lastname(buf);
	Cin >> buf;
	point.set_firstname(buf);
	Cin >> buf; 
	point.set_post(buf);
	Cin >> num;
	point.set_num_days(num);
	Cin >> num;
	point.set_daily_zp(num);

	//Cin >> point.lastname >> point.firstname >> point.post >> point.num_days >> point.daily_zp;
	return Cin;
}


istream& operator> (istream& Cin, Company& point) {//���������� �����
	strcpy_s(point.lastname, engSymInput(Cin, "�������"));
	strcpy_s(point.firstname, engSymInput(Cin, "���"));
	strcpy_s(point.post, engSymInput(Cin, "���������� ���������"));
	point.num_days = inputNumber(Cin, 0, 30, "���-�� ������������� ���� � ������");
	point.daily_zp = inputNumber(Cin, 50, 3000, "������� ��������");

	return Cin;
	/*
	cout << "������� �������\n->";
	Cin.getline(point.lastname, N);
	cout << "������� ���\n->";
	Cin.getline(point.firstname, N);
	cout << "������� ���������� ���������\n->";
	Cin.getline(point.post, N);
	cout << "������� ���-�� ������������� ���� � ������\n->";
	Cin >> point.num_days;
	cout << "������� ������� ��������\n->";
	Cin >> point.daily_zp;
	Cin.ignore(256, '\n');
	*/	
}
Company::Company(const char* last_name, const char* first_name, char* post, double daily_zp, int num_days) {
	//����������� � �����������
	set_lastname(last_name);
	set_firstname(first_name);
	set_post(post);
	set_daily_zp(daily_zp);
	set_num_days(num_days);
}
Company::Company() {//����������� ��� ����������
	strcpy_s(lastname, "");
	strcpy_s(firstname, "");
	strcpy_s(post, "");
	num_days = NULL;
	daily_zp = NULL;
}
char* Company::get_last_name() {//��������� �������
	return lastname;
}
char* Company::get_first_name() {//��������� ���
	return firstname;
}
char* Company::get_post() {//��������� ���������
	return this->post;
}
int Company::get_num_days() {//��������� ���-�� ������������ ����
	return this->num_days;
}
double Company::get_daily_zp() {//��������� ������� ��
	return this->daily_zp;
}
void Company::set_lastname(const char* lastname) {//������������� �������
	strcpy_s(this->lastname, lastname);
}
void Company::set_firstname(const char* firstname) {//������������� ���
	strcpy_s(this->firstname, firstname);
}
void Company::set_daily_zp(double daily_zp) {//������������� ������� ��
	this->daily_zp = daily_zp;
}
void Company::set_num_days(int num_days) {//������������� ���-�� ������������ ����
	this->num_days = num_days;
}
void Company::set_post(const char* post) {//������������� ����
	strcpy_s(this->post, post);
}