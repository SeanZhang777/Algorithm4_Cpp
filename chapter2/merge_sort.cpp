/*
 * @Author: Sean Zhang 
 * @Date: 2021-04-03 14:36:07 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-03 14:39:58
 */
#include <iostream>
#include <cstring>

char aux[256];

void Print(char a[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

bool IsSorted(char a[], int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1])
      return false;
  }
  return true;
}

void Merge(char a[], int lo, int mid, int hi) {
  int i = lo;
  int j = mid + 1;
  for (int k = lo; k <= hi; ++k) {
    aux[k] = a[k];
  }

  for (int k = lo; k <= hi; ++k) {
    if (i > mid)
      a[k] = aux[j++];
    else if (j > hi)
      a[k] = aux[i++];
    else if (aux[i] < aux[j])
      a[k] = aux[i++];
    else 
      a[k] = aux[j++];
  }
}

void MergeSort(char a[], int lo, int hi) {
  if (hi <= lo)
    return;
  int mid = lo + (hi - lo) / 2;
  MergeSort(a, lo, mid);
  MergeSort(a, mid+1, hi);
  if (a[mid] < a[mid+1])
    return;
  Merge(a, lo, mid, hi);
}

void MergeSort(char a[], int n) {
  MergeSort(a, 0, n-1);
}

int main(int argc, char **argv) {
  char a[] = "EEGMRACERT";
  int n = strlen(a);
  Print(a, n);
  MergeSort(a, n);
  Print(a, n);

  return 0;
}