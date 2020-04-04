#include "RC4.h"

RC4::RC4(void): S(0), K(0), i(0), j(0) {}

RC4::RC4 (vector<int> sem): S(256), K(256), i(0), j(0) {    // Algoritmo KSA
  for(int i = 0; i < 256; i++){   // Vector S y K
    S[i] = i;
    K[i] = sem[i % sem.size()];
  }
  int j = 0;
  for(int i = 0; i < 256; i++){
    j = (j + S[i] + K[i]) % 256;
    swap(S[i], S[j]);
  }
}

int RC4::PRGA(){     // Algoritmo para la secuencia cifrante
  int x;
  i = (i + 1) % 256;
  j = (j + S[i]) % 256;
  swap(S[i], S[j]);

  x = (S[i] + S[j]) % 256;

  return S[x];
}

vector<int> RC4::Cifrado(vector<int> msg){  // XOR entre los bytes de la secuencia cifrante y los de el mensaje.
  int C;
  vector<int> Mensaje_C(msg.size());
  Cipher.resize(msg.size());

  for(int i = 0; i < msg.size(); i++){
    C = PRGA();                               // Generamos cada byte
    Cipher[i] = C;                            // Lo introducimos
    Mensaje_C[i] = msg[i] ^ C;                // Operacion XOR
  }
  return Mensaje_C;
}

vector<int> RC4::Sec(){                      // Retornamos la secuencia cifrante, ninguna operacion
  return Cipher;
}
