#pragma once
#include <string>
#include <sstream>

using namespace std;

class Tocka
{
private:
	int x;
	int y;
	char c = '-';
public:
	Tocka();
	Tocka(int x, int y);
	Tocka(int x, int y, char c);
	int get_x();
	void set_x(int x);
	int get_y();
	void set_y(int y);
	char get_c();
	void set_c(bool tf);
	string to_string();
};

