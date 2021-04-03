/*
 * @Author: Sean Zhang 
 * @Date: 2021-04-03 23:46:06 
 * @Last Modified by: Sean Zhang
 * @Last Modified time: 2021-04-04 00:37:24
 */
#include <iostream>

template<typename T>
class PriorityQueue {
 public:
  PriorityQueue(){}
  PriorityQueue(int maxN) {
    pq_ = new T[maxN + 1];  // start from pq[1]
    capacity_ = maxN;
  }
  ~PriorityQueue() {
    if (pq_) 
      delete [] pq_;
  }

  bool IsEmpty() const {
    return size_ == 0;
  }

  int Size() const {
    return size_;
  }

  int Capacity() const {
    return capacity_;
  }

  void Insert(const T v) {
    if (size_ == capacity_)
      Resize(2 * capacity_);
    pq_[++size_] = v;
    Swim(size_);
  }

  T DelMax() {
    T max_value = pq_[1];
    pq_[1] = pq_[size_--];
    Sink(1);
    if (size_ > 0 && size_ == capacity_ / 4)
      Resize(capacity_ / 2);
    return max_value;
  }

 private:
  void Resize(int new_size) {
    T *temp = new T[new_size];
    for (int i = 0; i < size_; ++i) {
      temp[i] = pq_[i];
    }
    delete [] pq_;
    pq_ = temp;
    capacity_ = new_size;
  }

  void Swap(T &a, T&b) {
    T temp = a;
    a = b;
    b = temp;
  }

  void Swim(int k) {
    while (k > 1 && pq_[k / 2] < pq_[k]) {
      Swap(pq_[k/2], pq_[k]);
      k /= 2;
    }
  }

  void Sink(int k) {
    while (2 * k <= size_) { // if k has children
      int j = 2 * k;
      if (j < size_ && pq_[j] < pq_[j+1])  // select bigger child
        j++;
      if (!(pq_[k] < pq_[j]))
        break;
      Swap(pq_[k], pq_[j]);
      k = j;
    }
  }

  T *pq_ = nullptr;
  int size_ = 0;
  int capacity_ = 0;
};

int main(int argc, char **argv) {
  PriorityQueue<char> pq(128);
  pq.Insert('P');
  pq.Insert('Q');
  pq.Insert('E');
  std::cout << "Max: " << pq.DelMax() << std::endl;
  pq.Insert('X');
  pq.Insert('A');
  pq.Insert('M');
  std::cout << "Max: " << pq.DelMax() << std::endl;
  pq.Insert('P');
  pq.Insert('L');
  pq.Insert('E');
  std::cout << "Max: " << pq.DelMax() << std::endl;
}