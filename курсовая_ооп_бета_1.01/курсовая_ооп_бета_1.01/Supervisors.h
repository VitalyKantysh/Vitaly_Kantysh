#pragma once
#include "Company.h"
class Supervisors :	public Company {
protected:
	int num_project;//номер проекта 
	int profit;//прибыль
	int solary;//аванс
public:
	Supervisors();//конструктор без параметров
	Supervisors(const char*, const char*, char*, double, int, int, int, int);
	//конструктор с параметрами
	int get_solary();//возращает номер проекта 
	int get_profit();//возращает прибыль
	int get_num_project();//возращает аванс
	void set_num_project(int);//устанавливает номер проекта
	void set_solary(int);//устанавливает прибыль
	void set_profit(int);//устанавливает аванс
	void print_solary();//вывести зарплату всем сотрудникам
	friend ifstream& operator>> (ifstream& Cin, Supervisors& point);
	friend istream& operator> (istream& Cin, Supervisors& point);//перегрузка ввода
	friend ostream& operator< (ostream& Cin, Supervisors& point);//перегрузка ввода
};