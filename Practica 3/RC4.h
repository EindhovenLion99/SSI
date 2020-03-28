#include <iostream>
#include <vector>

using namespace std;

class RC4 {
 private:
  vector<int> S;   // Vecotr S
  vector<int> K;   // Vector K
  vector<int> Cipher;
  int i, j;

 public:
  RC4(void);                  // Constructor Vacio
  RC4(vector<int> sem);       // Constructor parametrizado
  int PRGA();                 // Algoritmo PRGA
  vector<int> Cifrado(vector<int> msg);   // Cifrado {}
  vector<int> Sec();                      // Retorna la secuencia cifrante
};