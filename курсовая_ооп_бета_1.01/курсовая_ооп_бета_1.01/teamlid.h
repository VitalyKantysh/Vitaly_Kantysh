#pragma once
#include "Supervisors.h"
class teamlid :	public Supervisors {
protected:
	int num_people;//количество подчиненных
public:	
	teamlid();//конструктор без параметров
	teamlid(const char*, const char*, const char*, double, int, int, int, int, int);
	//конструктор с параметрами
	int get_num_people();//возращает количество подчиненных
	void set_num_people(int);//устанавливает количество подчиненных
	
	void HEADER();//шапка для таблицы
	void edit();//редактирование
	const string get_file();//получает путь файла
	friend istream& operator> (istream& Cin, teamlid& point);//перегрузка ввода
	friend ostream& operator< (ostream& Cin, teamlid& point);
	friend ofstream& operator<< (ofstream& out, teamlid& point);//перегрузка вывода для записи в файл
	friend ifstream& operator>> (ifstream& Cin, teamlid& point);//перегрузка ввода для записи в файл
};	