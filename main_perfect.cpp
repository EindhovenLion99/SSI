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

void Print(string word, vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
  cout << word << "\t"
       << " -> ";

  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << endl;
  cout << "Clave"
       << "\t"
       << " -> ";

  for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
  cout << endl;

  cout << "Suma"
       << "\t"
       << " -> ";

  for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
  cout << endl;

  cout << "Codigo nuevo: " << BinaryStringToText(c) << endl;
  cout << "Codigo anterior: " << BinaryStringToText(d) << endl;
}

int main() {
  vector<int> y{0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1,
                1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1};
  vector<int> j{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1};
  bool w = 0;

  int Opc;
  cout << "Introduzca la dimension (2 o 3): ";
  cin >> Opc;

  vector<int> suma;
  // Introducimos la palabra
  string Palabra;
  cout << "Introduzca la palabra: ";
  cin >> Palabra;

  vector<int> x = convertBinary(Palabra);
  vector<int> Decod;
  switch (Opc) {
    case 2:
      suma = Sum(x, j);
      Decod = Sum(suma, j);
      Print(Palabra, x, j, suma, Decod);
      break;
    case 3:
      suma = Sum(x, y);
      Decod = Sum(suma, y);
      Print(Palabra, x, y, suma, Decod);
      break;
    default:
      cout << "Introduzca 2 o 3" << endl;
  }
}
