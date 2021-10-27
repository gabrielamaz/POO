#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

string leLinha()
{
  ifstream arquivo("arquivo.txt");
  string linha = "";
  if (arquivo.is_open()) {
    getline(arquivo, linha);
  }
  arquivo.close();
  return linha;
}

int contaEspacos(string linha)
{
  int numeroEspacos = 0;
  for (auto &iter : linha)
  {
    if (iter == ' ')
    {
      numeroEspacos++;
    }
  }
  return numeroEspacos;
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
  string linha = leLinha();
  int numeroEspacos = contaEspacos(linha);
  cout << numeroEspacos << endl;
  vector <int> numeros = leVetor();
}
