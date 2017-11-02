#include <iostream>
#include <string>
#include <cstdlib>
#include <ctype.h> //

struct INPUT {
  std::string var1;
  std::string var2;
  std::string null;
  int noto;
};

int work(std::string &var) {
  std::string tmp;

  if (var[0] == '-' && isalpha(var[1])) {return -1;}
  if (var[0] == '+' && isalpha(var[1])) {return +1;}
  if (isalpha(var[0])) {return +1;}

  for (size_t i = 0; !isalpha(var[i]); i++) {
    tmp += var[i];
  }
  var = "";
  return atoi(tmp.c_str());
}

inline int Determinante(int matrice[2][2]) {
  return matrice[0][0]*matrice[1][1]-matrice[1][0]*matrice[0][1];
}

inline int DeterminanteX(int matrice[2][2])
int main(int argc, char* argv[]) {
  /*== Inizializzazione variabili ==*/
  int matrice[2][2];
  INPUT input;

  /*== Input dati ==*/
  std::cout << "Inserisci la prima equazione in forma normale (+1x +2y = -1): "; // Example : +2x+3y = +1  +1/2x+5g = +5
  std::cin >> input.var1 >> input.var2 >> input.null >> input.noto;
  std::cin.sync();
  /*== Elaborazione dati ==*/
  matrice[0][0] = work(input.var1);
  matrice[1][0] = work(input.var2);

  /*== Input dati 2 ==*/
  std::cout << "Inserisci la seconda equazione in forma normale (+1x +2y = -1): "; // Example : +2x+3y = +1  +1/2x+5g = +5
  std::cin >> input.var1 >> input.var2 >> input.null >> input.noto;
  std::cin.sync();
  /*== Elaborazione dati 2 ==*/
  matrice[0][1] = work(input.var1);
  matrice[1][1] = work(input.var2);

  std::cout << Determinante(matrice) << '\n';


}
