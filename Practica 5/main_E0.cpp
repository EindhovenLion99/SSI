#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

const int sz_1 = 25;
const int sz_2 = 31;
const int sz_3 = 33;
const int sz_4 = 39;

const int sz_R1 = 2;

int main() {
  bitset<sz_1> LFSR1("1111111111111111111111101");
  bitset<sz_2> LFSR2("0111111111111111111111111111111");
  bitset<sz_3> LFSR3("011111111111111111111111111111111");
  bitset<sz_4> LFSR4("010101010101010101010101010101010101010");

  bitset<sz_R1> R1("01");
  bitset<sz_R1> R2;
  
  cout << "LFSR1[0]: " << LFSR1[0] << endl;
  cout << "LFSR1[1]: " << LFSR1[1] << endl;
  cout << "LFSR1[25]: " << LFSR1[24] << endl;

  for (int i = 0; i < 4; i++) {
    // Polinomio de cada registro

    int pol_1 = LFSR1[sz_1 - 8] ^ LFSR1[sz_1 - 12] ^ LFSR1[sz_1 - 20] ^
                LFSR1[sz_1 - 25];  // -> 0
    int pol_2 = LFSR2[sz_2 - 12] ^ LFSR2[sz_2 - 16] ^ LFSR2[sz_2 - 24] ^
                LFSR2[sz_2 - 31];  // -> 0
    int pol_3 = LFSR3[sz_3 - 4] ^ LFSR3[sz_3 - 24] ^ LFSR3[sz_3 - 28] ^
                LFSR3[sz_3 - 33];  // -> 0
    int pol_4 = LFSR4[sz_4 - 4] ^ LFSR4[sz_4 - 28] ^ LFSR4[sz_4 - 36] ^
                LFSR4[sz_4 - 39];  // -> 1

    // Procedemos a calcular la primera suma decimal

    int sum_1 = 0;
    if (LFSR1[sz_1 - 25] == 1) {
      sum_1++;
    }
    if (LFSR2[sz_2 - 31] == 1) {
      sum_1++;
    }
    if (LFSR3[sz_3 - 33] == 1) {
      sum_1++;
    }
    if (LFSR4[sz_4 - 39] == 1) {
      sum_1++;
    }

    // Intercambio de posiciones R1

    int aux = R1[0];
    R1[0] = R1[1];  // Utilzaremos este bit en la operacion de salida
    R1[1] = aux;

    int x = R1.to_ulong();  // Pasamos R1 (10) a decimal (2)

    // Creamos el R2 a partir del R1

    R2[0] = R1[1];
    R2[1] = R1[0];

    // Sumamos el numero de 1s con x

    int sum_2 = sum_1 + x;

    int div = sum_2 / 2;
    bitset<2> Z(div);

    // Construimos T1 y T2

    bitset<sz_R1> T1(R1);

    bitset<sz_R1> T2;
    T2[1] = R2[0];
    T2[0] = R2[1] ^ R2[0];

    // Las primeras puertas XOR

    bitset<sz_R1> xor_1;
    for (int i = 0; i < sz_R1; i++) {
      xor_1[i] = T2[i] ^ Z[i];
    }

    bitset<sz_R1> xor_2;
    for (int i = 0; i < sz_R1; i++) {
      xor_2[i] = xor_1[i] ^ T1[i];
    }

    // Multiplicacion R1[0] Y LFSR

    int K = LFSR1[sz_1 - 25] ^ LFSR2[sz_2 - 31] ^ LFSR3[sz_3 - 33] ^
            LFSR4[sz_4 - 39] ^ R1[0];

    // Imprimimos todo por pantalla

    cout << "Suma 1: " << sum_1 << endl;
    cout << "Suma 2: " << sum_2 << endl;
    cout << "Suma 2 en binario: " << Z << endl;
    cout << "R1: " << R1 << endl;
    cout << "R2: " << R2 << endl;
    cout << "T1: " << T1 << endl;
    cout << "T2: " << T2 << endl;
    cout << "XOR 1: " << xor_1 << endl;
    cout << "XOR 2: " << xor_2 << endl;
    cout << "Solucion final: " << K << endl;

    R1 = xor_2;

    cout << "Nuevo R1: " << R1 << endl;

    // Desplazamiento

    LFSR1 >>= 1;
    LFSR1[25] = pol_1;
    LFSR2 >>= 1;
    LFSR2[31] = pol_2;
    LFSR3 >>= 1;
    LFSR3[33] = pol_3;
    LFSR4 >>= 1;
    LFSR4[39] = pol_4;

    cout << endl << endl;
  }
}