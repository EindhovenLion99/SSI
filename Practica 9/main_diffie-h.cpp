#include <iostream>
#include <math.h>

using namespace std;

bool isPrimo(int p){
    int cont = 0, i = 1;
    while(i < p){
        if(p % i  == 0){
            cont++;
        }
        i++;
    }
    if(cont > 2){
        return false;
    } else {
        return true;
    }
}

bool impar(int x){
    return x % 2 == 0;
}

int exponenciacionRapida(int a, int n, int m){
    int exp = 1;
    int x = fmod(a, m);
    while (n > 0){
        if(impar(n)){
            exp = fmod(exp*n, m);
        }
        x = fmod(x*x, m);
        n /= 2; 
    }
    return exp;
}

void DiffieHellman(int p, int a, int xa, int xb){
    int ya = exponenciacionRapida(a, xa, p);
    int yb = exponenciacionRapida(a, xb, p);
    int k1 = exponenciacionRapida(yb, xa, p);
    int k2 = exponenciacionRapida(ya, xb, p);

    cout << "ya: " << ya << endl;
    cout << "yb: " << yb << endl;
    cout << "k1: " << k1 << endl;
    cout << "k2: " << k2 << endl;

    if(k1 == k2){
        cout << "Clave k generada, " << k1 << endl;
    }
}



int main(){

    // Diffie-Hellman
    int p, a, xa, xb;
    cout  << "Introduzca los datos para ejecutar el algoritmo:" << endl;
    cout << "Numero primo - p -: "; cin >> p;
    cout << "Alpha - a -: ";        cin >> a;
    cout << "Numero a - xa -: ";    cin >> xa;
    cout << "Numero b - xb -: ";    cin >> xb;

    if(!isPrimo(p)){
        cout << "ERROR, p no es primo" << endl;
    } else if(a > p){
        cout << "ERROR, a mayor que p: " << a << " > " << p << endl;
    } else {
        DiffieHellman(p, a, xa, xb);
    }
}