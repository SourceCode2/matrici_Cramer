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

  /*== Cramer 2x2 ==*/
  cramer2x2::cramer2x2(INPUT_CRAMER2x2 input) {
    /*== Inserimento dati nella matrice ==*/
    matrice[0][0] = process(input.x1);
    matrice[0][1] = process(input.y1);
    matrice[1][0] = process(input.x2);
    matrice[1][1] = process(input.y2);
    noto[0] = process(input.noto1);
    noto[1] = process(input.noto2);

    /*== Metodo di Cramer ==*/

    /*== Determinante ==*/
    Det = (matrice[0][0] * matrice[1][1]) - (matrice[1][0] * matrice[0][1]);
    FRACTION controllo = Det.value();
    if(controllo.numer / controllo.denom == 0) {
      std::cerr << "Equazioni impossibili" << '\n';
      exit(-1);
    }

    /*== Determinante X ==*/
    DetX = (noto[0] * matrice[1][1]) - (noto[1] * matrice[0][1]);
    resultX = DetX / Det;

    /*== Determinante Y ==*/
    DetY = (matrice[0][0] * noto[1]) - (matrice[1][0] - noto[0]);
    resultY = DetY / Det;
  }
  Fraction cramer2x2::funcX() {return resultX;}
  Fraction cramer2x2::funcY() {return resultY;}

  /*== Cramer 3x3 ==*/
  cramer3x3::cramer3x3(INPUT_CRAMER3x3 input) {
    matrice[0][0] = process(input.x1);
    matrice[1][0] = process(input.x2);
    matrice[2][0] = process(input.x3);
    matrice[0][1] = process(input.y1);
    matrice[1][1] = process(input.y2);
    matrice[2][1] = process(input.y3);
    matrice[0][2] = process(input.z1);
    matrice[1][2] = process(input.z2);
    matrice[2][2] = process(input.z3);
    noto[0]       = process(input.noto1);
    noto[1]       = process(input.noto2);
    noto[2]       = process(input.noto3);

    /*== Determinante ==*/
    Det =  (matrice[0][0]*matrice[1][1]*matrice[2][2]);
    Det += (matrice[0][1]*matrice[1][2]*matrice[2][0]);
    Det += (matrice[0][2]*matrice[1][0]*matrice[2][1]);
    Det -= (matrice[2][0]*matrice[1][1]*matrice[0][2]);
    Det -= (matrice[2][1]*matrice[1][2]*matrice[0][0]);
    Det -= (matrice[2][2]*matrice[1][0]*matrice[0][1]);
    Det.print();std::cout << '\n';
    FRACTION controllo = Det.value();
    if(controllo.numer / controllo.denom == 0) {
      std::cerr << "Equazioni impossibili" << '\n';
      exit(-1);
    }

    /*== Determinante X ==*/
    DetX =  (noto[0]*matrice[1][1]*matrice[2][2]);
    DetX += (matrice[0][1]*matrice[1][2]*noto[2]);
    DetX += (matrice[0][2]*noto[1]*matrice[2][1]);
    DetX -= (noto[2]*matrice[1][1]*matrice[0][2]);
    DetX -= (matrice[2][1]*matrice[1][2]*noto[0]);
    DetX -= (matrice[2][2]*noto[1]*matrice[0][1]);
    DetX.print();std::cout << '\n';
    resultX = DetX / Det;

    /*== Determinante Y ==*/
    DetY =  (matrice[0][0]*noto[1]*matrice[2][2]);
    DetY += (noto[0]*matrice[1][2]*matrice[2][0]);
    DetY += (matrice[0][2]*matrice[1][0]*noto[2]);
    DetY -= (matrice[2][0]*noto[1]*matrice[0][2]);
    DetY -= (noto[2]*matrice[1][2]*matrice[0][0]);
    DetY -= (matrice[2][2]*matrice[1][0]*noto[0]);
    DetY.print();std::cout << '\n';
    resultY = DetY / Det;

    /*== Determinante Z ==*/
    DetZ =  (matrice[0][0]*matrice[1][1]*noto[2]);
    DetZ += (matrice[0][1]*noto[1]*matrice[2][0]);
    DetZ += (noto[0]*matrice[1][0]*matrice[2][1]);
    DetZ -= (matrice[2][0]*matrice[1][1]*noto[0]);
    DetZ -= (matrice[2][1]*noto[1]*matrice[0][0]);
    DetZ -= (noto[2]*matrice[1][0]*matrice[0][1]);
    DetZ.print();std::cout << '\n';
    resultZ = DetZ / Det;
  }
  Fraction cramer3x3::funcX() {return resultX;}
  Fraction cramer3x3::funcY() {return resultY;}
  Fraction cramer3x3::funcZ() {return resultZ;}
} // end namespace
