#include <iostream>
#include <iomanip>

using namespace std;

int getInput();
int generateRandomNum(int n);

int main(int argc, char const *argv[]) {
  getInput();
  return 0;
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
  return 6*k;
}

int generateRandomNum(int n){
  if (n%6 != 0){
    cout << "n can not be divided by 6.\n";
    return -1;
  }

  

}
