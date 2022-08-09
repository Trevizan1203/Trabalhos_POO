#include <iostream>
#include <cmath>

using namespace std;

class base{
    virtual void resolver() = 0;
};

class primeiroGrau;
ostream& operator<<(ostream& stream, primeiroGrau eq);

class primeiroGrau : public base{
    double a, b;
public:
    primeiroGrau(double x, double y): a(x), b(y){}

    void resolver(){cout << "a raiz da equacao " << *this << " eh: " << ((-b)/a) << endl;}

    double getA(){return a;}
    double getB(){return b;}

    void setA(double A){a = A;}
    void setB(double B){b = B;}

    primeiroGrau operator+(primeiroGrau equacao2){
        primeiroGrau novo = (*this);

        novo.setA(novo.getA() + equacao2.getA());
        novo.setB(novo.getB() + equacao2.getB());

        return novo;
    }

    primeiroGrau operator-(primeiroGrau equacao2){
        primeiroGrau novo = (*this);

        novo.setA(novo.getA() - equacao2.getA());
        novo.setB(novo.getB() - equacao2.getB());

        return novo;
    }
};

ostream& operator<<(ostream& stream, primeiroGrau eq){
        stream << eq.getA() << "x ";
            if(eq.getB() > 0)
                stream << "+ ";
        stream << eq.getB() << " = 0";
        return stream;
    }

class segundoGrau;
ostream& operator<<(ostream& stream, segundoGrau eq);

class segundoGrau : public base{
    double a, b, c;
public:
    segundoGrau(double x, double y, double z): a(x), b(y), c(z){}

    void resolver(){
        if((b*b)-(4*a*c)<0)
            throw "o delta da equacao eh negativo, portanto, as raizes sao numeros imaginarios";
        else{
            cout << "equacao: " << *this << endl;
            cout << "raiz 1: " << ((-b)+sqrt((b*b) - (4*a*c)))/(2*a) << "\n";
            cout << "raiz 2: " << ((-b)-sqrt((b*b) - (4*a*c)))/(2*a) << endl;
        }
        }

    double getA(){return a;}
    double getB(){return b;}
    double getC(){return c;}

    void setA(double A){a = A;}
    void setB(double B){b = B;}
    void setC(double C){c = C;}

    segundoGrau operator+(segundoGrau equacao2){
        segundoGrau novo = (*this);

        novo.setA(novo.getA() + equacao2.getA());
        novo.setB(novo.getB() + equacao2.getB());
        novo.setC(novo.getC() + equacao2.getC());

        return novo;
    }

    segundoGrau operator-(segundoGrau equacao2){
        segundoGrau novo = (*this);

        novo.setA(novo.getA() - equacao2.getA());
        novo.setB(novo.getB() - equacao2.getB());
        novo.setC(novo.getC() - equacao2.getC());

        return novo;
    }
};

ostream& operator<<(ostream& stream, segundoGrau eq){
        stream << eq.getA() << "x^2 ";
            if(eq.getB() > 0)
                stream << "+ ";
        stream << eq.getB() << "x ";
            if(eq.getC() > 0)
                stream << "+ ";
        stream << eq.getC() << " = 0";
        return stream;
    }

int main()
{
    primeiroGrau eq1(2, 3);

    cout << "Eq1: " << eq1 << endl;
    eq1.resolver();

    segundoGrau eq2(1, 1, -6);

    cout << "Eq2: " << eq2 << endl;
    eq2.resolver();

    segundoGrau eq3 (1,1,1);
    segundoGrau eq4 = eq2 + eq3;

    cout << "Eq4: " << eq4 << endl;
        eq4 = eq4 - eq3;
    cout << "Eq4: " << eq4 << endl;

    return 0;
}
