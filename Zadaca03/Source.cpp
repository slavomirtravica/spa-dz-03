#include <iostream>
#include <math.h>
#include <Windows.h>
#include "Tocka.h"

using namespace std;

void inicijalizirajPolje(Tocka polje[20][40])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			polje[i][j].set_x(i);
			polje[i][j].set_y(j);
		}
	}
}

short postaviTocku(Tocka& tocak, char t)
{
	int x, y;
	cout << "Unesite brojeve izmedju 1 i 20 za retke, a 1 i 40 za stupce!" << endl;
	cout << t << " redak: ";
	cin >> x;
	cout << t << " stupac: ";
	cin.ignore();
	cin >> y;
	if (x < 1 || y < 1 || x > 20 || y > 40)
	{
		cout << "Otisli ste predaleko!" << endl;
		return 1;
	}
	if (y == 20 && x > 1 && x < 20)
	{
		cout << "Tocka je u zidu!" << endl;
		return 2;
	}
	tocak.set_x(x - 1);
	tocak.set_y(y - 1);
	tocak.set_c(true);

	return 0;
}

void buildTheWall(Tocka polje[20][40])
{
	for (int i = 1; i <= 18; i++)
	{
		polje[i][19].set_c(true);
	}
}

double udaljenost(Tocka a, Tocka b)
{
	return sqrt(pow((b.get_x() - a.get_x()), 2) + pow((b.get_y() - a.get_y()), 2));
}

void crtaj(Tocka polje[20][40])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			cout << polje[i][j].get_c();
		}
		cout << endl;
	}
}

void moveRight(Tocka polje[20][40], Tocka a, Tocka b)
{
	int x = a.get_x();
	for (int i = a.get_y() + 1; i <= b.get_y(); i++)
	{
		polje[x][i].set_c(true);
		crtaj(polje);
		if (i < b.get_y())
		{
			Sleep(100);
			system("cls");
		}
	}
}

void moveLeft(Tocka polje[20][40], Tocka a, Tocka b)
{
	int x = a.get_x();
	for (int i = a.get_y(); i >= b.get_y(); i--)
	{
		polje[x][i].set_c(true);
		crtaj(polje);
		if (i > b.get_y())
		{
			Sleep(100);
			system("cls");
		}
	}
}

void moveDown(Tocka polje[20][40], Tocka a, Tocka b)
{
	system("cls");
	int y = a.get_y();
	for (int i = a.get_x() + 1; i <= b.get_x(); i++)
	{
		polje[i][y].set_c(true);
		crtaj(polje);
		if (i < b.get_x())
		{
			Sleep(100);
			system("cls");
		}
	}
	if (a.get_y() < b.get_y())
	{
		system("cls");
		moveRight(polje, polje[b.get_x()][y], b);
	}
	else if (a.get_y() > b.get_y())
	{
		system("cls");
		moveLeft(polje, polje[b.get_x()][y], b);
	}
}

void moveUp(Tocka polje[20][40], Tocka a, Tocka b)
{
	system("cls");
	int y = a.get_y();
	int broj = a.get_x() - b.get_x();
	for (int i = a.get_x() - 1; i >= b.get_x(); i--)
	{
		polje[i][y].set_c(true);
		crtaj(polje);
		if (i > b.get_x())
		{
			Sleep(100);
			system("cls");
		}
	}
	if (a.get_y() < b.get_y())
	{
		system("cls");
		moveRight(polje, polje[b.get_x()][y], b);
	}
	else if (a.get_y() > b.get_y())
	{
		system("cls");
		moveLeft(polje, polje[b.get_x()][y], b);
	}
}

int main()
{
	Tocka polje[20][40];
	inicijalizirajPolje(polje);

	short ret;
	Tocka a;
	ret = postaviTocku(a, 'A');
	if (ret)
	{
		return -1;
	}
	Tocka b;
	ret = postaviTocku(b, 'B');
	if (ret)
	{
		return -1;
	}
	polje[a.get_x()][a.get_y()] = a;
	polje[b.get_x()][b.get_y()] = b;

	buildTheWall(polje);

	double uVrh = 0;
	double uDno = 0;
	double razmak = 0;
	if ((a.get_y() >= 19 && b.get_y() >= 19) ||
		(a.get_y() <= 19 && b.get_y() <= 19))
	{
		razmak = udaljenost(a, b);
	}
	else
	{
		uVrh = udaljenost(a, polje[0][19]);
		uDno = udaljenost(a, polje[19][19]);
	}

	// ako su sa iste strane zida
	if (razmak)
	{
		if (a.get_x() < b.get_x())
		{
			moveDown(polje, a, b);
			return 0;
		}
		else
		{
			moveUp(polje, a, b);
			return 0;
		}
	}

	// ako su preko zida
	if (uVrh < uDno)
	{
		moveUp(polje, a, polje[0][20]);
		moveDown(polje, polje[0][20], b);
		return 0;
	}
	else
	{
		moveDown(polje, a, polje[19][20]);
		moveUp(polje, polje[19][20], b);
		return 0;
	}

	return 0;
}