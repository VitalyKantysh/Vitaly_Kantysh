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
	void menu();//главное меню
	void menu_file();//меню для выбора объекта
};
template<class T>
void Interface<T>::menu_file() {//меню для выбора объекта
	system("color 02");//устанавливает цвет консоли
	setlocale(LC_ALL, "rus");//русская раскладка
	SetConsoleCP(1251);//руская раскладка в консоли
	SetConsoleOutputCP(1251);//русская раскладка в консоли	
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
void Interface<T>::menu() {//главное меню
	system("pause");//пауза
	system("cls");//очищает консоль
	T ob1;
	const string file = ob1.get_file();//получить путь файла в зависимости от объекта
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
			system("pause");//пауза
			system("cls");//очищает консоль
			exit_local = false;
			while (exit_local == false) {
				menu_worker();
				cin >> choice;
				switch (choice) {
				case 1:
					cin.ignore(256, '\n');//очищает ввод 
		  			cin > ob1;
					lst.push(ob1);//добавить ob1 в лист
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 2:
					cin.ignore(256, '\n');
					cin > ob1;
					lst.pushBack(ob1);
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 0:
					system("pause");//пауза
					system("cls");//очищает консоль
					exit_local = true;
					break;
				default:
					cout << "Неверный ввод!" << endl;
				}
			}
			break;
		case 2:
			system("pause");//пауза
			system("cls");//очищает консоль
			exit_local = false;
			while (exit_local == false) {
				del_menu();
				cin >> choice;
				switch (choice) {
				case 1:					
					lst.dellOne();
					cout << "\nУспешно удалено!\n";
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 2:
					lst.dellOneBack();
					cout << "\nУспешно удалено!\n";
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 3:
					ob1.HEADER();//вызывает шапку в зависимости от объекта
					lst.show();//выводит таблицу
					cout << "\nВведите номер сотрудника\n->";
					cin >> choice;
					lst.dellPoint(lst[choice]);//удаляет определенный элемент с помощью оператора []
					cout << "\nУспешно удалено!\n";
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 4:
					lst.dellAll();//удаляет все
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 0:
					system("pause");//пауза
					system("cls");//очищает консоль
					exit_local = true;
					break;
				default:
					cout << "Неверный ввод!" << endl;
				}
			}
			break;
		case 3:
			lst.writeFile(file);//запись в файл 
			cout << "\nУспешно записано!\n";
			system("pause");//пауза
			system("cls");//очищает консоль
			break;
		case 4:
			system("cls");//очищает консоль
			ob1.HEADER();//вызывает шапку в зависимости от объекта
			lst.show();//выводит данные в виде таблицы 
			system("pause");//пауза
			system("cls");//очищает консоль
			break;
		case 5:
			system("cls");//очищает консоль
			lst.showSolary();//вывести зарплату всех сотрудников
			system("pause");//пауза
			system("cls");//очищает консоль
			break;
		case 6:
			system("cls");//очищает консоль
			exit_ = false;
			ob1.HEADER();//вызывает шапку в зависимости от объекта
			lst.show();//выводит данные в виде таблицы 
			cout << "Введите номер редактируемой записи\n->";
			cin >> choice;
			lst[choice]->obj.edit();//вызывает метод edit() у определенного объекта
			//while (exit_ == false) {		
			//	cout << "Продолжить?(1-да,любое другое-нет)\n->";
			//	cin >> num;
			//	if (num == 1) {
			//		ob1.HEADER();//вызывает шапку в зависимости от объекта
			//		lst[choice]->obj.print();//выводит данные в виде таблицы в зависимости от объекта
			//		lst[choice]->obj.edit();//вызывает метод edit() у определенного объекта
			//	}
			//	else {
			//		exit_ = true;
			//	}				
			//}
			system("pause");//пауза
			system("cls");//очищает консоль
			break;
		case 7:
			system("cls");//очищает консоль
			exit_search = false;
			while (exit_search == false) {
				search_menu();
				cin >> choice;
				switch (choice) {
				case 1:
					cout << "Введите имя\n->";
					cin >> str;
					lst.searchName(str);//поиск
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 2:
					cout << "Введите фамилию\n->";
					cin >> str;
					lst.searchLastname(str);//поиск
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 3:
					cout << "Введите должность\n->";
					cin >> str;
					lst.searchPost(str);//поиск
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 4:
					cout << "Введите количество отработанных дней в месяце\n->";
					cin >> num;
					lst.searchDays(num);//поиск
					system("pause");//пауза
					system("cls");//очищает консоль
					break;
				case 0:
					exit_search = true;
					break;
				default:
					cout << "Неверный ввод!\n";
					system("pause");//пауза
					system("cls");//очищает консоль
				}
			}
			system("pause");//пауза
			system("cls");//очищает консоль
			break;
		case 0:
			exit = true;
			break;
		default:
			cout << "Неверный ввод!" << endl;
			system("pause");//пауза
			system("cls");//очищает консоль
		}
	}
}