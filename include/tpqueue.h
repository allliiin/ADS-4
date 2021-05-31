// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 private:
  T *arr;
  int size;
  int begin,
    end;
  int count;
 public:
  TPQueue():
    size(100),
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
  }
  ~TPQueue() {
    delete[] arr;
  }
  void push(const T &);
  T pop();
  T get() const;
  bool isEmpty() const;
  bool isFull() const;
};
template<typename T>
void TPQueue<T>::push(const T & item) {
  assert(count < size);
  if (end != 0) {
    for (int i = end - 1; i > -1; --i) {
      if (arr[i].prior >= item.prior) {
        arr[i + 1] = item;
        continue;
      } else {
        arr[i + 1] = arr[i];
        if (i == 0)
          arr[i] = item;
        continue;
      }
    }
  } else {
    arr[begin] = item;
  }
  count++;
  end++;
}
