#ifndef TEMPO_HPP
#define TEMPO_HPP

class Tempo {
  public:
    Tempo(int dia = 0, int hora = 0, int min = 0, int seg = 0);
    void verificaConsistencia();
    Tempo somaTempo(Tempo t1);
    void leituraArquivo();
    void escritaArquivo();
    void incrementaSegundo();

 private:
  int dia;
  int hora;
  int min;
  int seg;
};

#endif
