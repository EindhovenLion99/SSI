#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string key_generator(string Mensaje, string key) {
  int j = 0;
  string newkey;
  for (int i = 0; i < Mensaje.size(); i++) {
    if (Mensaje[i] != ' ') {
      newkey.push_back(key[j]);
      j++;
      if (j == key.size()) j = 0;
    }
  }
  return newkey;
}

vector<int> num_alf(string msg, string a, string b) {
  vector<int> aux;
  for (int i = 0; i < msg.size();
       i++) {  // Convertimos la frase a un vector de int
    for (int j = 0; j < a.size(); j++) {
      if (msg[i] == a[j] || msg[i] == b[j]) {
        aux.push_back(j);
      }
    }
  }
  return aux;
}

vector<int> sum(vector<int> a, vector<int> b) {
  vector<int> aux;
  int x;
  for (int i = 0; i < a.size(); i++) {
    x = a[i] + b[i];
    if (x <= 25) {
      aux.push_back(x);
    } else {
      aux.push_back(x % 26);
    }
  }
  return aux;
}

vector<int> resta(vector<int> a, vector<int> b) {
  vector<int> aux;
  int x;
  for (int i = 0; i < a.size(); i++) {
    x = a[i] - b[i];
    if (x < 0) {
      x += 26;
    }
    if (x <= 25) {
      aux.push_back(x);
    } else {
      aux.push_back(x % 26);
    }
  }
  return aux;
}

int main() {
  // Vector del alfabeto
  string alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                     'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                     's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  string alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                      'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                      'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  string mensaje_;
  string key_;

  cout << "Introduzca la frase a codificar: ";
  getline(cin, mensaje_);
  cout << "Introduzca la clave: ";
  cin >> key_;

  cout << endl;

  cout << "MENSAJE ORIGINAL: " << mensaje_ << endl;
  cout << "CLAVE: " << key_ << endl;

  cout << endl;

  string new_key = key_generator(mensaje_, key_);

  cout << "NUEVA CLAVE AUMENTADA: " << new_key << endl;

  vector<int> num_alf_m = num_alf(mensaje_, alphabet, alphabet_);
  vector<int> num_alf_k = num_alf(new_key, alphabet, alphabet_);

  vector<int> suma = sum(num_alf_m, num_alf_k);

  string Codificado;
  int j = 0;
  for (int i = 0; i < mensaje_.size(); i++) {
    if (isupper(mensaje_[i])) {
      Codificado.push_back(alphabet_[suma[j]]);
      j++;
    } else if (islower(mensaje_[i])) {
      Codificado.push_back(alphabet[suma[j]]);
      j++;
    }
  }

  vector<int> rest = resta(suma, num_alf_k);
  string Descifrado;
  j = 0;
  for (int i = 0; i < Codificado.size(); i++) {
    if (isupper(Codificado[i])) {
      Descifrado.push_back(alphabet_[rest[j]]);
      j++;
    } else if (islower(Codificado[i])) {
      Descifrado.push_back(alphabet[rest[j]]);
      j++;
    }
  }

  cout << endl;
  cout << "MENSAJE ENCRIPTADO: " << Codificado << endl;
  cout << "MENSAJE DESCIFRADO: " << Descifrado << endl;
}