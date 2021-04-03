/*
 * @Author: Sean Zhang 
 * @Date: 2021-04-03 20:50:36 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-03 21:08:38
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
int Partition(T a[], int lo, int hi) {
  T p = a[lo];
  int i = lo, j = hi + 1;
  while (true) {
    while (a[++i] < p)
      if (i == hi)
        break;
    while (a[--j] > p)
      if (j == lo)
        break;
    if (i >= j)
      break;
    Swap(a[i], a[j]);
  }
  Swap(a[lo], a[j]);
  return j;
}

template<typename T>
void QuickSort(T a[], int lo, int hi) {
  if (hi <= lo) return;
  int j = Partition(a, lo, hi);
  QuickSort(a, lo, j-1);
  QuickSort(a, j+1, hi);
}

template<typename T>
void QuickSort(T a[], int n) {
  int lo = 0, hi = n - 1;
  QuickSort(a, lo, hi);
}

template<typename T>
void QuickSort3Way(T a[], int lo, int hi) {
  if (hi <= lo) return;
  int lt = lo, i = lo+1, gt = hi;
  T p = a[lo];
  while (i <= gt) {
    if (a[i] < p)
      Swap(a[lt++], a[i++]);
    else if (a[i] > p)
      Swap(a[i], a[gt--]);
    else 
      i++;
  }
  QuickSort3Way(a, lo, lt-1);
  QuickSort3Way(a, gt+1, hi);
}

template<typename T>
void QuickSort3Way(T a[], int n) {
  int lo = 0, hi = n - 1;
  QuickSort3Way(a, lo, hi);
}

int main(int argc, char **argv) {
  char a[] = "QUICKSORTEXAMPLE";
  int n = strlen(a);
  QuickSort(a, n);
  Print(a, n);

  char b[] = "QUICKSORTTHREEWAYEXAMPLE";
  n = strlen(b);
  QuickSort3Way(b, n);
  Print(b, n);
}