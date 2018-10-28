#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>

using namespace std;

template <class T>
class GenQueue {
public:
  GenQueue();
  GenQueue(int maxSize);
  ~GenQueue();
  void insert(const T& data);
  char remove();
  char peek();

  bool isFull();
  bool isEmpty();
  int getSize();
private:
  int front;
  int rear;
  int numElements;
  int size;
  T *myQueue;
};

template <class T>
GenQueue<T>::GenQueue() {
  front = NULL;
  rear = NULL;
  numElements = 0;
  size = 100;
  myQueue = new DoublyLinkedList();
}

template <class T>
GenQueue<T>::~GenQueue() {

}

template <class T>
void GenQueue<T>::insert(char data) {
  myQueue.insertBack(data);
}

template <class T>
char GenQueue<T>::remove() {
  return myQueue.removeFront();
}

template <class T>
char GenQueue<T>::peek() {
  return myQueue.front;
}

template <class T>
bool GenQueue<T>::isFull() {
  //dynamic size.. will never be full
}

template <class T>
bool GenQueue<T>::isEmpty() {
  return myQueue == NULL;
}

#endif
