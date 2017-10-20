#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

#define THRESHOLD 4

void execute();
int getInput();
vector<int> generateRandomNum(int k);
void seperateLargeInts(int power,
  vector<vector<int> >& s,
  const vector<int>& l);
void largeIntMulti_two();
void largeIntMulti_three();
void printLargeInt(const vector<int>& l);
void printGroupInt(const vector<vector<int> >& s1);
int convertToInt(const vector<int>& l);
vector<int> convertToVector(int value);
vector<int> largeIntMulti_two(const vector<int>& a, const vector<int>& b);
vector<int> largeIntMulti_three(const vector<int>& a, const vector<int>& b);

int main(int argc, char const *argv[]) {
  execute();
  return 0;
}

void execute() {

  string input = "";
  bool sign = true;
  srand((unsigned)time(NULL));
  while (sign) {

    int k = getInput();
    vector<int> l1 = generateRandomNum(k);
    vector<int> l2 = generateRandomNum(k);

    printLargeInt(l1);
    printLargeInt(l2);
    vector<int> l3 = largeIntMulti_two(l1, l2);
    cout << "Result largeIntMulti_two: \n";
    printLargeInt(l3);
    vector<int> l4 = largeIntMulti_three(l1, l2);
    cout << "Result largeIntMulti_three: \n";
    printLargeInt(l4);

    cout << "Press e to Exit." << endl;
    cout << "Press any other button to continue." << endl;
    cin >> input;
    if (input[0] == 'e' || input[0] == 'E') {
      sign = false;
    }

    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cin >> input;
      if (input[0] == 'e' || input[0] == 'E') {
         sign = false;
      }
    }
  }
  cout << "Successfully Exited" << endl;
}


int getInput() {
  cout << "Num of digits will be 6*k.\n";
  cout << "Please input a value for k: ";
  int k = 0;
  cin >> k;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << "Num of digits will be 6*k.\n";
    cout << "Please input a value for k: ";
    cin >> k;
  }

  while (k <= 0) {
    cout << "Num of digits will be 6*k.\n";
    cout << "Please input a positive value for k: ";
    cin >> k;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Num of digits will be 6*k.\n";
      cout << "Please input a positive value for k: ";
      cin >> k;
    }
  }
  return k;
}

vector<int> generateRandomNum(int k){
  vector<int> l;
  if (k <= 0) {
    cout << "invalid k value to generateRandomNum.\n";
    return l;
  }
  // k>= 1
  l.push_back(rand()%9+1);
  for (int j = 0; j < 5; j++) {
    l.push_back(rand()%10);
  }
  for (int i = 0; i < k-1; i++){
    for (int j = 0; j < 6; j++) {
      l.push_back(rand()%10);
    }
  }
  return l;
}

void seperateLargeInts(int power,
  vector<vector<int> >& s,
  const vector<int >& l){

  if (l.size() == 0) return;
  if (power <= 0) return;
  vector<int> num;
  num.clear();
  int count = 0;
  for (int i = l.size()-1; i >= 0; i --) {
    num.insert(num.begin(), l.at(i));
    count ++;
    if (count == power) {
      s.insert(s.begin(), num);
      num.clear();
      count = 0;
    }
  }
  if (!num.empty()) {
    s.insert(s.begin(), num);
  }
  return;
}

int convertToInt(const vector<int>& l) {
  int value = 0;
  if (l.size() == 0) return 0;
  if (l.size() <= THRESHOLD) {
    for (int i = l.size()-1; i >= 0; i--) {
      value += l.at(i) * pow(10,  l.size()-1 - i);
    }
  } else {
    value = -1;
  }
  return value;
}

vector<int> convertToVector(int value) {
  vector<int> l;
  if (value < 0) {
    cout << "Error: try to convert negative value.\n";
    return l;
  }
  if (value == 0) {
    l.push_back(0);
    return l;
  }
  while (value >= 10) {
    int rem = value%10;
    value = value/10;
    l.insert(l.begin(), rem);
  }
  if (value >= 1) {
    l.insert(l.begin(), value);
  }
  return l;
}

