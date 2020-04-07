#pragma once
#include "Header.h"
#include "Company.h"
#include "junior.h"
#include "middle.h"
#include "senior.h"
#include "Supervisors.h"
#include "teamlid.h"
#include "Workers.h"
#include "List.h"

template<class T>
class Interface {
public:
	Interface() {}
	~Interface() {}
	void menu();//������� ����
	void menu_file();//���� ��� ������ �������
};
template<class T>
void Interface<T>::menu_file() {//���� ��� ������ �������
	system("color 02");//������������� ���� �������
	setlocale(LC_ALL, "rus");//������� ���������
	SetConsoleCP(1251);//������ ��������� � �������
	SetConsoleOutputCP(1251);//������� ��������� � �������	
	int choice;
	menu_object();
	cin >> choice;
	switch (choice) {
	case 1:
	{
		Interface<senior>ob1;
		ob1.menu();
	}
		break;
	case 2:
	{
		Interface<junior>ob1;
		ob1.menu();
	}
		break;
	case 3:
	{
		Interface<middle>ob1;
		ob1.menu();
	}
		break;
	case 4:
	{
		Interface<teamlid>ob1;
		ob1.menu();
	}
		break;
	case 0:
		return;
		break;
	}
}
template<class T>
void Interface<T>::menu() {//������� ����
	system("pause");//�����
	system("cls");//������� �������
	T ob1;
	const string file = ob1.get_file();//�������� ���� ����� � ����������� �� �������
	List<T> lst;
	lst.readFile(file);	
	bool exit = false, exit_local = false, exit_search = false, exit_ = false;
	int choice, num;
	char str[N];	
	while (exit == false) {
		menu_();
		cin >> choice;
		switch (choice) {
		case 1:
			system("pause");//�����
			system("cls");//������� �������
			exit_local = false;
			while (exit_local == false) {
				menu_worker();
				cin >> choice;
				switch (choice) {
				case 1:
					cin.ignore(256, '\n');//������� ���� 
		  			cin > ob1;
					lst.push(ob1);//�������� ob1 � ����
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 2:
					cin.ignore(256, '\n');
					cin > ob1;
					lst.pushBack(ob1);
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 0:
					system("pause");//�����
					system("cls");//������� �������
					exit_local = true;
					break;
				default:
					cout << "�������� ����!" << endl;
				}
			}
			break;
		case 2:
			system("pause");//�����
			system("cls");//������� �������
			exit_local = false;
			while (exit_local == false) {
				del_menu();
				cin >> choice;
				switch (choice) {
				case 1:					
					lst.dellOne();
					cout << "\n������� �������!\n";
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 2:
					lst.dellOneBack();
					cout << "\n������� �������!\n";
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 3:
					ob1.HEADER();//�������� ����� � ����������� �� �������
					lst.show();//������� �������
					cout << "\n������� ����� ����������\n->";
					cin >> choice;
					lst.dellPoint(lst[choice]);//������� ������������ ������� � ������� ��������� []
					cout << "\n������� �������!\n";
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 4:
					lst.dellAll();//������� ���
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 0:
					system("pause");//�����
					system("cls");//������� �������
					exit_local = true;
					break;
				default:
					cout << "�������� ����!" << endl;
				}
			}
			break;
		case 3:
			lst.writeFile(file);//������ � ���� 
			cout << "\n������� ��������!\n";
			system("pause");//�����
			system("cls");//������� �������
			break;
		case 4:
			system("cls");//������� �������
			ob1.HEADER();//�������� ����� � ����������� �� �������
			lst.show();//������� ������ � ���� ������� 
			system("pause");//�����
			system("cls");//������� �������
			break;
		case 5:
			system("cls");//������� �������
			lst.showSolary();//������� �������� ���� �����������
			system("pause");//�����
			system("cls");//������� �������
			break;
		case 6:
			system("cls");//������� �������
			exit_ = false;
			ob1.HEADER();//�������� ����� � ����������� �� �������
			lst.show();//������� ������ � ���� ������� 
			cout << "������� ����� ������������� ������\n->";
			cin >> choice;
			lst[choice]->obj.edit();//�������� ����� edit() � ������������� �������
			//while (exit_ == false) {		
			//	cout << "����������?(1-��,����� ������-���)\n->";
			//	cin >> num;
			//	if (num == 1) {
			//		ob1.HEADER();//�������� ����� � ����������� �� �������
			//		lst[choice]->obj.print();//������� ������ � ���� ������� � ����������� �� �������
			//		lst[choice]->obj.edit();//�������� ����� edit() � ������������� �������
			//	}
			//	else {
			//		exit_ = true;
			//	}				
			//}
			system("pause");//�����
			system("cls");//������� �������
			break;
		case 7:
			system("cls");//������� �������
			exit_search = false;
			while (exit_search == false) {
				search_menu();
				cin >> choice;
				switch (choice) {
				case 1:
					cout << "������� ���\n->";
					cin >> str;
					lst.searchName(str);//�����
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 2:
					cout << "������� �������\n->";
					cin >> str;
					lst.searchLastname(str);//�����
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 3:
					cout << "������� ���������\n->";
					cin >> str;
					lst.searchPost(str);//�����
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 4:
					cout << "������� ���������� ������������ ���� � ������\n->";
					cin >> num;
					lst.searchDays(num);//�����
					system("pause");//�����
					system("cls");//������� �������
					break;
				case 0:
					exit_search = true;
					break;
				default:
					cout << "�������� ����!\n";
					system("pause");//�����
					system("cls");//������� �������
				}
			}
			system("pause");//�����
			system("cls");//������� �������
			break;
		case 0:
			exit = true;
			break;
		default:
			cout << "�������� ����!" << endl;
			system("pause");//�����
			system("cls");//������� �������
		}
	}
}