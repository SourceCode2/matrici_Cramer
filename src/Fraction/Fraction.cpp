/*
src/Fractions
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#include "Fraction.h"
#include <iostream>
Fraction::Fraction(const int numer, const int denom) {
	this->numer = numer;
	this->denom = denom;
  this->reduce();
	if (denom < 0) {
		this->denom *= -1;
		this->numer *= -1;
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

int Fraction::mcm(int nr1, int nr2) const {
  int swap;
  int nr3, nr4, r, MCD;
  if (nr2>nr1) { swap = nr2; nr2 = nr1; nr1 = swap;}
  nr3 = nr1;
  nr4 = nr2;

  /*== Calcolo MCD ==*/
  r = nr3 % nr4;
  while(r!=0) {
    nr3 = nr4;
    nr4 = r;
    r = nr3 % nr4;
  }
  MCD = nr4;

  /*== Calcolo mcm ==*/
  return (nr1 * nr2)/MCD;
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
  std::cout << this->numer << "/" << this->denom << '\n';
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
	Fraction left(x.numer, this->denom);
	Fraction right(this->numer, x.denom);

	Fraction ret(left.numer * right.numer, left.denom * right.denom);
	return ret;
}

Fraction Fraction::operator/(const Fraction &x)const {
	auto ret = *this * this->Reciprocal();
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
