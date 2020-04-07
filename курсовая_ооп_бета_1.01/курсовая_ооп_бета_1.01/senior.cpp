
#include "senior.h"
#include "Supervisors.h"
#include "Header.h"
void senior::edit() {//��������������	
	int choice;
	int num;
	char str[N];
	edit_menu_senior();
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "������� ���\n->";
		cin >> str;
		set_firstname(str);
		system("pause");
		system("cls");
		break;
	case 2:
		cout << "������� �������\n->";
		cin >> str;
		set_lastname(str);
		system("pause");
		system("cls");
		break;
	case 3:
		cout << "������� ���������� ���������\n->";
		cin >> str;
		set_post(str);
		system("pause");
		system("cls");
		break;
	case 4:
		cout << "������� ���������� ������������� ����\n->" ;
		cin >> num;
		set_num_days(num);
		system("pause");
		system("cls");
		break;
	case 5:
		cout << "������� ������� ��������\n->" ;
		cin >> num;
		set_daily_zp(num);
		system("pause");
		system("cls");
		break;
	case 6:
		cout << "������� ���������� ��������\n->" ;
		cin >> num;
		set_num_project(num);
		system("pause");
		system("cls");
		break;
	case 7:
		cout << "������� �������\n->" ;
		cin >> num;
		set_profit(num);
		system("pause");
		system("cls");
		break;
	case 8:
		cout << "������� �����\n->" ;
		cin >> num;
		set_num_days(num);
		system("pause");
		system("cls");
		break;
	case 9:
		cout << "������� ������� ����\n->" ;
		cin >> str;
		set_current_role(str);
		system("pause");
		system("cls");
		break;
	case 0:
		system("pause");
		system("cls");
		break;
	default:
		cout << "�������� ����!!\n";
		system("pause");
		system("cls");
	}
}
const string senior::get_file() {//�������� ���� �����
	return FILE_SENIOR;
}
ostream& operator< (ostream& Cin, senior& point) {//������� � ���� �������
	Cin < dynamic_cast<Supervisors&>(point);
	Cin << setw(4) << " " << left << setw(15) << point.current_role << "|\n";
	Cin << "|-------------|-------------|--------------|-----|---------"
		<<"---|-----------------|---------|-------|-------------------|";
	return Cin;
}
void senior::HEADER() {//����� ��� �������
	cout << " __________________________________________________________"<<
		"___________________________________________________________\n";
	cout << "|   �������   |     ���     |   ���������  | ��� | ������� �"<<
		"� | ���-�� �������� | ������� | ����� |    ������� ����   |"  << endl;
	cout << "|-------------|-------------|--------------|-----|------------"<<
		"|-----------------|---------|-------|-------------------|" << endl;
}
istream& operator> (istream& Cin, senior& point) {//���������� �����
	Cin > dynamic_cast<Supervisors&>(point);
	strcpy_s(point.current_role, engSymInput(Cin, "������� ����"));

	//cout << "������� ������� ����\n->";
	//Cin.getline(point.current_role, N);
	return Cin;
}
ofstream& operator<< (ofstream& Cout, senior& point) {//���������� ������ ��� ������ � ����
	Cout << point.lastname<<"/" << point.firstname << " " << point.post << " " 
		<< point.num_days << " " << point.daily_zp << " " << point.num_project << " " 
		<< point.profit << " " << point.solary << " " << point.current_role << " ";
	return Cout;
}
ifstream& operator>> (ifstream& Cin, senior& point) {//���������� ����� ��� ������ � ����
	Cin >> dynamic_cast<Supervisors&>(point);
	char buf[NAME_SIZE];
	Cin >> buf;
	point.set_current_role(buf);
	//Cin >> point.current_role;

	return Cin;
}
senior::senior(const char* last_name, const char* first_name,const char* post, double daily_zp,
	int num_days, int num_project, int profit, int solary, const char* current_role) {
	//����������� � �����������
	set_lastname(last_name);
	set_firstname(first_name);
	set_post(post);
	set_daily_zp(daily_zp);
	set_num_days(num_days);	
	set_num_project(num_project);
	set_solary(solary);
	set_profit(profit);
	set_current_role(current_role);
}
senior::senior() {//����������� ��� ����������
	strcpy_s(current_role, "");
}
char* senior::get_current_role() {//��������� ������� ����
	return this->current_role;
}
void senior::set_current_role(const char* current_role) {//���������� ������� ����
	strcpy_s(this->current_role, current_role);
}

