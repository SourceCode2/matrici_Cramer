/*
src/Fraction/Fraction.h
github project https://github.com/SourceCode2/matrici_Cramer.git
The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#ifndef FRACTION_H
#define FRACTION_H
#include <string>
namespace Fraction_ns {
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
    FRACTION value();                   // Ritornare i valori
    void reduce();                  // Ridurre ai minimi termini
    void print();                   // Stampare la frazione

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
    std::string Improper()const;
  private:
    int MCD(int x, int y) const;
    int mcm(int nr1, int nr2) const;
    int numer, denom;
  };
} // end namespace Fraction
#endif // FRACTION_H
