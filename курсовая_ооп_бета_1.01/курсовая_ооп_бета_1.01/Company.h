#pragma once
#include "Header.h"
class Company {
protected:
	char firstname[N];//имя
	char lastname[N];//фамилия
	char post[N];//занимаемая должность
	int num_days;//кол-во отраотанных жней
	double daily_zp;//дневная зп
public:
	Company();//конструктор без параметров
	Company(const char*, const char*, char*, double, int);
	//конструктор с параметрами
	char* get_last_name();//возращает фамилию
	char* get_first_name();//возращает имя
	char* get_post();//возращает должность
	double get_daily_zp();//возращает дневную зп
	int get_num_days();//возращает кол-во отработанных дней
	void set_lastname(const char*);//устанавливает фамилию
	void set_firstname(const char*);//устанавливает имя
	void set_post(const char*);//устанавливает пост
	void set_daily_zp(double);//устанавливает дневную зп
	void set_num_days(int);//устанавливает кол-во отработанных дней
	void HEADER_SOLARY();//шапка для вывода зарплаты всем сотрудникам
	friend ifstream& operator>> (ifstream& Cin, Company& point);
	friend istream& operator> (istream& Cin, Company& point);//перегрузка ввода 
	friend ostream& operator< (ostream& Cin, Company& point);//перегрузка ввода 

};