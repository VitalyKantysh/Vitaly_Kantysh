
#include "Supervisors.h"
#include "teamlid.h"
#include "Header.h"
void teamlid::edit() {//редактирование
	int choice;
	bool exit = false;
	int num;
	char str[N];
	while (exit == false) {
		edit_menu_senior();
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "¬ведите им€\n->" << endl;
			cin >> str;
			set_firstname(str);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "¬ведите фамилию\n->" << endl;
			cin >> str;
			set_lastname(str);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "¬ведите занимаемую должность\n->" << endl;
			cin >> str;
			set_post(str);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "¬ведите количество проробатынных дней\n->" << endl;
			cin >> num;
			set_num_days(num);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "¬ведите дневную зарплату\n->" << endl;
			cin >> num;
			set_daily_zp(num);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "¬ведите количество проектов\n->" << endl;
			cin >> num;
			set_num_project(num);
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "¬ведите прибыль\n->" << endl;
			cin >> num;
			set_profit(num);
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "¬ведите аванс\n->" << endl;
			cin >> num;
			set_num_days(num);
			system("pause");
			system("cls");
			break;
		case 9:
			cout << "¬ведите количество подчиненных\n->" << endl;
			cin >> num;
			set_num_people(num);
			system("pause");
			system("cls");
			break;
		case 0:
			exit = true;
			break;
		default:
			cout << "Ќеверный ввод!!\n";
			system("pause");
			system("cls");
		}
	}
}
const string teamlid::get_file() {//получает путь файла
	return FILE_TEAMLID;
}
ostream& operator< (ostream& Cin, teamlid& point) {//вывести в виде таблицы
	Cin < dynamic_cast<Supervisors&>(point);
	Cin << setw(8) << " " << left << setw(11) << point.num_people << "|\n";
	Cin << "|-------------|-------------|--------------|-----|------------|-"<<
		"----------------|---------|-------|-------------------|";
	return Cin;
}
void teamlid::HEADER() {//шапка дл€ таблицы
	cout << " ____________________________________________________________"<<
		"_________________________________________________________\n";
	cout << "|   фамили€   |     им€     |   должность  | дни | дневна€ зп |"<<
		" кол-во проектов | прибыль | аванс | кол-во подчиненных|\n";
	cout << "|-------------|-------------|--------------|-----|------------|"<<
		"-----------------|---------|-------|-------------------|\n";
}
ofstream& operator<< (ofstream& Cout, teamlid& point) {//перегрузка вывода дл€ записи в файл
	Cout << point.lastname << "/" << point.firstname << " " << point.post << " "
		<< point.num_days << " " << point.daily_zp << " " << point.num_project << " "
		<< point.profit << " " << point.solary << " " << point.num_people << endl;
	return Cout;
}
ifstream& operator>> (ifstream& Cin, teamlid& point) {//перегрузка ввода дл€ записи в файл
	Cin >> dynamic_cast<Supervisors&>(point);
	char buf[NAME_SIZE];
	int num;
	Cin >> num;
	point.set_num_people(num);
	//Cin >> point.num_people;
	return Cin;
}
istream& operator> (istream& Cin, teamlid& point) {//перегрузка ввода
	Cin > dynamic_cast<Supervisors&>(point);
	
	point.num_people = inputNumber(Cin, 0, 50, "кол-во количество подчиненных людей");
	/*cout << "¬ведите количество подчиненных людей\n->";
	Cin >> point.num_people;
	cout << endl;
	Cin.ignore(256, '\n');*/
	return Cin;
}
teamlid::teamlid(const char* last_name, const char* first_name, const char* post, double daily_zp, int num_days,
	int num_project, int profit, int solary, int num_people) {
	//конструктор с параметрами
	set_lastname(last_name);
	set_firstname(first_name);
	set_post(post);
	set_daily_zp(daily_zp);
	set_num_days(num_days);
	set_num_project(num_project);
	set_solary(solary);
	set_profit(profit);
	set_num_people(num_people);
}
teamlid::teamlid() {//конструктор без параметров
	num_people = NULL;
}
int teamlid::get_num_people() {//возращает количество подчиненных
	return this->solary;
}
void teamlid::set_num_people(int num_people) {//устанавливает количество подчиненных
	this->num_people = num_people;
}