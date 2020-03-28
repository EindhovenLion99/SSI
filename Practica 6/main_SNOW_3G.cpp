#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>

using namespace std;

int hexa2deci(string s) {     // Funcion Hexadimal -> Decimal
  int decimal = 0;
  int sz = s.length();
  for (int i = 0; i < sz; i++) {
    char digit = s[sz - 1 - i];
    if (digit >= '0' && digit <= '9') {
      decimal += (digit - '0') * pow(16, i);
    } else {
      decimal += (digit - 'A' + 10) * pow(16, i);
    }
  }
  return decimal;
}

int main() {
  bitset<8> byte_aes("00011011");  // Byte algoritmo AES
  bitset<8> byte_3GS("10101001");  // Byte algoritmo SNOW

  string num_1, num_2;

  cout << "Introduzca el primer numero en hexadecimal: ";
  cin >> num_1;
  cout << "Introduzca el segundo numero en hexadecimal: ";
  cin >> num_2;
  cout << endl;

  int num_dec_1 = hexa2deci(num_1);
  int num_dec_2 = hexa2deci(num_2);

  bitset<8> byte_1(num_dec_1);  // Primer Byte
  bitset<8> byte_2(num_dec_2);  // Segundo Byte

  cout << "byte_1: " << byte_1 << endl;
  cout << "byte_2: " << byte_2 << endl;
  cout << endl;

  // Procedemos a hacer la multiplicacion:

  bitset<8> Sum;
  bitset<8> aux;

  if (byte_2[0] == 1) {
    Sum = byte_1;
  } else {
    bitset<8> Sum(0);
  }
  aux = byte_1;

  int x = 1;

  cout << "**********************************" << endl;
  cout << x << ". " << aux << endl;
  for (int i = 1; i < 8; i++) {
    if (aux[7] == 1) {
      aux <<= 1;
      cout << ++x << ". ";
      cout << aux << " <-" << endl;
      cout << "+  " << byte_aes << endl;
      aux ^= byte_aes;
      cout << "Suma da: " << aux << endl;
    } else {
      aux <<= 1;
      cout << ++x << ". " << aux << " <-" << endl;
    }
    if (byte_2[i] == 1) {
      Sum ^= aux;
    }
  }
  cout << endl << "**********************************" << endl;

  cout << "La suma final da: " << Sum << endl;
  // cout << cont << endl;
}