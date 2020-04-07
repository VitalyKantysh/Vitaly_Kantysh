#include "middle.h"
#include "Workers.h"
#include "Header.h"
void middle::edit() {//��������������
	int choice;
	bool exit = false;
	int num;
	char str[N];		
	edit_menu_middle();
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
		cout << "������� �������\n->" ;
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
		cout << "������� ������� ������\n->";
		cin >> str;
		set_current_project(str);
		system("pause");
		system("cls");
		break;
	case 7:
		cout << "������� ������\n->" ;
		cin >> num;
		set_award(num);
		system("pause");
		system("cls");
		break;
	case 8:
		cout << "������� ���������� ����������� ����\n->";
		cin >> num;
		set_num_days(num);
		system("pause");
		system("cls");
		break;
	case 9:
		cout << "������� ���������� ��������\n->" ;
		cin >> num;
		set_num_of_projects(num);
		system("pause");
		system("cls");
		break;
	case 0:
		exit = true;
		break;
	default:
		cout << "�������� ����!!\n";
		system("pause");
		system("cls");
	}
}
const string middle::get_file() {//�������� ���� �����
	return FILE_MIDDLE;
}
 ostream& operator< (ostream& Cin, middle& point) {//������� � ���� �������
	 Cin < dynamic_cast<Workers&>(point);
	 Cin << setw(5) << " " << left << setw(10) << point.num_of_projects << "|\n";
	 Cin << "|-------------|-------------|--------------|-----|------------|--------"<<
		"--------|--------|-------------|---------------|";
	 return Cin;
}
void middle::HEADER() {//����� ��� �������
	cout << " _____________________________________________________________"<<
		"________________________________________________________\n";
	cout << "|   �������   |     ���     |   ���������  | ��� | ������� �� "<<
		"| ������� ������ | ������ | ������. ��� |���-�� ��������|\n";
	cout << "|-------------|-------------|--------------|-----|------------|"<<
		"----------------|--------|-------------|---------------|\n";
}
ofstream& operator<< (ofstream& Cout, middle& point) {//���������� ������ ��� ������ � ����
	Cout << point.lastname << "/" << point.firstname << " " 
		<< point.post << " "<< point.num_days << " " << point.daily_zp
		<< " " << point.current_project << " "<< point.award << " " << 
		point.missing_day << " " << point.num_of_projects;
	return Cout;
}
ifstream& operator>> (ifstream& Cin, middle& point) {//���������� ����� ��� ������ � ����
	Cin >> dynamic_cast<Workers&>(point);
	char buf[NAME_SIZE];
	int num;
	Cin >> num;
	point.set_num_of_projects(num);
	//Cin >> point.num_of_projects;
	return Cin;
}
istream& operator> (istream& Cin, middle& point) {//���������� �����
	Cin > dynamic_cast<Workers&>(point);
	
	point.num_of_projects = inputNumber(Cin, 0, 150, "���������� ������������ ��������");
	/*cout << "������� ���������� ������������ ��������\n->";
	Cin >> point.num_of_projects;
	cout << endl;
	Cin.ignore(256, '\n');*/
	return Cin;
}
middle::middle(const char* last_name, const char* first_name,const char* post, double daily_zp, int num_days,
	const char* current_project, int award, int missing_day, int num_of_projects) {
	//����������� � �����������
	set_lastname(last_name);
	set_firstname(first_name);
	set_post(post);
	set_daily_zp(daily_zp);
	set_num_days(num_days);
	set_missing_day(missing_day);
	set_award(award);
	set_current_project(current_project);
	set_num_of_projects(num_of_projects);
}
middle::middle() {//����������� ��� ����������
	num_of_projects = NULL;
}
int middle::get_num_of_projects() {//�������� ���������� ��������
	return num_of_projects;
}
void middle::set_num_of_projects(int num_of_projects) {//�������� ���������� ��������
	this->num_of_projects = num_of_projects;
}