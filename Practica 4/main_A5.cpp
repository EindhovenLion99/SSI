#include <iostream>
#include <list>

using namespace std;

const int sz_x = 19;
const int sz_y = 22;
const int sz_z = 23;

int Mayoria(int x, int y, int z) {
  int m;
  if (x == 0) {
    if (y == 0 || z == 0) {
      m = 0;
    } else {
      m = 1;
    }
  } else {
    if (y == 1 || z == 1) {
      m = 1;
    } else {
      m = 0;
    }
  }
  return m;
}

int main() {
  // Listas

  int x[sz_x] = {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1};
  list<int> a(x, x + sizeof(x) / sizeof(int));

  int y[sz_y] = {0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1,
                 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0};
  list<int> b(y, y + sizeof(y) / sizeof(int));

  int z[sz_z] = {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1,
                 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
  list<int> c(z, z + sizeof(z) / sizeof(int));

  int aux, aux2, aux3;

  for (int i = 0; i < 6; i++) {
    cout << "*********** Ciclo " << i + 1 << ": ****************" << endl;
    cout << endl;
    cout << "\t";
    for (list<int>::iterator it = a.begin(); it != a.end(); it++) {
      cout << *it << ' ';
    }
    cout << endl;
    cout << "  ";
    for (list<int>::iterator it = b.begin(); it != b.end(); it++) {
      cout << *it << ' ';
    }
    cout << endl;

    for (list<int>::iterator it = c.begin(); it != c.end(); it++) {
      cout << *it << ' ';
    }
    cout << endl << endl;

    list<int>::iterator it_m = a.begin();
    advance(it_m, sz_x - 9);

    list<int>::iterator it2_m = b.begin();
    advance(it2_m, sz_y - 11);

    list<int>::iterator it3_m = c.begin();
    advance(it3_m, sz_z - 11);

    int X = Mayoria(*it_m, *it2_m, *it3_m);

    list<int>::iterator it = a.begin();
    advance(it, sz_x - 19);
    aux = *it;
    it = a.begin();
    advance(it, sz_x - 18);
    aux ^= *it;
    it = a.begin();
    advance(it, sz_x - 17);
    aux ^= *it;
    it = a.begin();
    advance(it, sz_x - 14);
    aux ^= *it;

    if (X == *it_m) {
      a.pop_front();
      a.push_back(aux);
    }

    it = b.begin();
    advance(it, sz_y - 22);
    aux2 = *it;
    it = b.begin();
    advance(it, sz_y - 21);
    aux2 ^= *it;

    if (X == *it2_m) {
      b.pop_front();
      b.push_back(aux2);
    }

    it = c.begin();
    advance(it, sz_z - 23);
    aux3 = *it;
    it = c.begin();
    advance(it, sz_z - 22);
    aux3 ^= *it;
    it = c.begin();
    advance(it, sz_z - 21);
    aux3 ^= *it;
    it = c.begin();
    advance(it, sz_z - 8);
    aux3 ^= *it;

    if (X == *it3_m) {
      c.pop_front();
      c.push_back(aux3);
    }

    cout << "a(t) = " << aux << endl;
    cout << "b(t) = " << aux2 << endl;
    cout << "c(t) = " << aux3 << endl;

    cout << endl;

    int key = aux ^ aux2 ^ aux3;
    cout << "a(t) ^ b(t) ^ c(t) = " << key << endl << endl;
  }
}