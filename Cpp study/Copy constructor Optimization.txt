#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Fraction {
private:
	int m_numerator;
	int m_denomirator;

public:
	Fraction(int num = 0, int den = 1) 
		: m_numerator(num), m_denomirator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction& _frac)
		:m_numerator(_frac.m_numerator), m_denomirator(_frac.m_denomirator)
	{
		cout << "copy constructor" << endl;
	}

	friend ostream& operator << (ostream& out, const Fraction& _frac) {
		out << _frac.m_numerator << "/" << _frac.m_denomirator;
		return out;
	}

};

Fraction some() {
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

int main() {
	Fraction frac(3, 5);

	// if you set /od2 - maximum optimization
	Fraction ret(Fraction(3, 7));
	// compiler delete Fraction(3, 7) expression to call basic constructor than copiler fill with this (3, 7)
	
	Fraction copy = some(); 
	//furthermore this case compiler set same adress temp & copy
	cout << &copy << endl;


	return 0;
}