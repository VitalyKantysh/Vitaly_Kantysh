	#include "junior.h"
	#include "Workers.h"
	#include "Header.h"
	void junior::edit() {//��������������
		int choice;
		bool exit = false;
		int num;
		char str[N];
		edit_menu_junior();
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "������� ���\n->" ;
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
			cout << "������� ���������� ���������\n->" ;
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
			cout << "������� ������� ������\n->" ;
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
			cout << "������� ���������� ����������� ����\n->" ;
			cin >> num;
			set_num_days(num);
			system("pause");
			system("cls");
			break;
		case 9:
			cout << "������� ������ �����������\n->";
			cin >> str;
			set_education(str);
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
	const string junior::get_file() {//�������� ���� �����
		return FILE_JUNIOR;
	}	
	ostream& operator< (ostream& Cin, junior& point) {//������� � ���� �������
		Cin < dynamic_cast<Workers&>(point);
		Cin << setw(5) << " " << left << setw(10) << point.education << "|\n";
		Cin << "|-------------|-------------|--------------|-----|------------|----------------|--------|-------------|---------------|";
		return Cin;
	}
	void junior::HEADER() {//����� ��� �������
		cout << " ____________________________________________________________"<<
			"_________________________________________________________\n";
		cout << "|   �������   |     ���     |  ���������   | ��� | �������"<<
			" �� | ������� ������ | ������ | ������. ��� |  �����������  |\n";
		cout << "|-------------|-------------|--------------|-----|----------"<<
			"--|----------------|--------|-------------|---------------|\n";
	}
	ofstream& operator<< (ofstream& Cout, junior& point) {//���������� ������ ��� ������ � ����
		Cout << point.lastname << "/" << point.firstname << " " << point.post << " "
			<< point.num_days << " " << point.daily_zp << " " << point.current_project << " "
			<< point.award << " " << point.missing_day << " " << point.education;
		return Cout;
	}
	ifstream& operator>> (ifstream& Cin, junior& point) {//���������� ����� ��� ������ � ����
		Cin >> dynamic_cast<Workers&>(point);
		char buf[NAME_SIZE];
		Cin >> buf;
		point.set_education(buf);
		//Cin >> point.education;
		return Cin;
	}
	istream& operator> (istream& Cin, junior& point) {//���������� �����
		Cin > dynamic_cast<Workers&>(point);
		strcpy_s(point.education, engSymInput(Cin, "������� �����������"));
		/*cout << "������� �����������\n->";
		Cin.getline(point.education, N);
		cout << endl;*/
		return Cin;
	}
	junior::junior(const char* last_name, const char* first_name, const char* post, double daily_zp, int num_days, const char* current_project, int award, int missing_day, const char* education) {
		//����������� � �����������
		set_lastname(last_name);
		set_firstname(first_name);
		set_post(post);

		set_daily_zp(daily_zp);
		set_num_days(num_days);
		set_missing_day(missing_day);
		set_award(award);
		set_current_project(current_project);
		set_education(education);
	}
	junior::junior() {//����������� ��� ����������
		strcpy_s(education, "");
	}
	char* junior::get_education() {//��������� �����������
		return education;
	}
	void junior::set_education(const char* education) {//������������� �����������
		strcpy_s(this->education, education);
	}