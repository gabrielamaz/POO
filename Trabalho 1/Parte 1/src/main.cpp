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

void leVetor() {
  int entrada;
  vector <int> numeros;
  vector <int> quantidade;
  while ((cin >> entrada) && (entrada > 0)) {
    numeros.push_back(entrada);
  }
  sort(numeros.begin(), numeros.end());
  quantidade = numeros;
  numeros.erase(std::unique(numeros.begin(), numeros.end()), numeros.end());
  for (std::vector<int>::const_iterator i = numeros.begin(); i != numeros.end(); ++i) 
  {
    int counter = 0;
    for(std::vector<int>::const_iterator n = quantidade.begin(); n != quantidade.end(); ++n)
    {
      if(*i == *n) counter++;
    }
    cout << counter << ' ' << *i << ' ';
  }
  cout << endl;
}

int main()
{
  cout << "  * Este programa se refere a atividade 1.1 e 1.2 da Atividade Pratica 01" << endl;
  cout << "  * Primeiramente ele ira retornar o numero de espacos do arquivo: arquivo.txt" << endl;
  cout << "  * Em seguida digite a sequencia de numeros desejada" << endl;
  leLinha();
  cout << numeroEspacos << endl;
  leVetor();
}