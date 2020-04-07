#pragma once
#include "Header.h"

class ERRORS :	public exception
{
private:
	char datastate[N];
	int code;
public:
	ERRORS(const char* msg, const char* datastate, int code);
	ERRORS(const char* msg, int code);
	const char* get_datastate();
	int get_code();
};

