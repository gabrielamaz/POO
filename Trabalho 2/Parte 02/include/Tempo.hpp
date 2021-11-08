#ifndef TEMPO_HPP
#define TEMPO_HPP

class Tempo {
 private:
  int dia;
  int hora;
  int min;
  int seg;

  void verificaSegundos();
  void verificaMinutos();
  void verificaHoras();

 public:
  Tempo(int dia = 0, int hora = 0, int min = 0, int seg = 0);

  int getSeg() { return seg; }

  int getMin() { return min; }

  int getHora() { return hora; }

  int getDia() { return dia; }

  void setSeg(int seg) { this->seg = seg; }

  void setMin(int min) { this->min = min; }

  void setHora(int hora) { this->hora = hora; }

  void setDia(int dia) { this->dia = dia; }

  void verificaConsistencia();
  Tempo somaTempo(Tempo t1);
  void leituraArquivo();
  void escritaArquivo();
  void incrementaSegundo();
  void incrementaMinuto();
  void incrementaHora();
  void incrementaDia();
};

#endif
