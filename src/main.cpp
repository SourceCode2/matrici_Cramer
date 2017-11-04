/*
src/main.cpp
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#include <iostream>
#include <string>
#include "cramer/cramer.h" // oppure #include <cramer.h> dopo aver installato le librerie

int main(int argc, char* argv[]) {
  /*== Inizializzazione variabili ==*/
  INPUT_CRAMER input;
  std::string null;

  /*== Input dati ==*/
  std::cout << "Inserisci la prima equazione in forma normale (+1x +2y = -1): "; // Example : +2x+3y = +1  +1/2x+5g = +5
  std::cin >> input.x1 >> input.y1 >> null >> input.noto1;
  std::cin.sync();
  /*== Input dati 2 ==*/
  std::cout << "Inserisci la seconda equazione in forma normale (+1x +2y = -1): "; // Example : +2x+3y = +1  +1/2x+5g = +5
  std::cin >> input.x2 >> input.y2 >> null >> input.noto2;
  std::cin.sync();

  /*== MAIN ==*/
  cramer oggetto(input);
  RESULT_CRAMER risultato = oggetto.resolve();
  std::cout << "x = " << risultato.resultX.numeratore << "/" << risultato.resultX.denominatore << '\n';
  std::cout << "y = " << risultato.resultY.numeratore << "/" << risultato.resultY.denominatore << '\n';
}
