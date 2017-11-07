/*
src/cramer/cramer.cpp
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#include "cramer.h"
#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <string>
#include <Fraction.h>

namespace cramer_ns {

  Fraction cramer::process(std::string var) {
    std::string tmp, var1;
    int nr_tmp[2];

    if (var[0] == '-' && isalpha(var[1])) {return Fraction(-1);}
    if (var[0] == '+' && isalpha(var[1])) {return Fraction(+1);}
    if (isalpha(var[0]))                  {return Fraction(+1);}

    for (size_t i = 0; !isalpha(var[i]); i++) {
      tmp += var[i];
    }
    for (size_t i = 0; i < tmp.length(); i++) {
      if (tmp[i] == '/') {
        for (size_t c = 0; c < i; c++) {var1 += tmp[c];}
        nr_tmp[0] = atoi(var1.c_str()); var1 = "";
        for (size_t d = i; i < var.length(); d++) {var1 += var[d];}
        nr_tmp[1] = atoi(var1.c_str());
        return Fraction(nr_tmp[0], nr_tmp[1]);
      }
    }
    return Fraction(atoi(tmp.c_str()));
  }
  cramer2x2::cramer2x2(INPUT_CRAMER input) {
    /*== Inserimento dati nella matrice ==*/
    matrice[0][0] = process(input.x1);
    matrice[0][1] = process(input.y1);
    matrice[1][0] = process(input.x2);
    matrice[1][1] = process(input.y2);
    noto[0] = process(input.noto1);
    noto[1] = process(input.noto2);

    /*== Metodo di Cramer ==*/

    /*== Determinatore ==*/
    Det = (matrice[0][0] * matrice[1][1]) - (matrice[1][0] * matrice[0][1]);
    FRACTION controllo = Det.value();
    if(controllo.numer / controllo.denom == 0) {
      std::cerr << "Equazioni impossibili" << '\n';
      exit(-1);
    }

    /*== Determinatore X ==*/
    DetX = (noto[0] * matrice[1][1]) - (noto[1] * matrice[0][1]);
    resultX = DetX / Det;

    /*== Determinatore Y ==*/ // DetY = (matrice[0][0].nr_int*noto1)-(matrice[1][0].nr_int*noto2);
    DetY = (matrice[0][0] * noto[1]) - (matrice[1][0] - noto[0]);
    resultY = DetY / Det;
  }
  Fraction cramer2x2::funcX() {return resultX;}
  Fraction cramer2x2::funcY() {return resultY;}
} // end namespace