vector<int> largeIntMulti_two(const vector<int>& a, const vector<int>& b){
  vector<int> l;
  if (a.size() == 0 || b.size() == 0) {
    l.push_back(0);
    return l;
  }

  if (a.size() <= THRESHOLD && b.size() <= THRESHOLD) {
    int a_value = convertToInt(a);
    int b_value = convertToInt(b);
    // cout << "a: " << a_value << "   b: " << b_value << endl;
    int r = a_value * b_value;
    cout << a_value << " * " << b_value << endl;
    l = convertToVector(r);
    // printLargeInt(l);
    return l;
  }

  // l needs seperation
  int power = max(a.size(), b.size());
  if (power%2 == 1) {
    power = power/2 +1;
  } else {
    power = power/2;
  }
  vector<vector<int> > sa;
  vector<vector<int> > sb;
  seperateLargeInts(power, sa, a);
  seperateLargeInts(power, sb, b);

  printGroupInt(sa);
  printGroupInt(sb);

  vector<int> a1;
  vector<int> a2;
  a1.clear();
  a2.clear();
  if (sa.size() == 1) {
    a1.push_back(0);
    for (int i = 0; i < sa.at(0).size(); i++) {
      a2.push_back(sa.at(0).at(i));
    }
  } else if (sa.size() == 2) {
    for (int i = 0; i < sa.at(0).size(); i++) {
      a1.push_back(sa.at(0).at(i));
    }
    for (int i = 0; i < sa.at(1).size(); i++) {
      a2.push_back(sa.at(1).at(i));
    }
  } else {
    a1.push_back(0);
    a2.push_back(0);
  }
  // printLargeInt(a1);
  // printLargeInt(a2);
  vector<int> b1;
  vector<int> b2;
  b1.clear();
  b2.clear();
  if (sb.size()  == 1) {
    b1.push_back(0);
    for (int i = 0; i < sb.at(0).size(); i++) {
      b2.push_back(sb.at(0).at(i));
    }
  } else if (sb.size() == 2) {
    for (int i = 0; i < sb.at(0).size(); i++) {
      b1.push_back(sb.at(0).at(i));
    }
    for (int i = 0; i < sb.at(1).size(); i++) {
      b2.push_back(sb.at(1).at(i));
    }
  } else {
    b1.push_back(0);
    b2.push_back(0);
  }

  // printLargeInt(b1);
  // printLargeInt(b2);

  vector<int> x = largeIntMulti_two(a1, b1);
  vector<int> y = largeIntMulti_two(a1, b2);
  vector<int> z = largeIntMulti_two(a2, b1);
  vector<int> w = largeIntMulti_two(a2, b2);

  int len =  max(
    max(x.size()+power*2, y.size()+power),
    max(z.size()+power, w.size())
  );

  int rem = 0;
  int carry = 0;
  int rev_index = 0;

  while (rev_index < len) {
    rem = 0;
    int w_index = w.size() -1 - rev_index;
    if ( w_index >= 0) {
      rem += w.at(w.size() -1 - rev_index);
    }
    int x_index = x.size() -1 - rev_index + power*2;
    if (x_index < x.size() && x_index >= 0) {
      rem += x.at(x_index);
    }
    int y_index = y.size() -1 - rev_index + power;
    if (y_index < y.size() && y_index >= 0){
      rem += y.at(y_index);
    }
    int z_index = z.size() -1 - rev_index + power;
    if (z_index >= 0 && z_index < z.size()) {
      rem += z.at(z_index);
    }
    rem += carry;
    carry = rem/10;
    l.insert(l.begin(), rem%10);
    rev_index ++;
  }
  return l;
}

