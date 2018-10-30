#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>

using namespace std;

template <class T>
class GenQueue {
public:
  GenQueue();
  ~GenQueue();
  void insert(const T& data);
  char remove();
  char peek();

  bool isEmpty();
  int getSize();
private:
  //ListNode *front;
  //ListeNode *back;
  int size;
  T *myQueue;
};

template <class T>
GenQueue<T>::GenQueue() {
  front = NULL;
  rear = NULL;
  size = 0;
  myQueue = new GenDoublyLL<T>();
}

template <class T>
GenQueue<T>::~GenQueue() {
  delete myQueue;
}

template <class T>
void GenQueue<T>::insert(char data) {
  myQueue.insertBack(data);
  size++;
}

template <class T>
T GenQueue<T>::remove() {
  if(size < 1) {
    cout << "Queue empty." << endl;
    return;
  }
  else {
    return myQueue.removeFront();
    size--;
  }
}

template <class T>
T GenQueue<T>::peek() {
  if(size < 1) {
    cout << "Queue empty." << endl;
    return;
  }
  else {
    return myQueue.getFront();
  }
}

template <class T>
bool GenQueue<T>::isEmpty() {
  return size == 0;
}

template <class T>
int GenQueue<T>::getSize() {
  return size;
}

#endif
