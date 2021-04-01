/*
 * @Author: Sean Zhang 
 * @Date: 2021-04-01 23:01:36 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-01 23:18:20
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
void SelectSort(T a[], int n) {
  for (int i = 0; i < n; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[min_idx])
        min_idx = j;
    }
    Swap(a[i], a[min_idx]);
  }
}

int main(int argc, char **argv) {
  char a[] = "SORTEXAMPLE";
  int n = strlen(a);
  SelectSort(a, n);
  Print(a, n);
}