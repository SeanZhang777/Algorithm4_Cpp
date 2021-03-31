/*
 * @Author: Sean Zhang 
 * @Date: 2021-03-31 21:24:36 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-03-31 21:24:59
 */
#include <iostream>

int binary_search(int *a, int n, int key) {
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (key < a[mid])
      hi = mid - 1;
    else if (key > a[mid])
      lo = mid + 1;
    else
      return mid;
  }
  return -1;
}

int main(int argc, char **argv) {
  int a[] = {1, 3, 4, 6, 7, 8, 9, 23, 35};
  int n = 9;
  int key = 3;
  int pos = binary_search(a, n, key);
  printf("pos=%d\n", pos);

  key = 5;
  pos = binary_search(a, n, key);
  printf("pos=%d\n", pos);
  return 0;
}
