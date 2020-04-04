#include <iostream>
#include <vector>
#include "RC4.h"

using namespace std;

int main() {
  int sz;
  int Y;

  vector<int> Msg;    // Almacenamos el mensaje
  vector<int> Sem;    // Almacenamos la semilla

  // Leemos la semila por pantalla

  cout << "Introduzca el tamaño de la clave: ";
  cin >> sz;
  Sem.resize(sz);

  cout << "Introduzca la clave" << endl;
  for (int i = 0; i < Sem.size(); i++) {
    cout << "Posicion [" << i << "]: ";
    cin >> Y;
    Sem[i] = Y;
  }

  cout << endl;

  // Introducimos el mensaje

  cout << "Introduzca el tamaño del mensaje: ";
  cin >> sz;

  Msg.resize(sz);

  cout << "Introduzca el mensaje" << endl;
  for (int i = 0; i < Msg.size(); i++) {
    cout << "Mensaje [" << i << "]: ";
    cin >> Y;
    Msg[i] = Y;
  }

  // Mensaje { 1, 34 }
  // Semilla { 2, 5 }

  cout << endl;

  vector<int> Nuevo_Cifrado(Msg.size());  // Este vector tendra el cifrado { 145, 44}

  RC4 X(Sem);   // Creamos el objeto RC4 mandando la semilla

  Nuevo_Cifrado = X.Cifrado(Msg);   // Llamamos al cifrado, enviando el mensaje

  vector<int> Sec = X.Sec();        // Llamamos a SEC que nos manda la secuencia

  cout << "Mensaje Original: ";
  for (int i = 0; i < Msg.size(); i++) {
    if (i == Msg.size() - 1)
      cout << Msg[i];
    else
      cout << Msg[i] << ", ";
  }
  cout << endl;
  cout << "Semilla: ";
  for (int i = 0; i < Sem.size(); i++) {
    if (i == Sem.size() - 1)
      cout << Sem[i];
    else
      cout << Sem[i] << ", ";
  }

  cout << endl;
  cout << "Secuencia cifrante: ";
  for (int i = 0; i < Sec.size(); i++) {
    if (i == Sec.size() - 1)
      cout << Sec[i];
    else
      cout << Sec[i] << ", ";
  }
  cout << endl;
  cout << "Mensaje cifrado: ";
  for (int i = 0; i < Nuevo_Cifrado.size(); i++) {
    if (i == Nuevo_Cifrado.size() - 1)
      cout << Nuevo_Cifrado[i];
    else
      cout << Nuevo_Cifrado[i] << ", ";
  }
  cout << endl;
}