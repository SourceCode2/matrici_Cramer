/*
src/esempio_Fraction.cpp
github project https://github.com/SourceCode2/matrici_Cramer.git

The Cramer method in C++ with fractions
Copyright (C) 2017  Davide Sofronia
License GPLv3
*/
#include "Fraction/Fraction.h"
//#include <Fraction.h> // Dopo aver installato le librerie
 int main(int argc, char const *argv[]) {
   Fraction addendo1(1);
   Fraction addendo2(1,2);
   Fraction addendo3(1,3);
   auto risultato = addendo1 + addendo2 + addendo3;
   risultato.print();
   return 0;
 }
