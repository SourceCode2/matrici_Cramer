/*
src/Fractions
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#include "Fraction.h"
#include <iostream>
#include <string>
namespace Fraction_ns {
	Fraction::Fraction(const int numer, const int denom) {
		auto MCD = this->MCD(numer, denom);
		this->numer = numer / MCD;
		this->denom = denom / MCD;
		if (this->denom < 0 && numer < 0) {
			this->denom *= -1;
			this->numer *= -1;
		}
		if (this->denom == 0) {
			std::cerr << "Error denom is zero" << '\n';
		}
	}

	Fraction::Fraction(const int x)
		:Fraction(x, 1) {}

	Fraction::Fraction()
		:Fraction(0) {}

	Fraction Fraction::Reciprocal() const {
		Fraction ret(this->denom, this->numer);
		return ret;
	}

	int Fraction::MCD(int x, int y) const {
  	/* Scambio valori Variabili */
  	if(y > x) {
    		int appo = x;
    		x = y;
    		y = appo;
  	}
  	/* Dichiarazione Variabili */
  	int r = 1;
  	int mcd = 0;
  	if(x == 0 && y == 0)
      	return 0;
  		else if(x == 0)
      	return y;
  		else if(y == 0)
      	return x;

  	while(y != 0) {
    		mcd = y;
    		r = x % y;
    		x = y;
    		y = r;
  	}
  	return mcd;
	}

	int Fraction::mcm(int nr1, int nr2) const {
  	/*== Calcolo mcm ==*/
  	return (nr1 * nr2)/MCD(nr1, nr2);
	}

	void Fraction::reduce() {
  	int i=2;
  	int min; //Il più basso fra numeratore e denominatore
  	if(this->numer > this->denom) {min=this->denom;}
  	else {min = this->numer;}
  	do{
    	if((this->numer % i == 0) && (this->denom % i == 0)) {
      	this->numer = this->numer / i;
      	this->denom = this->denom / i;
    	} else {i++;}
   	}while(i<=min);
	}

	void Fraction::print() {
  	std::cout << this->numer << "/" << this->denom;
	}
	std::string Fraction::Improper() const {
		auto numer = std::to_string(this->numer);
		auto denom = std::to_string(this->denom);
		auto ret = numer + "/" + denom;
		return ret;
	}

	FRACTION Fraction::value() {
		FRACTION ret{this->numer, this->denom};
		return ret;
	}
	Fraction Fraction::operator+(const Fraction &x)const {
		auto denom = mcm(this->denom, x.denom);
		auto numer = this->numer*(denom / this->denom) + x.numer*(denom / x.denom);

		Fraction ret(numer, denom);
		return ret;
	}

	Fraction Fraction::operator-(const Fraction &x)const {
		auto ret = *this + Fraction(-x.numer, x.denom);
		return ret;
	}

	Fraction Fraction::operator*(const Fraction &x)const {
		Fraction ret(this->numer * x.numer, this->denom * x.denom);
		return ret;
	}

	Fraction Fraction::operator/(const Fraction &x)const {
		auto ret = *this * x.Reciprocal();
		return ret;
	}

	Fraction& Fraction::operator+=(const Fraction &x) {
		*this = *this + x;
		return *this;
	}

	Fraction& Fraction::operator-=(const Fraction &x) {
		*this = *this - x;
		return *this;
	}

	Fraction& Fraction::operator*=(const Fraction &x) {
		*this = *this * x;
		return *this;
	}

	Fraction& Fraction::operator/=(const Fraction &x) {
		*this = *this / x;
		return *this;
	}

	Fraction& Fraction::operator=(const Fraction &x) {
		this->denom = x.denom;
		this->numer = x.numer;

		return *this;
	}

	Fraction Fraction::operator+(const int &x)const {
		return this->operator+(Fraction(x));
	}

	Fraction Fraction::operator-(const int &x)const {
		return this->operator-(Fraction(x));
	}

	Fraction Fraction::operator*(const int &x)const {
		return this->operator*(Fraction(x));
	}

	Fraction Fraction::operator/(const int &x)const {
		return this->operator/(Fraction(x));
	}

	Fraction& Fraction::operator+=(const int &x) {
		return this->operator+=(Fraction(x));
	}

	Fraction& Fraction::operator-=(const int &x) {
		return this->operator-=(Fraction(x));
	}

	Fraction& Fraction::operator*=(const int &x) {
		return this->operator*=(Fraction(x));
	}

	Fraction& Fraction::operator/=(const int &x) {
		return this->operator/=(Fraction(x));
	}

	Fraction& Fraction::operator=(const int &x) {
		*this = Fraction(x);
		return *this;
	}
} // end namespace Fraction
