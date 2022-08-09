#include <iostream>
#include <cmath>

using namespace std;

class Ponto{
    double abscissa, ordenada;
public:
    Ponto(double x, double y) : abscissa(x), ordenada(y) {}

    double getX(){
        return abscissa;
    }
    double getY(){
        return ordenada;
    }
    double distanciaParaPonto(Ponto p){
        double distancia;
        double x = p.getX();
        double y = p.getY();

        distancia = ((x - abscissa)*(x - abscissa)) + ((y - ordenada)*(y - ordenada));
        distancia = sqrt(distancia);

        return distancia;
    }
};
class Reta{
        double m, b;
public:
    Reta(Ponto p1, Ponto p2){
        double a, c, d, e;

        a = p2.getY();
        c = p2.getX();
        d = p1.getY();
        e = p1.getX();

        m = (a - d)/(c - e);
        b = a - (m * c);
    }
    double getM(){
        return m;
    }
    double getB(){
        return b;
    }
    double distanciaParaPonto(Ponto p0){
        double distancia2;
        double x, y, a, c;

        a = p0.getX();
        c = p0.getY();

        x = m*a + b-c;
        x = fabs(x);
        y = 1 + (m*m);
        y = sqrt(y);
        distancia2 = x/y;
        return distancia2;
    }
    bool ehPararela(Reta r){
        double a;
        a = r.getM();
        if(m == a)
            return true;
        else
            return false;
    }
};

int main()
{

    double x;

    Ponto A(1, 2);
    Ponto B(4, 4);
    Ponto C(1, 4);
    Ponto D(4, 6);
    Ponto E(4, 2);

    x = A.distanciaParaPonto(B);
    cout << x << endl;

    Reta R1(A, B);

    x = R1.getM();
    cout << x << endl;
    x = R1.getB();
    cout << x << endl;

    Reta R2(C, D);

    x = R2.getM();
    cout << x << endl;
    x = R2.getB();
    cout << x << endl;

    x = R1.distanciaParaPonto(E);
    cout << x << endl;

    x = R1.ehPararela(R2);
    if(x = 1)
        cout << "eh paralela" << endl;
    else
        cout << "nao eh paralela" << endl;

    cout << "Valeu Alvaro B)";
}