vector<int> largeIntMulti_three(const vector<int>& a, const vector<int>& b){


    vector<int> l;
    if (a.size() == 0 || b.size() == 0) {
      l.push_back(0);
      return l;
    }

    if (a.size() <= THRESHOLD && b.size() <= THRESHOLD) {
      int a_value = convertToInt(a);
      int b_value = convertToInt(b);
      int r = a_value * b_value;
      l = convertToVector(r);
      return l;
    }

    // l needs seperation
    int power = max(a.size(), b.size());

    if (power%3 == 0) {
      power = power/3;
    } else {
      power = power/3+1;
    }
    vector<vector<int> > sa;
    vector<vector<int> > sb;
    seperateLargeInts(power, sa, a);
    seperateLargeInts(power, sb, b);


    vector<int> a1;
    vector<int> a2;
    vector<int> a3;
    if (sa.size() == 0) {
      a1.push_back(0);
      a2.push_back(0);
      a3.push_back(0);
    } else if (sa.size() == 1) {
      a1.push_back(0);
      a2.push_back(0);
      a3 = sa.at(0);
    } else if (sa.size() == 2) {
      a1.push_back(0);
      a2 = sa.at(0);
      a3 = sa.at(1);
    } else {
      a1 = sa.at(0);
      a2 = sa.at(1);
      a3 = sa.at(2);
    }

    vector<int> b1;
    vector<int> b2;
    vector<int> b3;
    if (sb.size() == 0) {
      b1.push_back(0);
      b2.push_back(0);
      b3.push_back(0);
    } else if (sb.size() == 1) {
      b1.push_back(0);
      b2.push_back(0);
      b3 = sb.at(0);
    } else if (sb.size() == 2) {
      b1.push_back(0);
      b2 = sb.at(0);
      b3 = sb.at(1);
    } else {
      b1 = sb.at(0);
      b2 = sb.at(1);
      b3 = sb.at(2);
    }

    vector<int> v1 = largeIntMulti_three(a1, b1); // 4k
    vector<int> v2 = largeIntMulti_three(a1, b2); // 3k
    vector<int> v3 = largeIntMulti_three(a1, b3); // 2k
    vector<int> v4 = largeIntMulti_three(a2, b1); // 3k
    vector<int> v5 = largeIntMulti_three(a2, b2); // 2k
    vector<int> v6 = largeIntMulti_three(a2, b3); // 1k
    vector<int> v7 = largeIntMulti_three(a3, b1); // 2k
    vector<int> v8 = largeIntMulti_three(a3, b2); // 1k
    vector<int> v9 = largeIntMulti_three(a3, b3); // 0k
    // cout << "largeIntMulti_three after get\n";
    // printLargeInt(v1);
    // printLargeInt(v2);
    // printLargeInt(v3);
    // printLargeInt(v4);
    // printLargeInt(v5);
    // printLargeInt(v6);
    // printLargeInt(v7);
    // printLargeInt(v8);
    // printLargeInt(v9);

    for (int i = 0; i < power; i++) {
      for (int j = 0; j < 4; j++) {
        v1.push_back(0);
      }
      for (int j = 0; j < 3; j ++) {
        v2.push_back(0);
        v4.push_back(0);
      }
      for (int j = 0; j < 2; j ++) {
        v3.push_back(0);
        v5.push_back(0);
        v7.push_back(0);
      }
      v6.push_back(0);
      v8.push_back(0);
    }

    // cout << "largeIntMulti_three after push_back\n";
    // printLargeInt(v1);
    // printLargeInt(v2);
    // printLargeInt(v3);
    // printLargeInt(v4);
    // printLargeInt(v5);
    // printLargeInt(v6);
    // printLargeInt(v7);
    // printLargeInt(v8);
    // printLargeInt(v9);

    int len = 0;
    if (len < v1.size()){ len = v1.size();}
    if (len < v2.size()){ len = v2.size();}
    if (len < v3.size()){ len = v3.size();}
    if (len < v4.size()){ len = v4.size();}
    if (len < v5.size()){ len = v5.size();}
    if (len < v6.size()){ len = v6.size();}
    if (len < v7.size()){ len = v7.size();}
    if (len < v8.size()){ len = v8.size();}
    if (len < v9.size()){ len = v9.size();}


    int rem = 0;
    int carry = 0;

    while (v1.size() < len) {
      v1.insert(v1.begin(), 0);
    }
    while (v2.size() < len) {
      v2.insert(v2.begin(), 0);
    }
    while (v3.size() < len) {
      v3.insert(v3.begin(), 0);
    }
    while (v4.size() < len) {
      v4.insert(v4.begin(), 0);
    }
    while (v5.size() < len) {
      v5.insert(v5.begin(), 0);
    }
    while (v6.size() < len) {
      v6.insert(v6.begin(), 0);
    }
    while (v7.size() < len) {
      v7.insert(v7.begin(), 0);
    }
    while (v8.size() < len) {
      v8.insert(v8.begin(), 0);
    }
    while (v9.size() < len) {
      v9.insert(v9.begin(), 0);
    }

    // cout << "largeIntMulti_three after insert\n";
    // printLargeInt(v1);
    // printLargeInt(v2);
    // printLargeInt(v3);
    // printLargeInt(v4);
    // printLargeInt(v5);
    // printLargeInt(v6);
    // printLargeInt(v7);
    // printLargeInt(v8);
    // printLargeInt(v9);

    for (int i = len -1; i >= 0; i--) {
      rem = v1.at(i) + v2.at(i) +
      v3.at(i) + v4.at(i) + v5.at(i) + v6.at(i) +
      v7.at(i) + v8.at(i) + v9.at(i) + carry;
      carry = rem/10;
      l.insert(l.begin(), rem%10);
    }
    // printLargeInt(l);
    return l;
}

void printLargeInt(const vector<int>& l){
  cout << "LargeInt:\n";
  for (int i = 0; i < l.size(); i++) {
    cout << l.at(i);
  }
  cout << endl;
  return;
}

void printGroupInt(const vector<vector<int> >& s) {
  cout << "GroupInt:\n";
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.at(i).size(); j++) {
      cout << s.at(i).at(j);
    }
    cout << endl;
  }
  cout << endl;
}
