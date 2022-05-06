#pragma once
#include <iostream>



class tab2d
{
public:
	static const int N = 50;
private:
	int tab[N][N];

public:
	tab2d();
	int& operator()(int i, int j);
	int maksymalny() const;
	int minimalny() const;
	void skala(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const tab2d& t);
};








