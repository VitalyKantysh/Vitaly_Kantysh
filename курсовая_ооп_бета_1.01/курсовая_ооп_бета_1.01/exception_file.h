#pragma once
#include "Header.h"

class exception_file :public exception {
private:
	string file;
	int code;
public:
	exception_file(const char* msg, string file, int code);
	string get_file();
	int get_code();
};