#include <iostream>
#include <math.h>

using namespace std;

bool isPrimo(int p)
{
    int cont = 0, i = 1;
    while (i < p)
    {
        if (p % i == 0)
        {
            cont++;
        }
        i++;
    }
    if (cont > 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool impar(int x)
{
    if (x % 2 == 1)
        return true;
    return false;
}

int exponenciacionRapida(int a, int n, int m)
{
    int exp = 1;
    int x = fmod(a, m);
    cout << x << " | " << n << " | " << exp << endl;
    cout << "-----------" << endl;
    while (n > 0)
    {
        if (impar(n))
        {
            exp = fmod(x * exp, m);
            n--;
            cout << "  | ";
            cout << n << " | ";
            cout << exp << endl;
        }
        if (!impar(n))
        {
            x = fmod(x * x, m);
            n /= 2;
            if (n != 0)
            {
                cout << x << " | ";
                cout << n << " | " << endl;
            }
        }
    }
    cout << endl;
    return exp;
}

void DiffieHellman(int p, int a, int xa, int xb)
{
    cout << "************** yA **************" << endl;
    int ya = exponenciacionRapida(a, xa, p);
    cout << "************** yB **************" << endl;
    int yb = exponenciacionRapida(a, xb, p);
    cout << endl;
    cout << "************** k1 **************" << endl;
    int k1 = exponenciacionRapida(yb, xa, p);
    cout << "************** k2 **************" << endl;
    int k2 = exponenciacionRapida(ya, xb, p);

    cout << endl;

    cout << "k1: " << k1 << endl;
    cout << "k2: " << k2 << endl
         << endl;

    if (k1 == k2)
    {
        cout << "Clave k generada, " << k1 << endl;
    }
    else
    {
        cout << "ERROR, las claves son diferetes" << endl;
    }
}

int main()
{

    // Diffie-Hellman
    int p, a, xa, xb;
    cout << "Introduzca los datos para ejecutar el algoritmo:" << endl
         << endl;
    cout << "Numero primo - p -: ";
    cin >> p;
    cout << "Alpha - a -: ";
    cin >> a;
    cout << "Numero a - xa -: ";
    cin >> xa;
    cout << "Numero b - xb -: ";
    cin >> xb;

    cout << endl;

    if (!isPrimo(p))
    {
        cout << "ERROR, p no es primo" << endl;
    }
    else if (a > p)
    {
        cout << "ERROR, a mayor que p: " << a << " > " << p << endl;
    }
    else
    {
        DiffieHellman(p, a, xa, xb);
    }
}