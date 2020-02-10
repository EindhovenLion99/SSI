#include <assert.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> convertBinary(string s) {  // Palabra ASCII a binario
  vector<int> Bin;

  /*
  for (int i = 0; i <= s.size(); i++) {
    int valor = int(s[i]);
    Bin.push_back(0);

    while (valor > 0) {
      if (valor % 2 == 1) {
        Bin.push_back(1);
      } else {
        Bin.push_back(0);
      }
      valor /= 2;
    }
  }
  */

  int c;
  for (int i = 0; s[i] != '\0'; i++) {
    c = s[i];
    for (int j = 7; j >= 0; j--) {
      if (c >= (1 << j)) {
        c = c - (1 << j);
        Bin.push_back(1);
      } else {
        Bin.push_back(0);
      }
    }
  }

  return Bin;
}

vector<int> key(int size) {
  vector<int> Key;
  srand(time(NULL));

  for (int i = 0; i < size; i++) {
    Key.push_back(rand() % 2);
  }

  return Key;
}

vector<int> Sum(vector<int> a, vector<int> b) {
  vector<int> z;
  int aux = 0;
  for (int i = 0; i < a.size(); i++) {
    aux = a.at(i) ^ b.at(i);
    z.push_back(aux);
  }

  return z;
}

string BinaryStringToText(vector<int> a) {  // Pasamos binario a codigo ASCII
  string text = "";
  stringstream ss;
  for (size_t i = 0; i < a.size(); ++i) {
    if (i != 0) ss << "";
    ss << a[i];
  }
  string s = ss.str();
  stringstream sstream(s);
  while (sstream.good()) {
    bitset<8> bits;
    sstream >> bits;
    text += char(bits.to_ulong());
  }

  return text;
}

int main() {
  vector<int> y{1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0,
                1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};
  vector<int> j{1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1};
  bool w = 0;

  int Opc;
  cout << "Introduzca la dimension (2 o 3): ";
  cin >> Opc;

  // Convertimos la palabra a binario

  // Generando clave aleatoria
  // vector<int> y = key(x.size());

  vector<int> suma;
  // Introducimos la palabra
  string Palabra;
  cout << "Introduzca la palabra: ";
  cin >> Palabra;
  vector<int> x = convertBinary(Palabra);
  switch (Opc) {
    case 2:
      suma = Sum(x, j);
      cout << Palabra << "\t"
           << " -> ";

      for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
      cout << endl;
      cout << "Clave"
           << "\t"
           << " -> ";

      for (int i = 0; i < j.size(); i++) cout << y[i] << " ";
      cout << endl;

      cout << "Suma"
           << "\t"
           << " -> ";

      for (int i = 0; i < suma.size(); i++) cout << suma[i] << " ";
      cout << endl;

      // Imprimimos la palabra nueva generada
      cout << "Codigo nuevo: " << BinaryStringToText(suma) << endl;
      break;
    case 3:
      suma = Sum(x, y);
      cout << Palabra << "\t"
           << " -> ";

      for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
      cout << endl;
      cout << "Clave"
           << "\t"
           << " -> ";

      for (int i = 0; i < y.size(); i++) cout << y[i] << " ";
      cout << endl;

      cout << "Suma"
           << "\t"
           << " -> ";

      for (int i = 0; i < suma.size(); i++) cout << suma[i] << " ";
      cout << endl;

      // Imprimimos la palabra nueva generada
      cout << "Codigo nuevo: " << BinaryStringToText(suma) << endl;
      break;
    default:
      cout << "Introduzca 2 o 3" << endl;
  }
}
