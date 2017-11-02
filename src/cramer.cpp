#include "cramer.h"
#include <iostream>
#include <cstdlib>
#include <ctype.h>

void cramer::insert(INPUT_CRAMER input) {
  /*== Inserimento dati nella matrice ==*/
  matrice[0][0] = process(input.x1);
  matrice[1][0] = process(input.y1);
  matrice[0][1] = process(input.x2);
  matrice[1][1] = process(input.y2);

  noto1 = input.noto1; // Copia noto1
  noto2 = input.noto2; // Copia noto2
}

RESULT_CRAMER cramer::resolve() {
  /*== Metodo di Cramer ==*/
  Det  = matrice[0][0]*matrice[1][1]-matrice[1][0]*matrice[0][1];
  DetX = noto1*matrice[1][1]-noto2*matrice[0][1];
  DetY = matrice[0][0]*noto1-matrice[1][0]*noto2;

  result.resultX = DetX/Det;
  result.resultY = DetY/Det;
  return result;
}

int cramer::process(std::string var) {
  std::string tmp;

  if (var[0] == '-' && isalpha(var[1])) {return -1;}
  if (var[0] == '+' && isalpha(var[1])) {return +1;}
  if (isalpha(var[0]))                  {return +1;}

  for (size_t i = 0; !isalpha(var[i]); i++) {
    tmp += var[i];
  }
  return atoi(tmp.c_str());
}
