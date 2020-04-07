#include "ERRORS.h"
#include "Header.h"

ERRORS::ERRORS(const char* msg, const char* datastate, int code) :exception(msg)
{
	strcpy_s(this->datastate, datastate);
	this->code = code;
}

ERRORS::ERRORS(const char* msg, int code) : exception(msg)
{
	this->code = code;
}

const char* ERRORS::get_datastate()
{
	return this->datastate;
}

int ERRORS::get_code() {
	return this->code;
}