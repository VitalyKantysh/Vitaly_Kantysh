#include "Header.h"
#include "Company.h"
#include "junior.h"
#include "middle.h"
#include "senior.h"
#include "Supervisors.h"
#include "teamlid.h"
#include "Workers.h"
#include "List.h"
void menu_worker() {//���� ��� ���������� 
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - �������� ������� � ������ ������                               |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - �������� ������� � ����� ������                                |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}
void menu_object() {//���� ��� ������ �������
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - ����������� ��������� senior                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - ����������� ��������� junior                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - ����������� ��������� middle                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - ����������� ��������� teamlid                                  |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}
void menu_() {//������� ����
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - ������ ����������                                              |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - ������� ����������                                             |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - ������ � ����                                                  |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - ����������� ������ ���� �����������                            |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  5 - ��������� �������� ���� �����������                            |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  6 - ��������������                                                 |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  7 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - exit                                                           |\n";
	cout << "|_____________________________________________________________________|\n";
}
void del_menu() {//���� ��� ��������
	cout << " ____________________________________________________________________\n";
	cout << "|  1 - ������� ������� � ������ ������                                |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - ������� ������� � ����� ������                                 |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - ������� ������������ ������� ������                            |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - ������� ��� �������� ������                                    |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}
void search_menu() {//���� ��� ������
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - ������ �� �����                                                |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - ������ �� �������                                              |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - ������ �� ���������                                            |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - ������ �� ���������� ������������ ���� � ������                |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}
void edit_menu_junior() {//���� ��� �������������� junior
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - �������� ���                                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - �������� �������                                               |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - �������� ���������� ���������                                  |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - �������� ���������� ������������� ����                         |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  5 - �������� ������� ��������                                      |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  6 - �������� ������� ������                                        |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  7 - �������� ������                                                |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  8 - �������� ���������� ����������� ����                           |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  9 - �������� ������ �����������                                    |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}
void edit_menu_middle() {//���� ��� �������������� middle
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - �������� ���                                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - �������� �������                                               |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - �������� ���������� ���������                                  |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - �������� ���������� ������������� ����                         |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  5 - �������� ������� ��������                                      |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  6 - �������� ������� ������                                        |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  7 - �������� ������                                                |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  8 - �������� ���������� ����������� ����                           |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  9 - �������� ���������� ��������                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}
void edit_menu_teamlid() {//���� ��� �������������� teamlid
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - �������� ���                                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - �������� �������                                               |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - �������� ���������� ���������                                  |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - �������� ���������� ������������� ����                         |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  5 - �������� ������� ��������                                      |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  6 - �������� ���������� ��������                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  7 - �������� �������                                               |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  8 - �������� �����                                                 |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  9 - �������� ���������� �����������                                |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}
void edit_menu_senior() {//���� ��� �������������� senior
	cout << " _____________________________________________________________________\n";
	cout << "|  1 - �������� ���                                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  2 - �������� �������                                               |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  3 - �������� ���������� ���������                                  |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  4 - �������� ���������� ������������� ����                         |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  5 - �������� ������� ��������                                      |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  6 - �������� ���������� ��������                                   |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  7 - �������� �������                                               |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  8 - �������� �����                                                 |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  9 - �������� ������� ����                                          |\n";
	cout << "|_____________________________________________________________________|\n";
	cout << "|  0 - �����                                                          |\n";
	cout << "|_____________________________________________________________________|\n";
}