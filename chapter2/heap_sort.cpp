/*
 * @Author: Sean Zhang 
 * @Date: 2021-04-04 01:20:34 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-04 01:42:31
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
void Sink(T a[], int k, int n) {
  while (2 * k <= n) { // if k has children
    int j = 2 * k;
    if (j < n && a[j-1] < a[j])  // select bigger child
      j++;
    if (!(a[k-1] < a[j-1]))
      break;
    Swap(a[k-1], a[j-1]);
    k = j;
  }
}

template<typename T>
void HeapSort(T a[], int n) {
  for (int k = n / 2; k >= 1; --k) {
    Sink(a, k, n);
  }
  while (n > 1) {
    Swap(a[0], a[--n]);
    Sink(a, 1, n);
  }
}

int main(int argc, char **argv) {
  char a[] = "HEAPSORTEXAMPLE";
  int n = strlen(a);
  HeapSort(a, n);
  Print(a, n);
}