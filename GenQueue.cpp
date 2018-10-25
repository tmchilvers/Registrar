#include "GenQueue.h"

using namespace std;

GenQueue::GenQueue() {
  front = -1;
  rear = 0;
  numElements = 0;
  size = 10;
  myQueue = new char[size];
}
GenQueue::~GenQueue() {

}
void GenQueue::insert(char data) {
  myQueue.insertRear(data);
}
char GenQueue::remove() {
  return myQueue.removeFront();
}
char GenQueue::peek() {
  return myQueue.front;
}

bool GenQueue::isFull() {
  //dynamic size.. will never be full
}
bool GenQueue::isEmpty() {
  return myQueue == NULL;
}
