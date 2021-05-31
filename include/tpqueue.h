// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 private:
T* arr;
int size;
int start, follow;
int count;
	  
 public:
TPQueue() :
size(100),
start(0), follow(0), count(0) {
arr = new T[size + 1];
}
~TPQueue() {
delete[] arr;
}
void push(const T& item) {
assert(count < size);
if (follow != 0) {
arr[follow] = item;
for (int i = follow - 1; i >= start; i--) {
if (item.prior > arr[i].prior) {
arr[i + 1] = arr[i];
arr[i] = item;
}
}
} else {
arr[start] = item;
}
follow++;
count++;
if (follow > size)
follow -= size + 1;
}
T pop() {
assert(count > 0);
T item = arr[start++];
count--;
if (start > size)
start -= size + 1;
return item;
}
T get() const {
assert(count > 0);
return arr[start];
}
bool isEmpty() const {
return count == 0;
}
bool isFull() const {
return count == size;
}
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
