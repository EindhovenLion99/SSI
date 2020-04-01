#include "AES.h"
#include <iostream>

using namespace std;

int main() {
  unsigned char Clave_Expand[176];  // Expansion de la clave
  unsigned char Clave[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05,   // CLAVE
                             0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
                             0x0c, 0x0d, 0x0e, 0x0f};
  unsigned char Texto[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55,   // TEXTO
                             0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb,
                             0xcc, 0xdd, 0xee, 0xff};

  unsigned char mTexto[4][4];   // Matriz 4x4 del Texto
  unsigned char mClave[4][4];   // Matriz 4x4 de la Clave

  cout << endl << "CLAVE: ";
  for (int i = 0; i < 16; i++) {
    printf("%02x ", Clave[i]);
  }
  cout << endl << "TEXTO: ";
  for (int i = 0; i < 16; i++) {
    printf("%02x ", Texto[i]);
  }

  cout << endl << endl;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mClave[j][i] = Clave[i * 4 + j];  // Rellenamos la matriz de la clave
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mTexto[j][i] = Texto[i * 4 + j];  // Rellenamos la matriz del texto
    }
  }

  AES Rijndael;
  Rijndael.SubClaves(mClave, Clave_Expand);  // Expansion de clave
  Rijndael.Claves(mTexto, Clave_Expand);      // Cifrado del Texto
  cout << endl << endl;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%02x ", mTexto[j][i]);
    }
  }
  cout << endl;

}