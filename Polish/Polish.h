#pragma once
#ifndef _POLISH_
#define _POLISH_

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<fstream>
#include"Stack.h"

using namespace std;

class IOper
{
protected:

public:
	virtual int Priority() = 0;
	virtual int GetNumber() = 0;
	virtual IOper* Calc(IOper* a, IOper* b) = 0;
};

class TNum : public IOper
{
protected:
	int data;
public:
	TNum(int _d);
	TNum(TNum& _v);
	TNum(char* s);

	virtual int Priority();
	virtual int GetNumber();
	virtual IOper* Calc(IOper* a, IOper* b);

};

class TOper : public IOper
{
protected:
	char data;
public:
	TOper(char _d);
	TOper(TOper& _v);

	virtual int GetNumber();
};

class TPlus : public TOper
{
protected:

public:

	TPlus(char _d) : TOper(_d)
	{
	}

	virtual int Priority();
	virtual IOper* Calc(IOper* a, IOper* b);
};

class TMinus : public TOper
{
protected:

public:

	TMinus(char _d) : TOper(_d)
	{
	}

	virtual int Priority();
	virtual IOper* Calc(IOper* a, IOper* b);
};

class TMultiply : public TOper
{
protected:

public:
	TMultiply(char _d) : TOper(_d)
	{
	}

	virtual int Priority();
	virtual IOper* Calc(IOper* a, IOper* b);
};

class TDivide : public TOper
{
protected:

public:
	TDivide(char _d) : TOper(_d)
	{
	}
	virtual int Priority();
	virtual IOper* Calc(IOper* a, IOper* b);
};

class TOpenBracket : public TOper
{
protected:

public:
	TOpenBracket(char _d) : TOper(_d)
	{
	}

	virtual int Priority();
	virtual IOper* Calc(IOper* a, IOper* b);
};

class TCloseBracket : public TOper
{
protected:

public:

	TCloseBracket(char _d) : TOper(_d)
	{
	}
	virtual int Priority();

	virtual IOper* Calc(IOper* a, IOper* b);
};

class TOperFactory
{
public:
	static void Create(char* s, int& n, IOper**& opers);
};

class TPolish
{
public:
	static int Calculation(char* s);
};

#endif