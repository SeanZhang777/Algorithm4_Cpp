/*
 * @Author: Sean Zhang 
 * @Date: 2021-03-31 21:25:04 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-01 00:05:16
 */
#include "union_find.h"

UnionFind::UnionFind(int N) {
  count_ = N;
  id_ = new int[N];
  sz_ = new int[N];
  for (int i = 0; i < N; ++i) {
    id_[i] = i;
    sz_[i] = 1;
  }
}

UnionFind::~UnionFind() {
  if (id_)
    delete [] id_;
  if (sz_)
    delete [] sz_;
}

int UnionFind::Find(int p) {
  while (p != id_[p])
    p = id_[p];
  return p;
}

void UnionFind::Union(int p, int q) {
  int i = Find(p);
  int j = Find(q);
  if (i == j) return;
  if (sz_[i] < sz_[j]) {
    id_[i] = j;
    sz_[j] += sz_[i];
  } else {
    id_[j] = i;
    sz_[i] += sz_[j];
  }
  count_--;
}
