/*
src/cramer.cpp
github project : https:://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#include "cramer.h"
#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <string>
cramer::cramer(INPUT_CRAMER input) {
  /*== Inserimento dati nella matrice ==*/
  process(input.x1, 0, 0);
  process(input.y1, 0, 1);
  process(input.x2, 1, 0);
  process(input.y2, 1, 1);

  processNoto(input.noto1, 1);
  processNoto(input.noto2, 2);
}

RESULT_CRAMER cramer::resolve() {
  /*== Metodo di Cramer ==*/

  /*== Determinatore ==*/
  FRAZIONE parte1{numeratore : matrice[0][0].numeratore*matrice[1][1].numeratore, denominatore : matrice[0][0].denominatore*matrice[1][1].denominatore};
  FRAZIONE parte2{numeratore : matrice[1][0].numeratore*matrice[0][1].numeratore, denominatore : matrice[1][0].denominatore*matrice[0][1].denominatore};
  /*== MCM ==*/
  reduce(&parte1); reduce(&parte2);
  int mcm1 = mcm(parte1.denominatore, parte2.denominatore);
  parte1.numeratore = parte1.numeratore * (mcm1/parte1.denominatore); parte1.denominatore = mcm1;
  parte2.numeratore = parte2.numeratore * (mcm1/parte2.denominatore); parte2.denominatore = mcm1;
  /*== Calcolo ==*/
  Det.numeratore = parte1.numeratore - parte2.numeratore;
  Det.denominatore = mcm1;
  reduce(&Det);
  if(Det.numeratore/Det.denominatore == 0) {
    std::cerr << "Equazioni impossibili" << '\n';
    exit(-1);
  }

  /*== Determinatore X ==*/
  FRAZIONE parteX1{numeratore : noto1.numeratore*matrice[1][1].numeratore, denominatore : noto1.denominatore*matrice[1][1].denominatore};
  FRAZIONE parteX2{numeratore : noto2.numeratore*matrice[0][1].numeratore, denominatore : noto2.denominatore*matrice[0][1].denominatore};
  /*== MCM ==*/
  reduce(&parteX1); reduce(&parteX2);
  int mcmX1 = mcm(parteX1.denominatore, parteX2.denominatore);
  parteX1.numeratore = parteX1.numeratore * (mcmX1/parteX1.denominatore); parteX1.denominatore = mcmX1;
  parteX2.numeratore = parteX2.numeratore * (mcmX1/parteX2.denominatore); parteX2.denominatore = mcmX1;
  /*== Calcolo ==*/
  DetX.numeratore = parteX1.numeratore - parteX2.numeratore;
  DetX.denominatore = mcmX1;
  reduce(&DetX);
  result.resultX.numeratore = DetX.numeratore * Det.denominatore;
  result.resultX.denominatore = DetX.denominatore * Det.numeratore;
  reduce(&result.resultX);

  /*== Determinatore Y ==*/ // DetY = (matrice[0][0].nr_int*noto1)-(matrice[1][0].nr_int*noto2);
  FRAZIONE parteY1{numeratore : matrice[0][0].numeratore*noto2.numeratore, denominatore : matrice[0][0].denominatore*noto2.denominatore};
  FRAZIONE parteY2{numeratore : matrice[1][0].numeratore*noto1.numeratore, denominatore : matrice[1][0].denominatore*noto1.denominatore};
  /*== MCM ==*/
  reduce(&parteY1); reduce(&parteY2);
  int mcmY1 = mcm(parteY1.denominatore, parteY2.denominatore);
  parteY1.numeratore = parteY1.numeratore * (mcmY1/parteY1.denominatore); parteY1.denominatore = mcmY1;
  parteY2.numeratore = parteY2.numeratore * (mcmY1/parteY2.denominatore); parteY2.denominatore = mcmY1;
  /*== Calcolo ==*/
  DetY.numeratore = parteY1.numeratore - parteY2.numeratore;
  DetY.denominatore = mcmY1;
  reduce(&DetY);
  result.resultY.numeratore = DetY.numeratore * Det.denominatore;
  result.resultY.denominatore = DetY.denominatore * Det.numeratore;
  reduce(&result.resultY);

  return result;
}

void cramer::process(std::string var, int pos1, int pos2) {
  std::string tmp, var1;

  if (var[0] == '-' && isalpha(var[1])) {matrice[pos1][pos2].numeratore = -1; matrice[pos1][pos2].denominatore = 1; return;}
  if (var[0] == '+' && isalpha(var[1])) {matrice[pos1][pos2].numeratore = +1; matrice[pos1][pos2].denominatore = 1; return;}
  if (isalpha(var[0]))                  {matrice[pos1][pos2].numeratore = +1; matrice[pos1][pos2].denominatore = 1; return;}

  for (size_t i = 0; !isalpha(var[i]); i++) {
    tmp += var[i];
  }
  for (size_t i = 0; i < tmp.length(); i++) {
    if (tmp[i] == '/') {
      for (size_t c = 0; c < i; c++) {var1 += tmp[c];}
      matrice[pos1][pos2].numeratore = atoi(var1.c_str()); var1 = "";
      for (size_t d = i; i < var.length(); d++) {var1 += var[d];}
      matrice[pos1][pos2].denominatore = atoi(var1.c_str());
      return;
    }
  }
  matrice[pos1][pos2].denominatore = 1;
  matrice[pos1][pos2].numeratore = atoi(tmp.c_str());
}
void cramer::processNoto(std::string var, int nr) {
  std::string var1;
  if (nr == 1) {
    for (size_t i = 0; i < var.length(); i++) {
      if (var[i] == '/') {
        for (size_t c = 0; c < i; c++) { var1 += var[c];}
        noto1.numeratore = atoi(var1.c_str()); var1 = "";
        for (size_t d = i; i < var.length(); d++) {var1 += var[d];}
        noto1.denominatore = atoi(var1.c_str()); var1 = "";
        return;
      }
    }
    noto1.denominatore = 1;
    noto1.numeratore = atoi(var.c_str());
  } else if (nr == 2) {
    for (size_t i = 0; i < var.length(); i++) {
      if (var[i] == '/') {
        for (size_t c = 0; c < i; c++) { var1 += var[c];}
        noto2.numeratore = atoi(var1.c_str()); var1 = "";
        for (size_t d = i; i < var.length(); d++) {var1 += var[d];}
        noto2.denominatore = atoi(var1.c_str());
        return;
      }
    }
    noto2.denominatore = 1;
    noto2.numeratore = atoi(var.c_str());
  }
}
int cramer::mcm(int nr1, int nr2) {
  int swap;
  int nr3, nr4, r, MCD;
  if (nr2>nr1) {
    swap = nr2;
    nr2 = nr1;
    nr1 = swap;
  }
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
void cramer::reduce(FRAZIONE *frazione) {
  int i=2;
  int min; //Il più basso fra numeratore e denominatore
  if(frazione->numeratore > frazione->denominatore) {min=frazione->denominatore;}
  else {min = frazione->numeratore;}
  do{
    if((frazione->numeratore % i == 0) && (frazione->denominatore % i == 0)) {
      frazione->numeratore = frazione->numeratore / i;
      frazione->denominatore = frazione->denominatore / i;
    } else {i++;}
   }while(i<=min);
}
