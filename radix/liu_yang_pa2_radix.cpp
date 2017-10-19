#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <math.h>

using namespace std;

#define MAX_SIZE 1000
#define MAX_HEAP_NUM 200
#define MAX_RADIX_NUM 1000
static int arr[MAX_SIZE];
static int length;

void execute();
void getInput();
void generateHeapArray();
void generateRadixArray();
void heapSort();
void buildMaxHeap();
void maxHeaify(int parent_index, int bound);
void radixSort();
void countingSort(int digit);
void executeSorting();
void listArray();
void printArray();
void isSorted();

int main(int argc, char const *argv[]) {
  execute();
  return 0;
}

// continue taking arguments and execute
// main structure of this program
// and print output
void execute(){
  string input = "";
  bool sign = true;
  srand((unsigned)time(NULL));
  while (sign) {
    getInput();
    executeSorting();
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

// get the array length from user
void getInput(){
  int n = -1;
  cout << "please input a number between 1 to 1000: ";
  cin >> n;
  while (cin.fail()) {
     cin.clear();
     cin.ignore();
     cout << "please input a number between 1 to 1000: ";
     cin >> n;
  }
  while (n <= 0 || n > MAX_SIZE) {
    cout << "please input a number between 1 to 1000: ";
    cin >> n;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "please input a number between 1 to 1000: ";
      cin >> n;
    }
  }
  length = n;
  return;
}

// generate an array with given length
// FOR heapSort
// store the array as static
void generateHeapArray() {
  for (int i = 0; i < length; i++) {
    arr[i] = rand()%MAX_HEAP_NUM;
  }
  return;
}

// generate an array with given length
// FOR radixSort
// store the array as static
// 0-999
void generateRadixArray() {
  for (int i = 0; i < length; i ++) {
    arr[i] = rand()%MAX_RADIX_NUM;
  }
  return;
}

void heapSort() {
  buildMaxHeap();
  for (int i = length -1; i >= 0; i--) {
    int current_max = arr[0];
    arr[0] = arr[i];
    arr[i] = current_max;
    maxHeaify(0, i-1);
  }
  return;
}

void buildMaxHeap() {
  for (int i = length/2; i >= 0; i--) {
    maxHeaify(i, length-1);
  }
}

void maxHeaify(int parent_index, int bound) {
  int left_index = parent_index*2 + 1;
  int right_index = left_index + 1;
  int largest = parent_index;
  if (left_index <= bound && arr[left_index] > arr[parent_index]) {
    largest = left_index;
  }
  if (right_index <= bound && arr[right_index] > arr[largest]) {
    largest = right_index;
  }
  if (largest == parent_index) return;
  int temp = arr[parent_index];
  arr[parent_index] = arr[largest];
  arr[largest] = temp;
  maxHeaify(largest, bound);
  return;
}

void radixSort() {
  for (int i = 0; i < 3; i ++) {
    countingSort(i);
  }
  return;
}

void countingSort(int digit) {
  if (digit > 2 || digit < 0) {
    cout << "The range of Radix Sort is 3 digits.\n";
    return;
  }
  int denom = pow(10, digit);
  int sorted[length];
  for (int i = 0 ; i < length; i++) {
    sorted[i] = 0;
  }
  int counting[10];
  for (int i = 0; i < 10; i++) {
    counting[i] = 0;
  }
  for (int i = 0; i < length; i ++) {
    int num = (arr[i]/denom)%10;
    counting[num] ++;
  }
  for (int i = 1; i < 10; i++) {
    counting[i] += counting[i-1];
  }
  for (int i = 0; i < 10; i ++) {
    counting[i] --;
  }
  for (int i = length -1; i >= 0; i--) {
    int num = (arr[i]/denom)%10;
    sorted[counting[num]] = arr[i];
    counting[num] --;
  }
  for (int i = 0; i < length; i++) {
    arr[i] = sorted[i];
  }
}

// execute the array sorting process
// given the sort method choose by user
void executeSorting(){
  cout << "Please select the sorting method." << endl;
  cout << "1 : Heap Sort" << endl;
  cout << "2 : Radix Sort" << endl;
  int choice  = 0;
  cin >> choice;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << "Please select the sorting method." << endl;
    cout << "1 : Heap Sort" << endl;
    cout << "2 : Radix Sort" << endl;
    cout << "Please input between 1 to 2" << endl;
    cin >> choice;
  }

  if (choice < 1 || choice > 2) {
    cout << "Please select the sorting method." << endl;
    cout << "1 : Heap Sort" << endl;
    cout << "2 : Radix Sort" << endl;
    cout << "Please input between 1 to 2" << endl;
  }

  while (choice < 1 || choice > 2) {
    cin >> choice;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Please select the sorting method." << endl;
      cout << "1 : Heap Sort" << endl;
      cout << "2 : Radix Sort" << endl;
      cout << "Please input an one digit number between 1 to 2" << endl;
      cin >> choice;
    }
    if (choice < 1 || choice > 2) {
      cout << "Please select the sorting method." << endl;
      cout << "1 : Heap Sort" << endl;
      cout << "2 : Radix Sort" << endl;
      cout << "Please input between 1 to 2" << endl;
    }
  }
  cout << "Original Array:" << endl;
  switch (choice) {
    case 1:
      generateHeapArray();
      listArray();
      cout << "Starting Heap Sort" << endl;
      heapSort();
      break;
    case 2:
      generateRadixArray();
      listArray();
      cout << "Starting Radix Sort" << endl;
      radixSort();
  }
  listArray();
  isSorted();
  return;
}



// list the array
void listArray() {
  for (int i = 0; i < length; i ++) {
    cout << arr[i] <<" ";
  }
  cout << endl;
}

// print the array
void printArray(){
  if (length > 20) return;
  for (int i = 0; i < length; i ++) {
    for (int j = 0; j < arr[i]; j++) {
      cout << "*";
    }
    cout << endl;
  }
  cout << "========================"<< endl;
}

// check if the given array is sorted or not
// called after sorting
void isSorted() {
   for (int i = 0; i < length -1; i ++){
      if (arr[i] > arr[i+1]) {
         cout << "Sorting Failed!" << endl;
         return;
      }
   }
   cout << "The Array is Successfully Sorted." << endl;
}
