#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <limits.h>

using namespace std;

#define THRESHOLD 4
struct LargeInt{
  vector<int> ints;
};

void execute();
int getInput();
void generateRandomNums(const int& k, struct LargeInt& a);
void printLargeInt(const struct LargeInt& a);
void largeIntMulti_three(const struct LargeInt& a,
                   const struct LargeInt& b,
                   struct LargeInt& r);

int main(int argc, char const *argv[]) {
  execute();
  return 0;
}

void execute(){
  srand(time(NULL));
  int k_a = getInput();
  int k_b = getInput();
  struct LargeInt a;
  struct LargeInt b;
  generateRandomNums(k_a, a);
  generateRandomNums(k_b, b);
  printLargeInt(a);
  printLargeInt(b);
  struct LargeInt r;
  largeIntMulti_three(a, b, r);

}

int getInput() {
  cout << "Please input a value for k: ";
  int k = 0;
  cin >> k;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << "Please input a value for k: ";
    cin >> k;
  }

  while (k <= 0) {
    cout << "Please input a positive value for k: ";
    cin >> k;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Please input a positive value for k: ";
      cin >> k;
    }
  }
  return k;
}

void generateRandomNums(const int& k, struct LargeInt& a){
  int x = 0;
  for (int i = 0; i < 5; i++) {
    x += pow(10, i) * (rand()%10);
  }
  x += pow(10, 5) * (rand()%9 + 1);
  a.ints.push_back(x);

  x = 0;
  for (int i = 0; i < k-1; i++) {
    x = 0;
    for (int j = 0; j < 6; j++) {
      x += pow(10, j) * (rand()%10);
    }
    a.ints.push_back(x);
  }
  return;
}

void printLargeInt(const struct LargeInt& a){
  cout << "LargeInt: ";
  for (int i = 0; i < a.ints.size(); i++) {
    cout << right << setw(7) << setfill(' ') << a.ints.at(i);
  }
  cout << endl;
}

void largeIntMulti_three(const struct LargeInt& a,
                   const struct LargeInt& b,
                   struct LargeInt& r) {
  int n, m;
  int a_length = 0;
  int b_length = 0;

  int cur = a.ints.at(0);
  for (int j = 6; j >= 0; j--) {
    if (cur/pow(10,j) != 0) {
      a_length = j;
      break;
    }
  }
  a_length += 6*(a.ints.size()-1);

  cur = b.ints.at(0);
  for (int j = 6; j >= 0; j--) {
    if (cur/pow(10,j) != 0) {
      b_length = j;
      break;
    }
  }
  b_length += 6*(b.ints.size()-1);

  if (a_length == 0 || b_length == 0) {
    r.ints.push_back(0);
    return;
  }

  n = max(a_length, b_length);
  if (n <= THRESHOLD) {
    int prod = a.ints.at(0) * b.ints.at(0);
    int rem = prod % 1000000;
    prod = prod/1000000;
    if (prod > 0) r.ints.push_back(prod);
    r.ints.push_back(rem);
    printLargeInt(r);
    return;
  }

  struct LargeInt x, y, z, o, p, q;
  m = n/3;

  // cout << "a: " << a_length << endl;
  // cout << "b: " << b_length << endl;
  // cout << "n: " ;
  // printLargeInt(r);


}

void seperateLargeInts(const struct LargeInt& a, vector<struct LargeInt>& r, int power) {
  int a_length = 0;
  int cur = a.ints.at(0);
  for (int j = 6; j >= 0; j--) {
    if (cur/pow(10,j) != 0) {
      a_length = j;
      break;
    }
  }
  a_length += 6*(a.ints.size()-1);

  if (power > a_length) {
    r.push_back(a);
    return;
  }
  int count = 0;
  int a_index = a.ints.size()-1;
  vector<int>::iterator it;
  int prod = 0;
  int rem = 0;
  for (int i = 0; i < a_length/power; i++) {
    if (a_index < 0) break;
    struct LargeInt num;
    while (count < power) {
      if (num.ints.size() == 0 ) {
        if (prod != 0) {
          
        }
        while (count < power -6) {
          it = num.ints.begin();
          num.ints.insert(it, a.ints.at(a_index--));
          count += 6;
        }
        if (count == power) break;
        if (a_index >= 0) {
          prod = num.ints.at(a_index--);
          int denom = pow(10, power -count);
          rem = prod%denom;
          prod = prod/denom;
        } else {
          count = power;
        }

      } else if (num.ints.front() == 0) {

        if (count < power - 6) {
          num.ints.front() = a.ints.at(a_index--);
        }
        while (count < power -6) {
          it = num.ints.begin();
          num.ints.insert(it, a.ints.at(a_index--));
          count += 6;
        }

      } else if (num.ints.front() < 100000) {

        int need = 0;
        for (int i = 4; i >= 0; i--) {
          int denom = pow(10, i);
          if ((num.ints.front()/denom ) != 0){
            need = 6 - i -1;
            break;
          }
        }

      } else {
        // insert new int
        while (count < power -6) {
          it = num.ints.begin();
          num.ints.insert(it, a.ints.at(a_index--));
          count += 6;
        }

      }
    }
  }






















}
