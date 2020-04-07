#pragma once
#include "Workers.h"
class junior : public Workers {
protected:
	char education[N];//образование
public:
	junior();//конструктор без параметров
	junior(const char*, const char*, const char*, double, int, const char*, int, int, const char*);
	//конструктор с параметрами
	char* get_education();//возращает образование
	void set_education(const char*);//устанавливает образование

	void HEADER();//шапка для таблицы
	void edit();//редактирование
	const string get_file();//получает путь файла
	friend istream& operator> (istream& Cin, junior& point);//перегрузка ввода
	friend ostream& operator< (ostream& Cin, junior& point);
	friend ofstream& operator<< (ofstream& out, junior& point);//перегрузка вывода для записи в файл
	friend ifstream& operator>> (ifstream& Cin, junior& point);//перегрузка ввода для записи в файл
};