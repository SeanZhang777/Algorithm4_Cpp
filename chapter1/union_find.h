/*
 * @Author: Sean Zhang 
 * @Date: 2021-03-31 23:41:44 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-01 00:01:50
 */
#ifndef CHAPTER1_UNION_FIND_H_
#define CHAPTER1_UNION_FIND_H_

class UnionFind {
 public:
  explicit UnionFind(int N);
  ~UnionFind();

  inline int Count() {
    return count_;
  }
  inline bool Connected(int p, int q) {
    return Find(p) == Find(q);
  }

  int Find(int p);
  void Union(int p, int q);

 private:
  int *id_ = nullptr;
  int *sz_ = nullptr;
  int count_;
};

#endif  // CHAPTER1_UNION_FIND_H_
