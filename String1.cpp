#include "String1.h"

int String::num_string = 0;

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_string++;
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_string++;
}

String::String(const String& st)
{
	len = st.len;              // same length
	str = new char[len + 1];  // allot space
	std::strcpy(str, st.str);
	num_string++;

}

String::~String()
{
	--num_string;
	delete[] str;

}

char& String::operator[](int i)
{
	return str[i];
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator>(const String& st, const String& st2)
{
	return st2.str < st.str;
}

bool operator<(const String& st, const String& st2)
{
	return (strcmp(st.str, st2.str) < 0);
}

bool operator==(const String& st, const String& st2)
{
	return (strcmp(st.str, st2.str) == 0);
}

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}

