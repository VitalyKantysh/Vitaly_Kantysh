#include "exception_file.h"
#include "Header.h"

exception_file::exception_file(const char* msg, string datastate, int code) :exception(msg)
{
	this->file = datastate;
	this->code = code;
}

string exception_file::get_file()
{
	return this->file;
}

int exception_file::get_code() {
	return this->code;
}