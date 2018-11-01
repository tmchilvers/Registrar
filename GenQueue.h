#ifndef GENQUEUE_H
#define GENQUEUE_H

#include "GenDoublyLL.h"
#include <iostream>

using namespace std;

template <class T>
class GenQueue {
public:
  GenQueue();
  ~GenQueue();
  void insert(T* data);
  T* remove();
  T* peek();

  bool isEmpty();
  int getSize();
private:
  //ListNode<T> *front;
  //ListeNode<T> *back;
  int size;
  GenDoublyLL<T> *myQueue;
};

//Template Functions============================================================
template <class T>
GenQueue<T>::GenQueue() {
  //front = NULL;
  //rear = NULL;
  size = 0;
  myQueue = new GenDoublyLL<T>();
}

template <class T>
GenQueue<T>::~GenQueue() {
  delete myQueue;
}

template <class T>
void GenQueue<T>::insert(T* data) {
  myQueue->insertBack(data);
  //cout << "inserting: " << data << endl;
  size++;
}

template <class T>
T* GenQueue<T>::remove() {
  if(size < 1) {
    cout << "Queue empty." << endl;
    exit(EXIT_FAILURE);
  }
  else {
    return myQueue->removeFront();
    size--;
  }
}

template <class T>
T* GenQueue<T>::peek() {
  if(size < 1) {
    cout << "Queue empty." << endl;
    exit(EXIT_FAILURE);
  }
  else {
    //cout << "Peeking: " << myQueue->getFront()->data << endl;
    return myQueue->getFront()->data;
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
