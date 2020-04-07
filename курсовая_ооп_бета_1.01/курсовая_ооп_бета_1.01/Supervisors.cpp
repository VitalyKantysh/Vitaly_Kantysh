#include "Company.h"
#include "Supervisors.h"
#include "Header.h"
void Supervisors::print_solary() {
	cout << "|" << setw(4) << " " << left << setw(11) << lastname
		<< "|" << setw(3) << " " << left << setw(12) << firstname
		<< "|" << setw(6) << " " << left << setw(9) << num_days
		<< "|" << setw(4) << " " << left << setw(8)
		<< daily_zp * num_days + solary << "|\n";
	cout << "|---------------|---------------|---------------|------------|";
}

ifstream& operator>> (ifstream& Cin, Supervisors& point) {
	Cin >> dynamic_cast<Company&>(point);
	char buf[NAME_SIZE];
	int num;
	Cin >> num;
	point.set_num_project(num);
	Cin >> num;
	point.set_profit(num);
	Cin >> num;
	point.set_solary(num);
	//Cin >> point.num_project >> point.profit >> point.solary;
	return Cin;
}

ostream& operator< (ostream& Cin, Supervisors& point) {
	Cin < dynamic_cast<Company&>(point);
	Cin << setw(7) << " " << left << setw(10) <<
		point.num_project << "|" << setw(4) << " " << left << setw(5) <<
		point.profit << "|" << setw(3) << " " << left << setw(4)
		<< point.solary << "|";
	return Cin;
}

istream& operator> (istream& Cin, Supervisors& point) {
	Cin > dynamic_cast<Company&>(point);
		
	point.num_project = inputNumber(Cin, 0, 20, "количество проектов");
	point.profit = inputNumber(Cin, 0, 50000, "прибыль");
	point.solary = inputNumber(Cin, 0, 10000, "аванс");
	
	return Cin;
	/*cout << "¬ведите количество проектов\n->";
	Cin >> point.num_project;
	cout << "¬ведите прибыль\n->";
	Cin >> point.profit;
	cout << "¬ведите аванс\n->";
	Cin >> point.solary;
	Cin.ignore(256, '\n');*/
}
Supervisors::Supervisors(const char* last_name, const char* first_name, char* post, double daily_zp, int num_days, int num_project, int profit, int solary) {
	set_lastname(last_name);
	set_firstname(first_name);
	set_post(post);
	set_daily_zp(daily_zp);
	set_num_days(num_days);
	set_num_project(num_project);
	set_solary(solary);
	set_profit(profit);
}
Supervisors::Supervisors() {
	num_project = NULL;
	profit = NULL;
	solary = NULL;
}
int Supervisors::get_solary() {
	return this->solary;
}
int Supervisors::get_profit() {
	return this->profit;
}
int Supervisors::get_num_project() {
	return this->num_project;
}
void Supervisors::set_num_project(int num_project) {
	this->num_project = num_project;
}
void Supervisors::set_profit(int profit) {
	this->profit = profit;
}
void Supervisors::set_solary(int solary) {
	this->solary = solary;
}