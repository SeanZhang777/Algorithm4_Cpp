/*
 * @Author: Sean Zhang 
 * @Date: 2021-04-01 23:30:21 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-02 00:26:21
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
void ShellSort(T a[], int n) {
  int h = 1;
  while (h < n / 3)
    h = h * 3 + 1;  // knuth序列希尔排序
  while (h >= 1) {
    for (int i = h; i < n; ++i) {
      for (int j = i; j > h - 1; j -= h) {
        if (a[j] < a[j - h])
          Swap(a[j], a[j - h]);
      }
    }
    h /= 3;
  }
}

int main(int argc, char **argv) {
  char a[] = "SHELLSORTEXAMPLE";
  int n = strlen(a);
  ShellSort(a, n);
  Print(a, n);
}