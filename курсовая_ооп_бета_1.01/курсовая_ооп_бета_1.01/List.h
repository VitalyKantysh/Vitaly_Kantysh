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
	T obj; //�������
	Line<T>* next; //��������� �� ��������� �������
	Line<T>* prev; //��������� �� ����������� �������
};
template<class T>
class List {
	Line<T>* begin; //��������� �� ������ ������
	Line<T>* end; //��������� �� ����� ������
	int count; //���������� ���������
public:
	List();//����������� ��� ����������
	void push(const T&); //�������� ������� � ������
	void pushBack(const T&);//�������� ������� � �����
	T dellOne(); //������� ������� � ������
	T dellOneBack(); //������� ������� � �����
	void show();//�����, ��������� ��� �������� ������ � ������
	void showBack();//�����, ��������� ��� �������� ������ � �����
	void showSolary();//�����, ������������ �������� ���� �����������
	void dellAll();//������� ��� ��������
	int getCount();//�����, ������������ ���� count
	bool isEmpty(); //�����, ����������� ������ �� �������
	void readFile(string);  //������ ������ �� �����
	void writeFile(string); //������ ������ � ����
	T& pushElement(int index);
	T dellPoint(Line<T>*);//�������� ��������� ��������
	Line<T>* operator [] (int); //���������� ��������� []
	void searchPost(const char*);//����� �� ���������� ���������
	void searchName(const char*);//����� �� �����
	void searchLastname(const char*);//����� �� �������
	void searchDays(int);//����� �� ���������� ������������ ����
	~List();//���������� ��� ����������
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
void List<T>::writeFile(string fileName) {//������ � ����
	ofstream fout;
	Line<T>* current = begin;
	T element;
	int i = 0;

	try {
		fout.open(fileName, ios::out);
		if (!fout.is_open())
			throw exception_file("!!�� ������� ������� ����!!", fileName, 4362);

		for (int i = 0; i < count; i++)
		{
			element = pushElement(i);
			fout << element << endl;
		}

		fout.close();
	}
	catch (exception_file& ob)
	{
		cout << endl << ob.what() << endl << "����, ������� �� ������� ������� : \"" << ob.get_file() << "\"" <<
			endl << "��� ������ : " << ob.get_code() << endl << endl;
		exit(1);
	}
	catch (...) {
		cout << endl << "�������������� ������!" << endl;
		exit(1);
	}
	//ofstream fout(fileName,ios::out);	
	////out ������ ��� ����� ��� ��� ������ �� ������� ������ 
	//Line<T>* current = begin;
	//while (current != NULL) {//��������� ����
	//	fout << current->obj << endl;//���������� ������ ������� � ����
	//	current = current->next;
	//}
	//fout.close();//������� ����
}

template<class T>
void List<T>::readFile(string fileName) {
	int i = 0;
	ifstream fin;
	T temp;
	try {
		fin.open(fileName, ios::in);
		if (!fin.is_open())
			throw exception_file("!!�� ������� ������� ����!!", fileName, 4561);

		while (fin >> temp)
		{
			this->push(temp);
		}
		fin.close();
	}
	catch (exception_file& ob)
	{
		cout << endl << ob.what() << endl << "����, ������� �� ������� ������� : \"" << ob.get_file() << "\"" <<
			endl << "��� ������ : " << ob.get_code() << endl << endl;
		cout << "����������?(0-�����, ����� ������ �����-����������)\n->";
		cin >> i;
		if (i == 0)
			exit(1);
		system("pause");
		system("cls");
		rewind(stdin); //������� rewind() ���������� ��������� ��������� � ����� �� ������ ���������� ������. ��� ����� ���������� ����� ����� ����� � ������, ��������� �� stream. ��� ���������� 0 � ������ ������ � ��������� �������� � ��������� ������.
	}
	catch (...) {
		cout << endl << "�������������� ������!" << endl;
		exit(1);
	}
}

template<class T>
void List<T>::searchDays(int num_days) {//����� �� ���������� ������������ ����
	int index = 0;
	Line<T>* current = nullptr;//������������� ������� Line
	current = end;//��� ��� current = nullptr �� ���� ����������� ��������� �� �����
	while (current != NULL) {
		if (current->obj.get_num_days() >= num_days) {
			//���� num_days ����� ����� ���������� ��������  
			index++;//���� �� �������� ���� ����
			if (index == 1) {
				current->obj.HEADER();//����� ����� �������� ������ 1 ���
			}
			cout<current->obj;//�����
			cout << endl;
		}
		current = current->prev;//��������� �� ���������� �������
	}
	if (index == 0) {
		cout << "�������� � ����� ������ �� ����������!" << endl;
	}
}
template<class T>
void List<T>::searchLastname(const char* lastname) {//����� �� �������
	int index = 0;
	Line<T>* current = nullptr;//������������� ������� Line
	current = end;//��� ��� current = nullptr �� ���� ����������� ��������� �� �����
	while (current != NULL) {
		if (strcmp(current->obj.get_last_name(), lastname) == 0) {
			//���� lastname ����� ����� ���������� ��������  
			index++;//���� �� �������� ���� ����
			if (index == 1) {
				current->obj.HEADER();//����� ����� �������� ������ 1 ���
			}
			cout < current->obj;//�����
			cout << endl;
		}
		current = current->prev;//��������� �� ���������� �������
	}
	if (index == 0) {
		cout << "�������� � ����� ������ �� ����������!" << endl;
	}
}
template<class T>
void List<T>::searchName(const char* firstname) {//����� �� �����
	int index = 0;
	Line<T>* current = nullptr;//������������� ������� Line
	current = end;//��� ��� current = nullptr �� ���� ����������� ��������� �� �����
	while (current != NULL) {
		if (strcmp(current->obj.get_first_name(), firstname) == 0) {
			//���� firstname ����� ����� ���������� ��������  
			index++;//���� �� �������� ���� ����
			if (index == 1) {
				current->obj.HEADER();//����� ����� �������� ������ 1 ���
			}
			cout < current->obj;//�����
			cout << endl;
		}
		current = current->prev;//��������� �� ���������� �������
	}
	if (index == 0) {
		cout << "�������� � ����� ������ �� ����������!" << endl;
	}
}
template<class T>
void List<T>::searchPost(const char* post) {//����� �� ���������� ���������
	int index = 0;
	Line<T>* current = nullptr;//������������� ������� Line
	current = end;//��� ��� current = nullptr �� ���� ����������� ��������� �� �����
	while(current != NULL) {
		if (strcmp(current->obj.get_post(), post) == 0) {
			//���� post ����� ����� ���������� ��������
			index++;//���� �� �������� ���� ����
			if (index == 1) {
				current->obj.HEADER();//����� ����� �������� ������ 1 ���
			}
			cout < current->obj;//�����
			cout << endl;
		}
		current = current->prev;//��������� �� ���������� �������
	}
	if (index == 0)	{
		cout << "�������� � ����� ������ �� ����������!" << endl;
	}
}
template<class T>
Line<T>* List<T>::operator[] (int id) {
	//���������� ���������[] ����� ����� ���� �������� ������������ �������
	Line<T>* current = nullptr;//������������� ������� Line
	current = end;//��� ��� current = nullptr �� ���� ����������� ��������� �� �����
	int index = 1;
	while (id != index)	{//���� �� �������� ���� �� id
		if (current->prev != NULL) {//���� ���� ������ id
			current = current->prev;//��������� �� ���������� �������
		}
		index++;
	}
	return current;//��������� ������� �������
}
template<class T>
T List<T>::dellPoint(Line<T>* obj) {//�������� ������������� ��������
	Line<T>* temp, * tempn, data;
	count--;
	if (obj == begin && obj != end)	{
		//���� obj ����� ������ ������ � �� ����� �����(�� ����� 1 ��� 0)
		tempn = obj->next;//��������� ������ ������� 1 �������
		tempn->prev = NULL;
		begin = tempn;
		data.obj = obj->obj;
		delete obj;
	}
	else if (obj == end && obj != begin) {
		//���� obj ����� ����� ������ � �� ����� ������(�� ����� 1 ��� 0)
		temp = obj->prev;//��������� ������ � ������� ��������� �������
		temp->next = obj->next;
		end = temp;
		data.obj = obj->obj;
		delete obj;
	}
	else if (obj == end && obj == begin) {
		//���� obj ����� ������ ������ � ����� �����(����� 1)
		temp = obj;//��������� ������ ������� ������������ �������
		data.obj = obj->obj;
		delete end;
		end = begin = NULL;
	}
	else {
		//���� obj �� ������ � �� ��������� � �� ������������ �������
		temp = obj->prev;//��������� ������
		tempn = obj->next;
		temp->next = tempn;
		tempn->prev = temp;
		data.obj = obj->obj;
		delete obj;//������� �������� �������
	}
	return data.obj;//��������� ���������� ����
}
template<class T>
void List<T>::dellAll() {//������� ���� ����
	Line<T>* tmp = nullptr;//������������� ������� Line
	if (begin != NULL) {//���� ������ �� ������
		while (begin != NULL) {//���� �� ������� ���� ������
			tmp = begin->next;//��������� �������� ��� ��������
			delete begin;
			begin = tmp;
		}
	}
}
template<class T>
int List<T>::getCount() {//�������� ������� ���������
	return this->count;
}

template<class T>
T List<T>::dellOne() {//������� ������� � ������ ������
	if (end == begin) {//���� ����� ����� ������(����� 1)
		count--;//��������� �������
		Line<T> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;//������� ������������ �������
		return data.obj;//��������� ���������� ����
	}
	else {
		Line<T>* current = nullptr;//������������� ������� Line
		count--;//��������� �������
		Line<T> data;
		current = end->prev;
		current->next = NULL;
		data.obj = end->obj;
		delete end;//������� ������� � ������ ������
		end = current;
		return data.obj;//��������� ���������� ����
	}
}

template<class T>
bool List<T>::isEmpty() {//������ �� ����
	if (begin != NULL) {//���� ���� �� ���� ��������� true
		return true;
	}
	else {//���� ���� ���� ��������� false
		return false;
	}
}
template<class T>
T List<T>::dellOneBack() {//������� ������� � ����� ������
	if (end == begin) {//���� ����� ����� ������(����� 1)
		count--;//��������� �������
		Line<T> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;//������� ������������ �������
		return data.obj;//��������� ���������� ����
	}
	else {
		Line<T>* current = nullptr;//������������� ������� Line
		Line<T> data;
		count--;//��������� �������
		current = begin->next;
		current->prev = NULL;
		data.obj = end->obj;
		delete begin;//������� ������� � ����� ������
		begin = current;
		return data.obj;//��������� ���������� ����
	}
}
template<class T>
List<T>::List() {//����������� �� ���������
	count = 0;//������� 0 �� ��� ���������
	begin = NULL;//��� ������ �� ��� ���������
	end = NULL;//��� ����� �� ��� ���������
}
template<class T>
void List<T>::showBack() {//�������� �������� � �����
	Line<T>* current = nullptr;//������������� ������� Line
	current = begin;
	cout<current->obj;//�����
	cout << endl;
	while (current->next != NULL) {//�������� ���� ���� 
		current = current->next;//��������� �� ���������
		cout<current->obj;//�����
		cout << endl;
	}
}
template<class T>
List<T>::~List() {//����������
	dellAll();//������� ���
}
template<class T>
void List<T>::showSolary() {//�������� �� ���� ����������� � ������ ������
	Line<T>* current = nullptr;//������������� ������� Line
	current = end;
	current->obj.HEADER_SOLARY();//����� ����� ��� ����� ��
	current->obj.print_solary();//����� �� ���� �����������
	cout << endl;
	while (current->prev != NULL) {//�������� ���� ���� 
		current = current->prev;//��������� �� ����������
		current->obj.print_solary();//����� �� ���� �����������
		cout << endl;
	}
}
template<class T>
void List<T>::show() {//�������� �������� � ������
	Line<T>* current = nullptr;//������������� ������� Line
	current = end;
	cout < current->obj;//�����
	cout << endl;
	while (current->prev != NULL) {//�������� ���� ���� 
		current = current->prev;//��������� �� ����������
		cout<current->obj;//�����
		cout << endl;
	}
}
template<class T>
void List<T>::push(const T& obj) {//�������� � ���� ������ � ������
	count++;//��������� �������
	Line<T>* temp = new Line<T>;//������������� temp
	temp->next = NULL;//��������� �� ��������� NULL
	Line<T>* current = nullptr;//������������� current
	temp->obj = obj;
	if (begin != NULL) {//���� begin �� ����� 0
		temp->prev = end;
		end->next = temp;
		end = temp;
		current = end;//���������� temp � ������ ������
	}
	else {//���� ��� ���������
		temp->prev = NULL;
		begin = end = temp;//����������� temp � ������ � �����
	}
}
template<class T>
void List<T>::pushBack(const T& obj) {//�������� � ���� ������ � �����
	Line<T>* current = nullptr;//������������� current
	Line<T>* temp = new Line<T>;//������������� temp
	temp->prev = NULL;//��������� �� ���������� NULL
	current = NULL;
	temp->obj = obj;
	count++;//��������� �������
	if (begin != NULL) {//���� begin �� ����� 0
		begin->prev = temp;
		temp->next = begin;
		begin = temp;
		current = begin;//���������� temp � ����� ������
	}
	else {//���� ��� ���������
		temp->next = NULL;
		begin = end = temp;//����������� temp � ������ � �����
	}
}	