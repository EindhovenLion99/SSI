#include <iostream>
#include <math.h>

using namespace std;

bool iteraciones(int N, int s, int v)
{
    int x, a, y;
    int e;

    cout << "Escoge un numero secreto x (Compromisosecreto de A): ";
    cin >> x;

    a = fmod(x * x, N);

    cout << endl
         << "a: " << a << endl;

    cout
        << "Escoge el bit e (Respuesta): ";
    cin >> e;

    if (e == 0)
    {
        y = fmod(x, N);
        cout << endl
             << "Comprobar " << y << "^2 = " << a << " (mod " << N << " )" << endl;
    }
    else
    {
        y = fmod(x * s, N);
        cout << endl
             << "Comprobar " << y << "^2 = " << a << " * " << v << " (mod " << N << " )" << endl;
    }

    if (e == 0)
    {
        if (fmod(y * y, N) == fmod(a, N))
        {
            return true;
        }
        return false;
    }
    else
    {
        if (fmod(y * y, N) == fmod(a * v, N))
        {
            return true;
        }
        return false;
    }
}

int main()
{
    int p, q, N, s, v;

    cout << "Introduce el numero p: ";
    cin >> p;
    cout << "Introduce el numero q: ";
    cin >> q;

    N = p * q;

    cout << "Escoge un numero secreto s (Identificacion secreta de A): ";
    cin >> s;

    v = fmod(s * s, N);

    int j;
    cout << "Escoge el numero de iteraciones: ";
    cin >> j;

    cout << endl
         << "N: " << N << endl;

    cout << endl
         << "v: " << v << endl;

    for (int i = 0; i < j; i++)
    {
        bool a = iteraciones(N, s, v);
        if (a)
        {
            cout << "Iteracion " << i << " correcta" << endl;
        }
        else
        {
            cout << "Iteracion " << i << " incorrecta" << endl;
        }
    }
}