#include <iostream>
#include <vector>
#include <string>

using namespace std;

string organizaPalavra(string palavra)
{
    int T, x;
    T = palavra.size();
    for(int i = 0; i < T; i++){
        x = palavra[i];
        if(x >= 65 and x <= 90)
        {   x = x + 32;
            palavra[i] = x;
        }
    } return palavra;
}

int main()
{
    int A, i, j, x = 0;
    int tamTotal = 0;
    int tam = 0;
    string palavra;
    vector <string> V;

    cout << "Insira o numero de palavras que deseja escrever \n";
    cin >> A;

    for(i = 0; i != A; i++)
    {
        cin >> palavra;
        tam = palavra.size();
        tamTotal = tamTotal + tam;
        palavra = organizaPalavra(palavra);
        V.push_back(palavra);
    }

    vector<string>::iterator base;
    vector<string>::iterator aux;

    string help;

    do{
        base = V.begin();
        aux = V.begin()+1;
        for(i = 0; i < A-1; i++){
            if(*base < *aux){
                help = *base;
                *base = *aux;
                *aux = help;
            }
            base++;
            aux++;
        }x++;
   }while(x <= A);

   cout << "a quantidade de caracteres digitados eh " << tamTotal << endl;

   for(i = A-1; i != 0; i--){
        cout << V[i] << endl;
   } cout << V[0];

    return 0;
}
