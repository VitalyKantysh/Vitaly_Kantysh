#pragma once
#include "Header.h"
#include "Company.h"
#include "junior.h"
#include "middle.h"
#include "senior.h"
#include "Supervisors.h"
#include "teamlid.h"
#include "Workers.h"
#include "exception_file.h"

template<class T>
struct Line {
	T obj; //элемент
	Line<T>* next; //указатель на следующий элемент
	Line<T>* prev; //указатель на предыдующий элемент
};
template<class T>
class List {
	Line<T>* begin; //указатель на начало списка
	Line<T>* end; //указатель на конец списка
	int count; //количество элементов
public:
	List();//конструктор без параметров
	void push(const T&); //добавить элемент в начало
	void pushBack(const T&);//добавить элемент в конец
	T dellOne(); //удалить элемент с начала
	T dellOneBack(); //удалить элемент с конца
	void show();//метод, выводящий все элемента списка с начала
	void showBack();//метод, выводящий все элемента списка с конца
	void showSolary();//метод, показывающий зарплату всем сотрудникам
	void dellAll();//удалить все элементы
	int getCount();//метод, возвращающий поле count
	bool isEmpty(); //метод, проверяющий список на пустоту
	void readFile(string);  //чтение данных из файла
	void writeFile(string); //запись данных в файл
	T& pushElement(int index);
	T dellPoint(Line<T>*);//удаление заданного элемента
	Line<T>* operator [] (int); //перегрузка оператора []
	void searchPost(const char*);//поиск по занимаемой должности
	void searchName(const char*);//поиск по имени
	void searchLastname(const char*);//поиск по фамилии
	void searchDays(int);//поиск по количеству отработанных дней
	~List();//деструктор без параметров
};

template<class T>
T& List<T>::pushElement(int index)
{
	Line<T>* temp;
	temp = begin;
	if (index == 0)
	{
	}
	else {
		for (int i = 0; i < index; i++)
			temp = temp->next;
	}	
	return temp->obj;
}
template<class T>
void List<T>::writeFile(string fileName) {//запись в файл
	ofstream fout;
	Line<T>* current = begin;
	T element;
	int i = 0;

	try {
		fout.open(fileName, ios::out);
		if (!fout.is_open())
			throw exception_file("!!Не удалось открыть файл!!", fileName, 4362);

		for (int i = 0; i < count; i++)
		{
			element = pushElement(i);
			fout << element << endl;
		}

		fout.close();
	}
	catch (exception_file& ob)
	{
		cout << endl << ob.what() << endl << "Файл, который не удалось открыть : \"" << ob.get_file() << "\"" <<
			endl << "Код ошибки : " << ob.get_code() << endl << endl;
		exit(1);
	}
	catch (...) {
		cout << endl << "Непредвиденная ошибка!" << endl;
		exit(1);
	}
	//ofstream fout(fileName,ios::out);	
	////out значит что кажый раз при записи мы очищаем список 
	//Line<T>* current = begin;
	//while (current != NULL) {//пробегаем лист
	//	fout << current->obj << endl;//записываем каждый элемент в файл
	//	current = current->next;
	//}
	//fout.close();//закрыть файл
}

template<class T>
void List<T>::readFile(string fileName) {
	int i = 0;
	ifstream fin;
	T temp;
	try {
		fin.open(fileName, ios::in);
		if (!fin.is_open())
			throw exception_file("!!Не удалось открыть файл!!", fileName, 4561);

		while (fin >> temp)
		{
			this->push(temp);
		}
		fin.close();
	}
	catch (exception_file& ob)
	{
		cout << endl << ob.what() << endl << "Файл, который не удалось открыть : \"" << ob.get_file() << "\"" <<
			endl << "Код ошибки : " << ob.get_code() << endl << endl;
		cout << "Продолжить?(0-выход, любое другое число-продолжить)\n->";
		cin >> i;
		if (i == 0)
			exit(1);
		system("pause");
		system("cls");
		rewind(stdin); //Функция rewind() перемещает указатель положения в файле на начало указанного потока. Она также сбрасывает флаги конца файла и ошибки, связанные со stream. Она возвращает 0 в случае успеха и ненулевое значение в противном случае.
	}
	catch (...) {
		cout << endl << "Непредвиденная ошибка!" << endl;
		exit(1);
	}
}

