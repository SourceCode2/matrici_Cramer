/*
src/cramer/cramer.h
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#ifndef CRAMER_H
#define CRAMER_H
#include <string>
#include <Fraction.h>

using namespace Fraction_ns;
namespace cramer_ns {

  struct INPUT_CRAMER {
    /*== Prima equazione ==*/
    std::string x1, y1;    // Le due/tre incognite
    std::string noto1;         // Il valore noto
    /*== Seconda equazione ==*/
    std::string x2, y2;    // Le due/tre incognite
    std::string noto2;         // Il valore noto
  };
  class cramer {
  protected:
    Fraction process(std::string var); // Elaborare i dati
  };

  class cramer2x2 : public cramer {
  public:
    cramer2x2(INPUT_CRAMER input); // Inserire i dati sottoforma di INPUT_CRAMER
    Fraction funcX();
    Fraction funcY();
  private:
    Fraction matrice[2][2];
    Fraction noto[2];
    Fraction Det, DetX, DetY;
    Fraction resultX, resultY;
  };

  class cramer3x3 : public cramer {
  public:
    cramer3x3(INPUT_CRAMER input); // Inserire i dati sottoforma di INPUT_CRAMER
    Fraction funcX();
    Fraction funcY();
    Fraction funcZ();
  private:
    Fraction matrice[3][3];
    Fraction noto[3];
    Fraction Det, DetX, DetY, DetZ;
    Fraction resultX, resultY, resultZ;
  };

} // end namespace
#endif // CRAMER_H
