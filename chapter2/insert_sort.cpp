/*
 * @Author: Sean Zhang 
 * @Date: 2021-04-01 23:30:21 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-01 23:33:09
 */
#include <iostream>
#include <cstring>

template<typename T>
void Swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

template<typename T>
void Print(T a[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

template<typename T>
bool IsSorted(T a[], int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1])
      return false;
  }
  return true;
}

template<typename T>
void InsertSort(T a[], int n) {
  for (int i = 1; i < n; ++i) {
    for (int j = i; j > 0; --j) {
      if (a[j] < a[j - 1])
        Swap(a[j], a[j - 1]);
    }
  }
}

int main(int argc, char **argv) {
  char a[] = "SORTEXAMPLE";
  int n = strlen(a);
  InsertSort(a, n);
  Print(a, n);
}