template<class T>
void List<T>::searchDays(int num_days) {//поиск по количеству отработанных дней
	int index = 0;
	Line<T>* current = nullptr;//инициализация пустого Line
	current = end;//так как current = nullptr то надо переместить указатель на конец
	while (current != NULL) {
		if (current->obj.get_num_days() >= num_days) {
			//если num_days будет равен введенному значению  
			index++;//пока не пробежим весь лист
			if (index == 1) {
				current->obj.HEADER();//чтобы шапка вывелась только 1 раз
			}
			cout<current->obj;//вывод
			cout << endl;
		}
		current = current->prev;//указатель на предыдущий элемент
	}
	if (index == 0) {
		cout << "Элементы с таким именем не существуют!" << endl;
	}
}
template<class T>
void List<T>::searchLastname(const char* lastname) {//поиск по фамилии
	int index = 0;
	Line<T>* current = nullptr;//инициализация пустого Line
	current = end;//так как current = nullptr то надо переместить указатель на конец
	while (current != NULL) {
		if (strcmp(current->obj.get_last_name(), lastname) == 0) {
			//если lastname будет равен введенному значению  
			index++;//пока не пробежим весь лист
			if (index == 1) {
				current->obj.HEADER();//чтобы шапка вывелась только 1 раз
			}
			cout < current->obj;//вывод
			cout << endl;
		}
		current = current->prev;//указатель на предыдущий элемент
	}
	if (index == 0) {
		cout << "Элементы с таким именем не существуют!" << endl;
	}
}
template<class T>
void List<T>::searchName(const char* firstname) {//поиск по имени
	int index = 0;
	Line<T>* current = nullptr;//инициализация пустого Line
	current = end;//так как current = nullptr то надо переместить указатель на конец
	while (current != NULL) {
		if (strcmp(current->obj.get_first_name(), firstname) == 0) {
			//если firstname будет равен введенному значению  
			index++;//пока не пробежим весь лист
			if (index == 1) {
				current->obj.HEADER();//чтобы шапка вывелась только 1 раз
			}
			cout < current->obj;//вывод
			cout << endl;
		}
		current = current->prev;//указатель на предыдущий элемент
	}
	if (index == 0) {
		cout << "Элементы с таким именем не существуют!" << endl;
	}
}
template<class T>
void List<T>::searchPost(const char* post) {//поиск по занимаемой должности
	int index = 0;
	Line<T>* current = nullptr;//инициализация пустого Line
	current = end;//так как current = nullptr то надо переместить указатель на конец
	while(current != NULL) {
		if (strcmp(current->obj.get_post(), post) == 0) {
			//если post будет равен введенному значению
			index++;//пока не пробежим весь лист
			if (index == 1) {
				current->obj.HEADER();//чтобы шапка вывелась только 1 раз
			}
			cout < current->obj;//вывод
			cout << endl;
		}
		current = current->prev;//указатель на предыдущий элемент
	}
	if (index == 0)	{
		cout << "Элементы с таким именем не существуют!" << endl;
	}
}
template<class T>
Line<T>* List<T>::operator[] (int id) {
	//перегрузка оператора[] чтобы можно было получить определенный элемент
	Line<T>* current = nullptr;//инициализация пустого Line
	current = end;//так как current = nullptr то надо переместить указатель на конец
	int index = 1;
	while (id != index)	{//пока не пробежим лист до id
		if (current->prev != NULL) {//если лист больше id
			current = current->prev;//указатель на предыдущий элемент
		}
		index++;
	}
	return current;//возращаем текущий элемент
}
template<class T>
T List<T>::dellPoint(Line<T>* obj) {//удаление определенного элемента
	Line<T>* temp, * tempn, data;
	count--;
	if (obj == begin && obj != end)	{
		//если obj равен началу списка и не равен концу(не равен 1 или 0)
		tempn = obj->next;//пробегаем список удаляем 1 элемент
		tempn->prev = NULL;
		begin = tempn;
		data.obj = obj->obj;
		delete obj;
	}
	else if (obj == end && obj != begin) {
		//если obj равен концу списка и не равен началу(не равен 1 или 0)
		temp = obj->prev;//пробегаем список и удаляем последний элемент
		temp->next = obj->next;
		end = temp;
		data.obj = obj->obj;
		delete obj;
	}
	else if (obj == end && obj == begin) {
		//если obj равен началу списка и равен концу(равен 1)
		temp = obj;//пробегаем список удаляем единственный элемент
		data.obj = obj->obj;
		delete end;
		end = begin = NULL;
	}
	else {
		//если obj не первый и не последний и не единственный элемент
		temp = obj->prev;//пробегаем список
		tempn = obj->next;
		temp->next = tempn;
		tempn->prev = temp;
		data.obj = obj->obj;
		delete obj;//удаляем заданный элемент
	}
	return data.obj;//возращаем измененный лист
}
template<class T>
void List<T>::dellAll() {//удалить весь лист
	Line<T>* tmp = nullptr;//инициализация пустого Line
	if (begin != NULL) {//если список не пустой
		while (begin != NULL) {//пока не пройдем весь список
			tmp = begin->next;//пробегаем удаеляем все элементы
			delete begin;
			begin = tmp;
		}
	}
}
template<class T>
int List<T>::getCount() {//получить счетчик элементов
	return this->count;
}

