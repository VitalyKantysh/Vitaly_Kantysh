#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

const int N = 40;
const int NAME_SIZE = 20;

void menu_worker();//���� ��� ���������� 
void menu_object();//���� ��� ������ �������
void menu_();//������� ����
void del_menu();//���� ��� ��������
void edit_menu_senior();//���� ��� �������������� senior
void edit_menu_middle();//���� ��� �������������� middle
void edit_menu_junior();//���� ��� �������������� junior
void edit_menu_teamlid();//���� ��� �������������� teamlid
void search_menu();//���� ��� ������
const char* engSymInput(istream&, const char*);
const char* engSymAndNumInput(istream& Cin, const char* nameSubject);
int inputNumber(istream& in, int min, int max, const char* nameSubject);
bool isNumberNumeric();
bool isNumberRangeCorrect(int number, int left_range, int right_range);

const string FILE_SENIOR = "C://Users//kanty//source//repos//��������_���_����_1.01//senior.txt";
//���� ����� senior.txt
const string FILE_JUNIOR = "C://Users//kanty//source//repos//��������_���_����_1.01//junior.txt";
//���� ����� junior.txt
const string FILE_MIDDLE = "C://Users//kanty//source//repos//��������_���_����_1.01//middle.txt";
//���� ����� middle.txt
const string FILE_TEAMLID = "C://Users//kanty//source//repos//��������_���_����_1.01//teamlid.txt";
//���� ����� teamlid.txt