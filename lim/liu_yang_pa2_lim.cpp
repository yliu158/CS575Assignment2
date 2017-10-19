#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
struct LargeInt{
  vector<int> ints;
};

void execute();
int getInput();
void generateRandomNums(const int& k, struct LargeInt& a, struct LargeInt& b);

int main(int argc, char const *argv[]) {
  execute();
  return 0;
}

void execute(){
  int n = getInput();
  struct LargeInt a;
  struct LargeInt b;
  generateRandomNums(n, a, b);
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

void generateRandomNums(const int& k, struct LargeInt& a, struct LargeInt& b){
  srand(time(NULL));
  int threshold = pow(INT_MAX, 0.5);

  int x;
  for (int i = 0; i < k-1; i++) {
    x = 0;
    for (int j = 0; j < 6; j++) {
      x += pow(10, i) * (rand()%10);
    }
  }

  x = 0;
  for (int i = 0; i < n -1; i++) {
    x += pow(10, k*6-1) * (rand()%9 + 1);
  }
  return;
}
