#include "Tocka.h"
#include <sstream>
#include <string>

Tocka::Tocka()
{
	this->x = 0;
	this->y = 0;
}

Tocka::Tocka(int x, int y)
{
	this->x = x;
	this->y = y;
}

Tocka::Tocka(int x, int y, char c)
{
	this->x = x;
	this->y = y;
	this->c = c;
}

int Tocka::get_x()
{
	return this->x;
}

void Tocka::set_x(int x)
{
	this->x = x;
}

int Tocka::get_y()
{
	return this->y;
}

void Tocka::set_y(int y)
{
	this->y = y;
}

char Tocka::get_c()
{
	return this->c;
}

void Tocka::set_c(bool tf)
{
	if (tf)
	{
		this->c = '*';
	}
	else
	{
		this->c = '-';
	}
}

string Tocka::to_string()
{
	stringstream ss;
	ss << "x: " << this->x << ", "
		<< "y: " << this->y << endl;

	return ss.str();
}
