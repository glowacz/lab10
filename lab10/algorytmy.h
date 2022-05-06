#pragma once

#include <complex>
#include "function.h"
#include "tab2d.h"
#include "element.h"

using std::complex;
using std::cout;
using std::endl;


//--------------------------------------------------------------------------
template <typename T>
T pierwiastek(const Function<T>& f, T x, int& it)	throw(...);

//tylko dla typu complex<double>
//template <int N>
//void fraktal(const Function<complex<double> >& f, const complex<double>& q) noexcept;



//--------------------------------------------------------------------------

template <typename T>
T pierwiastek(const Function<T>& f, T x, int& it)	throw(...)
{
	double eps = 1e-6;   // dok³adnoœæ obliczeñ
	int max_it = 50;	 //maksymalna liczba iteracji

	for (it = 0; it < max_it; it++)
	{
		T val = f.value(x);

		if (abs(val) < eps)
			return x;

		T deriv = f.prim(x);

		if (abs(deriv) < eps)
			throw "derivative close to zero";

		x = x - (val / deriv);
	}

	throw "max_it reached";
}


//--------------------------------------------------------------------------

/*
template <int N>
void fraktal(const Function<std::complex<double> >& f, const std::complex<double> & q) noexcept
{
	double qre = q.real();
	double qim = q.imag();
	
	tab2d<element,N> frrr;	//wykorzystanie wzorca tablicy 
	int it;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			try
			{
				pierwiastek(f, complex<double>(qre + i, qim + j), it);

			}
			catch (...)
			{
				// nawet jeœli brak zbie¿noœci interesuje nas liczba wykonanych iteracji				
			}
			frrr(i, j) = element(it);
		}


	cout << "FRAKTAL NEWTONA:" << endl;
	cout << frrr << endl;

	cout << "SKALA :" << endl;
	frrr.skala(std::cout);
	cout << endl << endl;

}

*/

//--------------------------------------------------------------------------