template<class T>
T List<T>::dellOne() {//удалить элемент с начала списка
	if (end == begin) {//если конец равен началу(равен 1)
		count--;//уменьшаем счетчик
		Line<T> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;//удаляем единственный элемент
		return data.obj;//возращаем измененный лист
	}
	else {
		Line<T>* current = nullptr;//инициализация пустого Line
		count--;//уменьшаем счетчик
		Line<T> data;
		current = end->prev;
		current->next = NULL;
		data.obj = end->obj;
		delete end;//удаляем элемент с начала списка
		end = current;
		return data.obj;//возращаем измененный лист
	}
}

template<class T>
bool List<T>::isEmpty() {//пустой ли файл
	if (begin != NULL) {//если файл не пуст возращаем true
		return true;
	}
	else {//если файл пуст возращаем false
		return false;
	}
}
template<class T>
T List<T>::dellOneBack() {//удалить элемент с конча списка
	if (end == begin) {//если конец равен началу(равен 1)
		count--;//уменьшаем счетчик
		Line<T> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;//удаляем единственный элемент
		return data.obj;//возращаем измененный лист
	}
	else {
		Line<T>* current = nullptr;//инициализация пустого Line
		Line<T> data;
		count--;//уменьшаем счетчик
		current = begin->next;
		current->prev = NULL;
		data.obj = end->obj;
		delete begin;//удаляем элемент с конца списка
		begin = current;
		return data.obj;//возращаем измененный лист
	}
}
template<class T>
List<T>::List() {//конструктор по умолчанию
	count = 0;//счетчик 0 тк нет элементов
	begin = NULL;//нет начала тк нет элементов
	end = NULL;//нет конца тк нет элементов
}
template<class T>
void List<T>::showBack() {//показать элементы с конца
	Line<T>* current = nullptr;//инициализация пустого Line
	current = begin;
	cout<current->obj;//вывод
	cout << endl;
	while (current->next != NULL) {//проходим весь лист 
		current = current->next;//указатель на следующий
		cout<current->obj;//вывод
		cout << endl;
	}
}
template<class T>
List<T>::~List() {//деструктор
	dellAll();//удалить все
}
template<class T>
void List<T>::showSolary() {//показает зп всех сотрудников с начала списка
	Line<T>* current = nullptr;//инициализация пустого Line
	current = end;
	current->obj.HEADER_SOLARY();//вывод шапки для счета зп
	current->obj.print_solary();//вывод зп всех сотрудников
	cout << endl;
	while (current->prev != NULL) {//проходим весь лист 
		current = current->prev;//указатель на предыдущий
		current->obj.print_solary();//вывод зп всех сотрудников
		cout << endl;
	}
}
template<class T>
void List<T>::show() {//показать элементы с начала
	Line<T>* current = nullptr;//инициализация пустого Line
	current = end;
	cout < current->obj;//вывод
	cout << endl;
	while (current->prev != NULL) {//проходим весь лист 
		current = current->prev;//указатель на предыдущий
		cout<current->obj;//вывод
		cout << endl;
	}
}
template<class T>
void List<T>::push(const T& obj) {//добавить в лист объект с начала
	count++;//увеличить счетчик
	Line<T>* temp = new Line<T>;//инициализация temp
	temp->next = NULL;//указатель на следующий NULL
	Line<T>* current = nullptr;//инициализация current
	temp->obj = obj;
	if (begin != NULL) {//если begin не равен 0
		temp->prev = end;
		end->next = temp;
		end = temp;
		current = end;//перемещаем temp в начало списка
	}
	else {//если нет элементов
		temp->prev = NULL;
		begin = end = temp;//присваиваем temp к началу и концу
	}
}
template<class T>
void List<T>::pushBack(const T& obj) {//добавить в лист объект с конца
	Line<T>* current = nullptr;//инициализация current
	Line<T>* temp = new Line<T>;//инициализация temp
	temp->prev = NULL;//указатель на предыдуший NULL
	current = NULL;
	temp->obj = obj;
	count++;//увеличить счетчик
	if (begin != NULL) {//если begin не равен 0
		begin->prev = temp;
		temp->next = begin;
		begin = temp;
		current = begin;//перемещаем temp в конец списка
	}
	else {//если нет элементов
		temp->next = NULL;
		begin = end = temp;//присваиваем temp к началу и концу
	}
}	