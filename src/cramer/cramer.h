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

struct FRAZIONE {
  int numeratore;
  int denominatore;
};
struct INPUT_CRAMER {
  /*== Prima equazione ==*/
  std::string x1, y1; // Le due incognite
  std::string noto1; // Il valore noto
  /*== Seconda equazione ==*/
  std::string x2, y2; // Le due incognite
  std::string noto2; // Il valore noto
};
struct RESULT_CRAMER {
  FRAZIONE resultX;
  FRAZIONE resultY;
};

class cramer {
public:
  cramer(INPUT_CRAMER input); // Inserire i dati sottoforma dello struct INPUT_CRAMER
  RESULT_CRAMER resolve(); // Eseguire il metodo di Cramer e ritornare i risultati

private:
  void process(std::string var, int pos1, int pos2); // Eleborare i dati
  void processNoto(std::string var, int nr); // Elaborare i valori noti
  int mcm(int nr1, int nr2); // Calcolare l'mcm per le frazioni
  void reduce(FRAZIONE *frazione); // Ridurre la frazione in minimi termini
  FRAZIONE matrice[2][2];
  FRAZIONE Det, DetX, DetY; // Le variabili per i determinanti
  FRAZIONE noto1, noto2; // I valori noti
  RESULT_CRAMER result; // Il risultato
};
#endif // CRAMER_H
