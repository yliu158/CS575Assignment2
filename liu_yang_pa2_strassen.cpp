#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int getInput();
vector<vector<int> > generateMatrix(int n);
vector<vector<int> > generateMatrix_one(int n);
void printMatrix(const vector<vector<int> >& m);
vector<vector<int> > multiMatrix(const vector<vector<int> >& a, const vector<vector<int> >& b);
void checkMatrixSame(const vector<vector<int> >& a, const vector<vector<int> >& b);
vector<vector<int> > addMatrix(const vector<vector<int> >& a, const vector<vector<int> >& b);
vector<vector<int> > minusMatrix(const vector<vector<int> >& a, const vector<vector<int> >& b);
vector<vector<int> > divideMatrix(const vector<vector<int> >& a, int r_ind, int c_ind, int size);
vector<vector<int> > strassenMulti(const vector<vector<int> >& a, const vector<vector<int> >& b);

int main(int argc, char const *argv[]) {
  int n = getInput();
  return 0;
}

int getInput() {
  cout << "Please input the size of the matrix: ";
  int n = 0;
  cin >> n;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << "Please input the size of the matrix: ";
    cin >> n;
  }
  while (n <= 0 || n > 10) {
    cout << "Please input the size of the matrix between 1 and 10: ";
    cin >> n;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Please input the size of the matrix: ";
      cin >> n;
    }
  }
  return pow(2, n);
}

vector<vector<int> > generateMatrix(int n) {
  int max_num = (int)pow((INT_MAX/n),0.5);
  vector<vector<int> > matrix;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < n; j++) {
      row.push_back(rand()%max_num);
    }
    matrix.push_back(row);
  }
  return matrix;
}

vector<vector<int> > generateMatrix_one(int n) {
  vector<vector<int> > m;
  for (int i = 0; i < n; i ++) {
    vector<int> r;
    for (int j = 0; j < n; j++) {
      if (i == j) r.push_back(1);
      else r.push_back(0);
    }
    m.push_back(r);
  }
  return m;
}

void printMatrix(const vector<vector<int> >& m) {
  if (m.size() == 0) return;
  cout << endl;
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m.at(0).size(); j++) {
      cout << left << setw(7) << setfill(' ') <<m.at(i).at(j);
    }
    cout << endl;
  }
}

vector<vector<int> > multiMatrix(const vector<vector<int> >& a, const vector<vector<int> >& b) {
  vector<vector<int> > m;
  if (a.at(0).size() != b.size()) return m;
  vector<int> r;
  for (int i = 0; i < a.size(); i++) {
    r.clear();
    for (int j = 0; j < a.at(0).size(); j ++) {
      int cur = 0;
      for (int k = 0; k < b.size(); k ++) {
        cur += a.at(i).at(k) * b.at(k).at(j);
      }
      r.push_back(cur);
    }
    m.push_back(r);
  }
  return m;
}

void checkMatrixSame(const vector<vector<int> >& a, const vector<vector<int> >& b){
  if (a.size() != b.size()) {
    cout << "The two matrixs are not identical.\n";
    return;
  }
  if (a.size() == 0 ) {
    cout << "The two matrixs are empty.\n";
    return;
  }

  for (int i = 0; i < a.size(); i ++) {
    if (a.at(i).size() != b.at(i).size()) {
      cout <<"The two matrixs are not identical.\n";
      return;
    }
    for (int j = 0; j < a.at(i).size(); j++) {
      if (a.at(i).at(j) != b.at(i).at(j)){
        cout << "The two matrixs are not identical.\n";
        return;
      }
    }
  }
  cout << "The two matrixs are identical.\n";
  return;
}

vector<vector<int> > addMatrix(const vector<vector<int> >& a, const vector<vector<int> >& b) {
  vector<vector<int> > m;
  if (a.size() != b.size()) {
    cout << "The two matrixs are not addable.\n";
    return m;
  }
  vector<int> r;
  for (int i = 0; i < a.size(); i++) {
    r.clear();
    if (a.at(i).size() != b.at(i).size()) {
      cout << "The two matrixs are not addable.\n";
      return m;
    }
    for (int j = 0; j < a.at(i).size(); j++) {
      r.push_back(a.at(i).at(j) + b.at(i).at(j));
    }
    m.push_back(r);
  }
  return m;
}

vector<vector<int> > minusMatrix(const vector<vector<int> >& a, const vector<vector<int> >& b) {
  vector<vector<int> > m;
  if (a.size() != b.size()) {
    cout << "The two matrixs are not minusable.\n";
    return m;
  }
  vector<int> r;
  for (int i = 0; i < a.size(); i++) {
    r.clear();
    if (a.at(i).size() != b.at(i).size()) {
      cout << "The two matrixs are not minusable.\n";
      return m;
    }
    for (int j = 0; j < a.at(i).size(); j++) {
      r.push_back(a.at(i).at(j) - b.at(i).at(j));
    }
    m.push_back(r);
  }
  return m;
}

vector<vector<int> > divideMatrix(const vector<vector<int> >& a, int r_ind, int c_ind, int size) {
  vector<vector<int> > emptymatrix;
  if (a.size() < r_ind + size) {
    cout << "Out of range of the matrix(row).\n";
    return emptymatrix;
  }
  vector<vector<int> > m;
  vector<int> r;
  for (int i = r_ind; i < r_ind+size; i++) {
    r.clear();
    if (a.at(i).size() < c_ind + size){
      cout << "Out of range of the matrix(col).\n";
      return emptymatrix;
    }
    for (int j = c_ind; j < c_ind + size;j ++) {
      r.push_back(a.at(i).at(j));
    }
    m.push_back(r);
  }
  return m;
}

vector<vector<int> > strassenMulti(const vector<vector<int> >& a, const vector<vector<int> >& b){
  vector<vector<int> > m;
  return m;
}
