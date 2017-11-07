/*
src/main.cpp
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#include <iostream>
#include <string>
#include <cramer.h>
#include <Fraction.h>
int main(int argc, char* argv[]) {
  std::cout << "Vuoi usare Cramer 2x2 o 3x3 : ";
  std::string risposta;
  std::cin >> risposta;
  if (risposta == "2x2") {
    /*== Inizializzazione variabili ==*/
    cramer_ns::INPUT_CRAMER2x2 input;
    std::string null;

    /*== Input dati ==*/
    std::cout << "Inserisci la prima equazione in forma normale (+1x +2y = -1/3): ";
    std::cin >> input.x1 >> input.y1 >> null >> input.noto1;
    std::cin.sync();
    /*== Input dati 2 ==*/
    std::cout << "Inserisci la seconda equazione in forma normale (2x +1/2y = -1): ";
    std::cin >> input.x2 >> input.y2 >> null >> input.noto2;
    std::cin.sync();
    /*== MAIN ==*/
    cramer_ns::cramer2x2 oggetto(input);
    Fraction_ns::Fraction risultatoX = oggetto.funcX();
    Fraction_ns::Fraction risultatoY = oggetto.funcY();
    std::cout << "x = ";risultatoX.print(); std::cout << '\n';
    std::cout << "y = ";risultatoY.print(); std::cout << '\n';
    return 0;

  } else if (risposta == "3x3") {
    /*== Inizializzazione variabili ==*/
    cramer_ns::INPUT_CRAMER3x3 input;
    std::string null;

    /*== Input dati ==*/
    std::cout << "Inserisci la prima equazione in forma normale (x +2y -1/2z = -1/5): ";
    std::cin >> input.x1 >> input.y1 >> input.z1 >> null >> input.noto1;
    std::cin.sync();
    /*== Input dati 2 ==*/
    std::cout << "Inserisci la seconda equazione in forma normale (5x +1/2y + 5/3z = -1): ";
    std::cin >> input.x2 >> input.y2 >> input.z2 >> null >> input.noto2;
    std::cin.sync();

    /*== Input dati 3 ==*/
    std::cout << "Inserisci la terza equazione in forma normale (1/3x +1/5y + 5/3z = -2/6): ";
    std::cin >> input.x3 >> input.y3 >> input.z3 >> null >> input.noto3;
    std::cin.sync();

    /*== MAIN ==*/
    cramer_ns::cramer3x3 oggetto(input);
    Fraction_ns::Fraction risultatoX = oggetto.funcX();
    Fraction_ns::Fraction risultatoY = oggetto.funcY();
    Fraction_ns::Fraction risultatoZ = oggetto.funcZ();
    std::cout << "x = ";risultatoX.print(); std::cout << '\n';
    std::cout << "y = ";risultatoY.print(); std::cout << '\n';
    std::cout << "z = ";risultatoZ.print(); std::cout << '\n';
  }
  return -1;
}
