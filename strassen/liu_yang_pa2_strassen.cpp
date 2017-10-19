#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits.h>


using namespace std;

void execute();
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
  execute();
  return 0;
}

void execute() {
  srand(time(NULL));
  int n = getInput();
  vector<vector<int> > v1 = generateMatrix(n);
  printMatrix(v1);
  vector<vector<int> > v2 = generateMatrix(n);
  printMatrix(v2);
  vector<vector<int> > v3 = strassenMulti(v1,v2);
  printMatrix(v3);
  vector<vector<int> > v4 = multiMatrix(v1,v2);
  printMatrix(v4);
  checkMatrixSame(v4, v3);
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
      cout << left << setw(20) << setfill(' ') <<m.at(i).at(j);
    }
    cout << endl;
  }
}

vector<vector<int> > multiMatrix(const vector<vector<int> >& a, const vector<vector<int> >& b) {
  vector<vector<int> > m;
  vector<int> r;
  vector<vector<int> > emptymatrix;
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i).size() != b.size()) {
      cout << "The two matrixs can not be multipled.\n";
      return emptymatrix;
    }
    r.clear();
    for (int j = 0; j < a.at(i).size(); j ++) {
      int cur = 0;
      for (int k = 0; k < b.size(); k ++) {
        if (b.at(k).size() < j) {
          cout << "The two matrixs can not be multipled.\n";
          return emptymatrix;
        }
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
  vector<vector<int> > emptymatrix;
  vector<int> r;
  for (int i = 0; i < a.size(); i++) {
    r.clear();
    if (a.at(i).size() != b.at(i).size()) {
      cout << "The two matrixs are not addable.\n";
      return emptymatrix;
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
  vector<vector<int> > emptymatrix;
  vector<int> r;
  for (int i = 0; i < a.size(); i++) {
    r.clear();
    if (a.at(i).size() != b.at(i).size()) {
      cout << "The two matrixs are not minusable.\n";
      return emptymatrix;
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
  if ( a.size() != b.size()
    || a.size() == 0
    || a.at(0).size() != a.size()
    || b.at(0).size() != b.size()
  ) {
    cout << "The two matrix can not be multipled.\n";
    cout << "emptymatrix returned.\n";
    return m;
  }

  if (a.size() == 2) {
    return multiMatrix(a, b);
  }
  int size = a.size();

  vector<vector<int> > a11 = divideMatrix(a, 0,0, size/2);
  vector<vector<int> > a12 = divideMatrix(a, 0,size/2, size/2);
  vector<vector<int> > a21 = divideMatrix(a, size/2,0, size/2);
  vector<vector<int> > a22 = divideMatrix(a, size/2,size/2, size/2);

  vector<vector<int> > b11 = divideMatrix(b, 0,0, size/2);
  vector<vector<int> > b12 = divideMatrix(b, 0,size/2, size/2);
  vector<vector<int> > b21 = divideMatrix(b, size/2,0, size/2);
  vector<vector<int> > b22 = divideMatrix(b, size/2,size/2, size/2);

  vector<vector<int> > m1 = strassenMulti(addMatrix(a11, a22), addMatrix(b11, b22));
  vector<vector<int> > m2 = strassenMulti(addMatrix(a21, a22), b11);
  vector<vector<int> > m3 = strassenMulti(a11, minusMatrix(b12, b22));
  vector<vector<int> > m4 = strassenMulti(a22, minusMatrix(b21, b11));
  vector<vector<int> > m5 = strassenMulti(addMatrix(a11, a12), b22);
  vector<vector<int> > m6 = strassenMulti(minusMatrix(a21, a11), addMatrix(b11, b12));
  vector<vector<int> > m7 = strassenMulti(minusMatrix(a12, a22), addMatrix(b21, b22));

  vector<vector<int> > c11 = addMatrix(m1, m4);
  c11 = minusMatrix(c11, m5);
  c11 = addMatrix(c11, m7);
  vector<vector<int> > c12 = addMatrix(m3, m5);
  vector<vector<int> > c21 = addMatrix(m2, m4);
  vector<vector<int> > c22 = minusMatrix(m1, m2);
  c22 = addMatrix(c22, m3);
  c22 = addMatrix(c22, m6);

  vector<vector<int> > c;
  vector<int> r;
  for (int i = 0; i < c11.size(); i++) {
    r.clear();
    for (int j = 0; j < c11.at(i).size(); j ++) {
      r.push_back(c11.at(i).at(j));
    }
    c.push_back(r);
  }

  for (int i = 0; i < c12.size(); i++) {
    for (int j = 0; j < c12.at(i).size(); j++) {
      c.at(i).push_back(c12.at(i).at(j));
    }
  }

  for (int i = 0; i < c21.size(); i++) {
    r.clear();
    for (int j = 0; j < c21.at(i).size(); j++) {
      r.push_back(c21.at(i).at(j));
    }
    c.push_back(r);
  }

  for (int i = 0; i < c22.size(); i++) {
    for (int j = 0; j < c22.at(i).size(); j++) {
      c.at(i + c11.size()).push_back(c22.at(i).at(j));
    }
  }
  return c;
}
