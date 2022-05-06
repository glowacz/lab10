#pragma once
#include <iostream>
#include <windows.h>
   
class element
{
	static const char z = '*';
	int color;	

public:
	element(int color=0) :color(color) {}

	element& operator++()
	{
		color++;
		return *this;
	}
	
	friend bool operator>(const element& e1, const element& e2)
	{
		return e1.color > e2.color;
	}
	friend bool operator<(const element& e1, const element& e2)
	{
		return e1.color < e2.color;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const element& el)
	{
		//ustawia kolor do wypisania znaku
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), el.color);	
		out << el.z;

		//powrót do wartoœci domyœlnych konsoli
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		return out;
	}
};



