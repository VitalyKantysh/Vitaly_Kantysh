#include "Header.h"
#include "ERRORS.h"

bool isNumberNumeric()
{
	if ((cin.get() == '\n'))
		return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		throw ERRORS("���������� ����", 121);
	}
}

bool isNumberRangeCorrect(int number, int left_range, int right_range)
{
	if ((number >= left_range) && (number <= right_range))
		return true;
	else
		throw ERRORS("������������ ��������", 123);
}

int inputNumber(istream& Cin, int left_range, int right_range, const char* str)
{
	bool exit = false;
	int number;
	while (exit == false)
	{
		try
		{
			cout << "������� " << str << " :(�� " << left_range << " �� " << right_range << ")\n->";
			Cin >> number;
			isNumberNumeric();
			isNumberRangeCorrect(number, left_range, right_range);
			exit = true;
		}
		catch (ERRORS& ex)
		{
			cout << endl << ex.what() << endl;
			cout << "��� ������: " << ex.get_code() << endl << endl;
		}
		catch (...)
		{
			cout << "�������������� ������!" << endl << endl;
		}
	}
	return number;
}

const char* engSymAndNumInput(istream& Cin, const char* nameSubject)
{
	char* str;
	str = new char[N];
	bool exit = false;
	while (exit == false)
	{
		try
		{
			cout << "������� " << nameSubject << " \n->";
			Cin.getline(str, N);
			if (strlen(str) == 0)
			{
				throw exception("!!! ������ ������, ��������� ���� !!!");
			}
			for (int i = 0; str[i]/*i < strlen(str)*/; i++)
			{
				if (((int(str[i]) >= 65) && (int(str[i]) <= 90) || (int(str[i]) >= 97) && (int(str[i]) <= 122) || (int(str[i]) >= 48) && (int(str[i]) <= 57)) == false)
				{
					throw ERRORS("!!! ������ ������ ������ ��������� ������ ������� ����������� �������� �/��� ����� , ��������� ���� !!!", str, 70);
				}
			}
			exit = true;
		}
		catch (ERRORS& ex)
		{
			cout << endl << ex.what() << endl << "������, � ������� ������� ������ : \"" << ex.get_datastate() << "\"" <<
				endl << "��� ������ : " << ex.get_code() << endl << endl;
		}
		catch (const exception& ex)
		{
			cout << endl << ex.what() << endl << endl;
		}
		catch (...)
		{
			cout << "�������������� ������! ��������� ����\n\n";
		}

	}
	return str;
}

const char* engSymInput(istream& Cin, const char* nameSubject)
{
	char* str;
	str = new char[N];
	bool exit = false;
	while (exit == false)
	{
		try
		{
			cout << "������� " << nameSubject << " \n->";
			Cin.getline(str, N);
			if (strlen(str) == 0)
			{
				throw exception("!!! ������ ������, ��������� ���� !!!");
			}
			for (int i = 0; i < strlen(str); i++)
			{
				if (((int(str[i]) >= 65) && (int(str[i]) <= 90) || (int(str[i]) >= 97) && (int(str[i]) <= 122) || (int(str[i])==32) ) == false)
				{
					throw ERRORS("!!! ������ ������ ������ ��������� ������ ������� ����������� ��������, ��������� ���� !!!", str, 70);
				}
			}
			exit = true;
		}
		catch (ERRORS& ex)
		{
			cout << endl << ex.what() << endl << "������, � ������� ������� ������ : \"" << ex.get_datastate() << "\"" << endl << "��� ������ : " << ex.get_code() << endl << endl;
		}
		catch (const exception& ex)
		{
			cout << endl << ex.what() << endl << endl;
		}
		catch (...)
		{
			cout << "�������������� ������! ��������� ����\n\n";
		}
	}
	return str;
}