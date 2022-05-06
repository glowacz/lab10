#pragma once

#include <iostream>


template <typename T>
class Function
{

public:
	Function() = default;
	Function(const Function&) = delete;
	Function& operator=(const Function&) = delete;

	virtual T value(T x) const = 0;
	virtual T prim(T x) const = 0;

	virtual ~Function() { }
};

//---------------------------------------------------
template <typename T>
class Const :public Function<T>
{
	T a;
public:
	Const(T a) : a(a) { }
	virtual T value(T x) const override
	{
		return a;
	}
	virtual T prim(T x) const override
	{
		return 0.0;
	}
};

template <typename T>
class X :public Function<T>
{
public:
	X() { }
	virtual T value(T x) const override
	{
		return x;
	}
	virtual T prim(T x) const override
	{
		return 1.0;
	}
};

template <typename T>
class Plus : public Function<T>
{
	Function<T>* f;
	Function<T>* g;
public:
	Plus(Function<T>* f, Function<T>* g) : f(f), g(g) { }
	
	virtual T value(T x) const override
	{
		return f->value(x) + g->value(x);
	}
	
	virtual T prim(T x) const override
	{
		return f->value(x) + g->value(x);
	}

	virtual ~Plus()
	{
		delete f;
		delete g;
	}
};

template <typename T>
class Minus : public Function<T>
{
	Function<T>* f;
	Function<T>* g;
public:
	Minus(Function<T>* f, Function<T>* g) : f(f), g(g) { }

	virtual T value(T x) const override
	{
		return f->value(x) - g->value(x);
	}

	virtual T prim(T x) const override
	{
		return f->value(x) - g->value(x);
	}

	virtual ~Minus()
	{
		delete f;
		delete g;
	}
};

template <typename T>
class Iloczyn : public Function<T>
{
	Function<T>* f;
	Function<T>* g;
public:
	Iloczyn(Function<T>* f, Function<T>* g) : f(f), g(g) { }

	virtual T value(T x) const override
	{
		return f->value(x) * g->value(x);
	}

	virtual T prim(T x) const override
	{
		return f->value(x) * g->prim(x) + f->prim(x) * g->value(x);
	}
	
	virtual ~Iloczyn()
	{
		delete f;
		delete g;
	}
};

//--------------------------------------------------------------------------

template <typename T>
class Wielomian : public Function<T>
{
	Function<T>* f;

public:
	Wielomian() { }
	Wielomian(Function<T>* f) : f(f) { }
	~Wielomian() { delete f; }

	virtual T value(T x) const override
	{
		return f->value(x);
	}

	virtual T prim(T x) const override
	{
		return f->prim(x);
	}

	//Wielomian<T>* generuj1(T* wsp, int N)
	void generuj1(T* wsp, int N)
	{
		f = new Const<T>(0);

		for (int i = N - 1; i >= 0; i--)
		{
			f = new Iloczyn<T>(f, new X<T>());
			f = new Plus<T>(f, new Const<T>(wsp[i]));
		}
	}

	//Wielomian<T>* generuj2(T* zeroes, int N)
	void generuj2(T* zeroes, int N)
	{
		f = new Const<T>(1);

		for (int i = 0; i < N; i++)
		{
			f = new Iloczyn<T>(f, new Minus<T>(new X<T>(), new Const<T>(zeroes[i])));
		}
	}

};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
