
#include <iostream>
using namespace std;
#include "tab2d.h"

tab2d::tab2d()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) tab[i][j] = 0;
}

int& tab2d::operator()(int i, int j)
{
	return tab[i][j];
}

int tab2d::maksymalny() const
{
	int m = tab[0][0];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (tab[i][j] > m) m = tab[i][j];

	return m;
}

int tab2d::minimalny() const
{
	int m = tab[0][0];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (tab[i][j] < m) m = tab[i][j];

	return m;
}

void tab2d::skala(std::ostream& out) const
{
	int m1 = minimalny();
	int m2 = maksymalny();
	
	while (!(m1 > m2))
	{
		out << m1;
		++m1;
	}
}

std::ostream& operator<<(std::ostream& out, const tab2d& t)
{
	for (int i = 0; i < t.N; i++)
	{
		for (int j = 0; j < t.N; j++) 	out << t.tab[i][j];
		out << endl;
	}
	return out;
}



