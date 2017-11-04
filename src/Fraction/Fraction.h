/*
src/Fraction/Fraction.h
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#ifndef FRACTION_H
#define FRACTION_H

struct FRACTION {
  int numer; // numeratore
  int denom; // denominatore
};

class Fraction {
public:
  Fraction();                       //--------------//
  Fraction(int i);                 // Construttori //
  Fraction(int numer, int denom); //--------------//

  Fraction Reciprocal()const;
  void set(int numer, int denom); // Settare i valori
  FRACTION value(); // Ritornare i valori
  void reduce();    // Ridurre ai minimi termini
  void print();     //
  /* Creare gli operatori*/
  Fraction& operator=(const Fraction &x);
  Fraction operator+(const Fraction &x)const;
	Fraction operator-(const Fraction &x)const;
	Fraction operator*(const Fraction &x)const;
	Fraction operator/(const Fraction &x)const;
	Fraction& operator+=(const Fraction &x);
	Fraction& operator-=(const Fraction &x);
	Fraction& operator*=(const Fraction &x);
	Fraction& operator/=(const Fraction &x);

	Fraction& operator=(const int &x);
	Fraction operator+(const int &x)const;
	Fraction operator-(const int &x)const;
	Fraction operator*(const int &x)const;
	Fraction operator/(const int &x)const;
	Fraction& operator+=(const int &x);
	Fraction& operator-=(const int &x);
	Fraction& operator*=(const int &x);
  Fraction& operator/=(const int &x);

private:
  int mcm(int nr1, int nr2) const;
  int numer, denom;

};
#endif // FRACTION_H
