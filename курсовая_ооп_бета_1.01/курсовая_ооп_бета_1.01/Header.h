#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

const int N = 40;
const int NAME_SIZE = 20;

void menu_worker();//меню дл€ добавлени€ 
void menu_object();//меню дл€ выбора объекта
void menu_();//главное меню
void del_menu();//меню дл€ удалени€
void edit_menu_senior();//меню дл€ редактировани€ senior
void edit_menu_middle();//меню дл€ редактировани€ middle
void edit_menu_junior();//меню дл€ редактировани€ junior
void edit_menu_teamlid();//меню дл€ редактировани€ teamlid
void search_menu();//меню дл€ поиска
const char* engSymInput(istream&, const char*);
const char* engSymAndNumInput(istream& Cin, const char* nameSubject);
int inputNumber(istream& in, int min, int max, const char* nameSubject);
bool isNumberNumeric();
bool isNumberRangeCorrect(int number, int left_range, int right_range);

const string FILE_SENIOR = "C://Users//kanty//source//repos//курсова€_ооп_бета_1.01//senior.txt";
//путь файла senior.txt
const string FILE_JUNIOR = "C://Users//kanty//source//repos//курсова€_ооп_бета_1.01//junior.txt";
//путь файла junior.txt
const string FILE_MIDDLE = "C://Users//kanty//source//repos//курсова€_ооп_бета_1.01//middle.txt";
//путь файла middle.txt
const string FILE_TEAMLID = "C://Users//kanty//source//repos//курсова€_ооп_бета_1.01//teamlid.txt";
//путь файла teamlid.txt