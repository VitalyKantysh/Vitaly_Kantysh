#include "Company.h"
#include "Workers.h"
#include "Header.h"
void Workers::print_solary() {//������� �������� ��� ���� �����������
	cout << "|" << setw(4) << " " << left << setw(11) << lastname
		<< "|" << setw(3) << " " << left << setw(12) << firstname
		<< "|" << setw(6) << " " << left << setw(9) << num_days
		<< "|" << setw(4) << " " << left << setw(8)
		<< daily_zp * num_days + award << "|\n";
	cout << "|---------------|---------------|---------------|------------|";
}
istream& operator> (istream& Cin, Workers& point) {//���������� �����
	Cin > dynamic_cast<Company&>(point);

	strcpy_s(point.current_project, engSymInput(Cin, "������� ������"));
	point.award = inputNumber(Cin, 0, 30, "���-�� ������������� ���� � ������");
	point.missing_day = inputNumber(Cin, 0, 30, "���-�� ���-�� ����������� ���� �� ������� �����");

	return Cin;
	/*cout << "������� ������� ������\n->";
Cin.getline(point.current_project, N);
cout << "������� ������\n->";
Cin >> point.award;
cout << "������� ���-�� ����������� ���� �� ������� �����\n->";
Cin >> point.missing_day;
Cin.ignore(256, '\n');*/
}

ostream& operator< (ostream& Cin, Workers& point) {
	Cin < dynamic_cast<Company&>(point);
	Cin << setw(6) << " " << left << setw(10) << point.current_project << "|"
		<< setw(3) << " " << left << setw(5) <<
		point.award << "|" << setw(6) << " " << left << setw(7)
		<< point.missing_day << "|";
	return Cin;
}

ifstream& operator>> (ifstream& Cin, Workers& point) {
	Cin >> dynamic_cast<Company&>(point);
	char buf[NAME_SIZE];
	int num;
	Cin >> buf;
	point.set_current_project(buf);
	Cin >> num;
	point.set_award(num);
	Cin >> num;
	point.set_missing_day(num);
	//Cin >> point.current_project >> point.award >> point.missing_day;
	return Cin;
}

Workers::Workers(const char* last_name, const char* first_name, char* post, double daily_zp, int num_days, const char* current_project, int award, int missing_day) {
	//����������� � �����������
	set_lastname(last_name);
	set_firstname(first_name);
	set_post(post);
	set_daily_zp(daily_zp);
	set_num_days(num_days);
	set_missing_day(missing_day);
	set_award(award);
	set_current_project(current_project);
}
Workers::Workers() {//����������� ��� ����������
	missing_day = NULL;
	award = NULL;
	strcpy_s(current_project, "");
}
char* Workers::get_current_project() {//��������� ������� ������
	return current_project;
}
int Workers::get_award() {//��������� ������
	return this->award;
}
int Workers::get_missing_day() {//��������� ���-�� ����������� ����
	return this->missing_day;
}
void Workers::set_current_project(const char* current_project) {//������������� ������� ������
	strcpy_s(this->current_project, current_project);
}
void Workers::set_award(int award) {//������������� ������
	this->award = award;
}
void Workers::set_missing_day(int missing_day) {//������������� ������� ������
	this->missing_day = missing_day;
}