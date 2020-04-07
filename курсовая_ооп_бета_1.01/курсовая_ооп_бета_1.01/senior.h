#pragma once
#include "Supervisors.h"
class senior : public Supervisors {
protected:
	char current_role[N];//текущая роль
public:
	senior();//конструктор без параметров
	senior(const char*, const char*, const char*, double, int, int, int, int, const char*);
	//конструктор с параметрами
	char* get_current_role();//возращает текущую роль
	void set_current_role(const char*);//утсановить текущую роль
	
	void edit();//редактирование	
	const string get_file();//получает путь файла
	void HEADER();//шапка для таблицы
	friend istream& operator> (istream& Cin, senior& point);//перегрузка ввода
	friend ostream& operator< (ostream& Cout, senior& point);
	friend ofstream& operator<< (ofstream& out, senior& point);//перегрузка вывода для записи в файл
	friend ifstream& operator>> (ifstream& Cin, senior& point);//перегрузка ввода для записи в файл
};