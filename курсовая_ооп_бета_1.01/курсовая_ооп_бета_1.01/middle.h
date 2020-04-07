#pragma once
#include "Workers.h"
class middle : public Workers {
protected:
	int num_of_projects;//количество проектов
public:	
	middle();//конструктор без параметров
	middle(const char*, const char*,  const char*, double, int, const char*, int, int, int);
	//конструктор с параметрами
	int get_num_of_projects();//получить количество проектов
	void set_num_of_projects(int);//изменить количество проектов
	
	void HEADER();//шапка для таблицы
	void edit();//редактирование
	const string get_file();//получает путь файла
	friend istream& operator> (istream& Cin, middle& point);//перегрузка ввода
	friend ostream& operator< (ostream& Cout, middle& point);//перегрузка ввода
	friend ofstream& operator<< (ofstream& out, middle& point);//перегрузка вывода для записи в файл
	friend ifstream& operator>> (ifstream& Cin, middle& point);//перегрузка ввода для записи в файл
};