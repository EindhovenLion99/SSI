#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

class AES {
 private:
 public:
  AES();
  ~AES();
  int CajaS(int pos);      // Accede a la caja y evuelve el valor necesario
  void SubClaves(unsigned char (*arrClave)[4], unsigned char *mClaveExp);
  void addRoundKey(int pos, unsigned char (*texto)[4], unsigned char *mClaveExp);
  void subBytes(unsigned char (*texto)[4]);
  void shiftRows(unsigned char (*texto)[4]);
  void mixColumns(unsigned char (*r)[4]);
  void Claves(unsigned char (*texto)[4], unsigned char *mClaveExp);
};