#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int numeroEspacos = 0;

void contaEspacos(string linha)
{
  for (auto &iter : linha)
  {
    if (iter == ' ')
    {
      numeroEspacos++;
    }
  }
}

void leLinha()
{
  ifstream arquivo("arquivo.txt");
  string linha = "";
  while (getline(arquivo, linha))
  {
    contaEspacos(linha);
  }
  arquivo.close();
}

vector <int> leVetor() {
  int entrada;
  vector <int> numeros;
  while ((cin >> entrada) && (entrada > 0)) {
    numeros.push_back(entrada);
  }
  sort(numeros.begin(), numeros.end());
  numeros.erase(std::unique(numeros.begin(), numeros.end()), numeros.end());
  return numeros;
}

int main()
{
  leLinha();
  cout << numeroEspacos << endl;
}