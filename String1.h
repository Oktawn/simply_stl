#ifndef STRING1_H
#define STRING1_H
#include <iostream>

class String
{

public:
	String();
	String(const char* s);
	String(const String&);
	~String();

	int lenght() const { return len; }
	static int Howmany() { return num_string; }

	char& operator[](int i);
	String& operator=(const char*);
	String& operator=(const String&);
	const char& operator[](int i)const;

	friend bool operator>(const String& st, const String& st2);
	friend bool operator<(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend std::istream& operator>>(std::istream& is, String& st);
	friend std::ostream & operator<<(std::ostream& os, const String& st);


private:
	int len;
	char* str;
	static int num_string;
	static const int CINLIM = 80;
};



#endif // !STRING1_H

