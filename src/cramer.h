#ifndef CRAMER_H
#define CRAMER_H
#include <string>
struct INPUT_CRAMER {
  /*== Prima equazione ==*/
  std::string x1, y1; // Le due incognite
  int noto1; // Il valore noto
  /*== Seconda equazione ==*/
  std::string x2, y2; // Le due incognite
  int noto2; // Il valore noto
};

struct RESULT_CRAMER {
  int resultX; // Risultato di X
  int resultY; // Risultato di Y
};

class cramer {
public:
  void insert(INPUT_CRAMER input); // Inserire i dati sottoforma dello struct INPUT_CRAMER
  RESULT_CRAMER resolve(); // Eseguire il metodo di Cramer e ritornare i risultati

private:
  int process(std::string var); // Eleborare i dati

  int matrice[2][2]; // La matrice
  int Det, DetX, DetY; // Le variabili per i determinanti
  int noto1, noto2; // I valori noti
  RESULT_CRAMER result; // Il risultato
};
#endif // CRAMER_H
