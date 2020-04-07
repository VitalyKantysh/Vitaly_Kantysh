#pragma once
#include "Company.h"
class Workers :public Company {
protected:
	char current_project[N];//текущий проект
	int award;//премия
	int missing_day;//кол-во пропущенных дней
public:
	Workers();//конструктор без параметров
	Workers(const char*, const char*, char*, double, int, const char*, int, int);
	//конструктор с параметрами
	char* get_current_project();//возращает текущий проект
	int get_award();//возращает премию
	int get_missing_day();//возращает кол-во пропущенных дней
	void set_missing_day(int);//устанавливает текущий проект
	void set_award(int);//устанавливает премию
	void set_current_project(const char*);//устанавливает текущий проект
	void print_solary();//выводит зарплату для всех сотрудников
	friend ifstream& operator>> (ifstream& Cin, Workers& point);
	friend istream& operator> (istream& Cin, Workers& point);//перегрузка ввода
	friend ostream& operator< (ostream& Cin, Workers& point);//перегрузка ввода
};