#ifndef CRAMER_H
#define CRAMER_H

struct INPUT_CRAMER {
  /*== Prima equazione ==*/
  std::string x1, y1; // Le due incognite
  int noto1; // Il valore noto

  /*== Seconda equazione ==*/
  std::string x2, y2; // Le due incognite
  int noto2; // Il valore noto
}

struct RESULT_CRAMER {
  int resultX; // Risultato di X
  int resultY; // Risultato di Y
}

class cramer {
public:
  cramer(); // Contruttore
  void insert(INPUT_CRAMER data); // Inserire i dati sottoforma dello struct INPUT_CRAMER
  RESULT_CRAMER result(); // Eseguire il metodo di Cramer e ritornare i risultati

private:
  int work(std::string var); // Eleborare i dati
  int determinante(); // Calcolare il Determinante della matrice
  int determinanteX(); // Calcolare il Determinante di X
  int determinanteY(); // Calcolare il Determinante di Y
};
#endif // CRAMER_H
