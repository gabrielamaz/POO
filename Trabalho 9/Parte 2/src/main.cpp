#include <iostream>
#include <cmath>
using namespace std;

class Funcao
{   
    private:
        double resultado = 0; 

    public:

    //funcao que obtem a integral da funcao pela regra do trapezio
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos){
        //equação: h((f(a)-f(b))/2)+somatório(f(x))
        
        double somatorio = 0;

        //calculo de h
        double h = (limiteSuperior - limiteInferior)/intervalos;

        //calculo do somatorio de f(x)
        for(int i = 1; i <= intervalos-1; i++){
            somatorio += func(limiteInferior + i*h);
        }

        //aplicacao da equação
        resultado = (h*((func(limiteInferior) + func(limiteSuperior))/2)) + h*somatorio;

        return resultado;
    }

    // funcao virtual representando a funcao cuja integral deve ser calculada
    virtual double func(double input) = 0;

    // destrutor
    virtual ~Funcao(){}
};

class Quadratica : public Funcao {
    private:

        double output = 0;
        int _a;
        int _b;
        int _c;
    
    public:

        Quadratica(int a, int b, int c){
            this->_a = a;
            this->_b = b;
            this->_c = c;
        }

        ~Quadratica() {}

        virtual double func(double input){
            output = pow(input, 2) + 2*input + 4;
            return output;
        }
};

class Senoide : public Funcao {
    private:

        double output = 0;

    public:

        Senoide(){ }

        ~Senoide() {}

        virtual double func(double input){
            output = sin(input)/input;
            return output;
        }
};

class Linear : public Funcao {
    private:
        double output = 0;
        int _a;
        int _b;

    public:
        Linear(int a, int b){
            this->_a = a;
            this->_b = b;
        }

        ~Linear() {};

        virtual double func(double input){
            output = input + 4;
            return output;
        }
};

int main()
{
    double resultado;

    //cria um container de ponteiros do tipo Funcao
    Funcao *f[3];

    f[0] = new Quadratica(1,2,4);
    f[1] = new Senoide();
    f[2] = new Linear(1,4);

    cout << "*** Calculo de integrais usando a regra do trapezio: ***"<<endl<<endl;
    cout << "*** Funcoes ***" << endl;
    cout << "(1) x^2 + 2x + 4" << endl;
    cout << "(2) sen(x) / x" << endl;
    cout << "(3) x + 4" << endl;
    cout << endl;

    for (int i=0; i<3; i++)
    {
        resultado = f[i]->getIntegral(1,4,1000);
        cout << "Integral da Funcao (" << i+1 << "): " << resultado;
        cout << endl;
    }

    for (int i=0; i<3; i++)
    {
        delete f[i];
    }

    return 0;
}