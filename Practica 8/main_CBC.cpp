#include <iostream>
#include "AES.h"

using namespace std;

// Modo de Cifrado en Bloque: CBC, haciendo uso de la practica anterior (AES)

int main()
{
    unsigned char Clave_Expand[176];                               // Expansion de la clave
    unsigned char Clave[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, // CLAVE
                               0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
                               0x0c, 0x0d, 0x0e, 0x0f};

    unsigned char Bloque_1_Texto[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, // TEXTO 1
                                        0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb,
                                        0xcc, 0xdd, 0xee, 0xff};

    unsigned char Bloque_2_Texto[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // TEXTO 2
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00};

    unsigned char IV[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // IV
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00};

    unsigned char XOR[16];

    for (int i = 0; i < 16; i++)
    {
        XOR[i] = Bloque_1_Texto[i] ^ IV[i];
    }

    unsigned char mTexto[4][4]; // Matriz 4x4 del Texto, almacenara XOR1
    unsigned char mClave[4][4]; // Matriz 4x4 de la Clave

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mClave[j][i] = Clave[i * 4 + j]; // Rellenamos la matriz de la clave
        }
    }

    AES Rijndael;

    for (int y = 1; y < 3; y++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (y == 1)
                {
                    mTexto[j][i] = Bloque_1_Texto[i * 4 + j] ^ IV[i * 4 + j];
                }
                else if (y == 2)
                {
                    mTexto[j][i] = mTexto[j][i] ^ Bloque_2_Texto[i * 4 + j];
                }
            }
        }

        Rijndael.SubClaves(mClave, Clave_Expand); // Expansion de clave
        Rijndael.Claves(mTexto, Clave_Expand);    // Cifrado del Texto

        cout << "\n Bloque " << y << " de Texto Cifrado : ";

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%02x ", mTexto[j][i]);
            }
        }
        cout << endl;
    }

}
