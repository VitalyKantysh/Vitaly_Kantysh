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
		throw ERRORS("нечисловой ввод", 121);
	}
}

bool isNumberRangeCorrect(int number, int left_range, int right_range)
{
	if ((number >= left_range) && (number <= right_range))
		return true;
	else
		throw ERRORS("некорректный диапазон", 123);
}

int inputNumber(istream& Cin, int left_range, int right_range, const char* str)
{
	bool exit = false;
	int number;
	while (exit == false)
	{
		try
		{
			cout << "Введите " << str << " :(от " << left_range << " до " << right_range << ")\n->";
			Cin >> number;
			isNumberNumeric();
			isNumberRangeCorrect(number, left_range, right_range);
			exit = true;
		}
		catch (ERRORS& ex)
		{
			cout << endl << ex.what() << endl;
			cout << "Код ошибки: " << ex.get_code() << endl << endl;
		}
		catch (...)
		{
			cout << "Непредвиденная ошибка!" << endl << endl;
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
			cout << "Введите " << nameSubject << " \n->";
			Cin.getline(str, N);
			if (strlen(str) == 0)
			{
				throw exception("!!! Пустая строка, повторите ввод !!!");
			}
			for (int i = 0; str[i]/*i < strlen(str)*/; i++)
			{
				if (((int(str[i]) >= 65) && (int(str[i]) <= 90) || (int(str[i]) >= 97) && (int(str[i]) <= 122) || (int(str[i]) >= 48) && (int(str[i]) <= 57)) == false)
				{
					throw ERRORS("!!! Данная строка должна содержать только символы английского алфавита и/или цифры , повторите ввод !!!", str, 70);
				}
			}
			exit = true;
		}
		catch (ERRORS& ex)
		{
			cout << endl << ex.what() << endl << "Строка, в которой найдена ошибка : \"" << ex.get_datastate() << "\"" <<
				endl << "Код ошибки : " << ex.get_code() << endl << endl;
		}
		catch (const exception& ex)
		{
			cout << endl << ex.what() << endl << endl;
		}
		catch (...)
		{
			cout << "Непредвиденная ошибка! Повторите ввод\n\n";
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
			cout << "Введите " << nameSubject << " \n->";
			Cin.getline(str, N);
			if (strlen(str) == 0)
			{
				throw exception("!!! Пустая строка, повторите ввод !!!");
			}
			for (int i = 0; i < strlen(str); i++)
			{
				if (((int(str[i]) >= 65) && (int(str[i]) <= 90) || (int(str[i]) >= 97) && (int(str[i]) <= 122) || (int(str[i])==32) ) == false)
				{
					throw ERRORS("!!! Данная строка должна содержать только символы английского алфавита, повторите ввод !!!", str, 70);
				}
			}
			exit = true;
		}
		catch (ERRORS& ex)
		{
			cout << endl << ex.what() << endl << "Строка, в которой найдена ошибка : \"" << ex.get_datastate() << "\"" << endl << "Код ошибки : " << ex.get_code() << endl << endl;
		}
		catch (const exception& ex)
		{
			cout << endl << ex.what() << endl << endl;
		}
		catch (...)
		{
			cout << "Непредвиденная ошибка! Повторите ввод\n\n";
		}
	}
	return str;
}