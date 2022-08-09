#include <iostream>

using namespace std;

class Fila{
    static int filas;
    static int tamanhoTotal;
    int tamanho = 0;
    int FI = 0;
    int FO = 0;
    int vetor[50];
public:
    Fila(){filas++;}
    Fila(const Fila &obj){
        filas++;
        this->tamanho = obj.tamanho;
        this->FI = obj.FI;
        this->FO = obj.FO;
        for(int i = 0; i < 50; i++){
            this->vetor[i] = obj.vetor[i];
        }
        tamanhoTotal = tamanhoTotal + obj.tamanho;
    }
    Fila(int a, int b, int c) : tamanho(a), FI(b), FO(c) {filas++;}
    ~Fila(){
        filas--;
        tamanhoTotal = tamanhoTotal - this->tamanho;
        delete this;
    }
    int getTamanho(){return tamanho;}
    int getFI(){return FI;}
    int getFO(){return FO;}
    int getVet(int i){return vetor[i];}
    void enqueue(int x){
        if(tamanho == 50)
            throw -1;
        if(FI <= 49){
        vetor[FI] = x;
        FI++;
        tamanhoTotal++;
        tamanho++;}
        else if (FI == 50){
            FI = 0;
            vetor[FI] = x;
            FI++;
            tamanhoTotal++;
            tamanho++;
        }
    }
    int dequeue(){
        if(this->tamanho == 0)
            throw -2;
        else if(FO <= 49){
            int valor = vetor[FO];
            vetor[FO] = 0;
            FO++;
            tamanho--;
            tamanhoTotal--;
            return valor;}
        else if(FO == 50){
                FO = 0;
                int valor = vetor[FO];
                vetor[FO] = 0;
                FO++;
                tamanho--;
                tamanhoTotal--;
                return valor;
        }
    }

    static void stats(){
        cout << "Ha " << filas << " com tamanho total " << tamanhoTotal << endl;
    }

    Fila &operator=(Fila &aux){
            tamanhoTotal = tamanhoTotal - this->getTamanho();
            this->tamanho = aux.getTamanho();
            this->FI = aux.getFI();
            this->FO = aux.getFO();
        for(int i = 0; i < 50; i++){
        this->vetor[i] = aux.getVet(i);
        }
        tamanhoTotal = tamanhoTotal + aux.getTamanho();
        return aux;
    } 

};

int Fila::filas;
int Fila::tamanhoTotal;

int main() {
Fila::stats();
Fila *a = new Fila();
for (int i=0;i<4;i++)
a->enqueue(i);
Fila b = (*a);
Fila::stats();
b.enqueue (4);
b.enqueue (5);
Fila c = (*a);
Fila::stats();
c = b;
Fila::stats();
int x = c.dequeue();
delete a;
Fila::stats();
return 0;
}