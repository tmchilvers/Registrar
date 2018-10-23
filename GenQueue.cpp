#include "GenQueue.h"

using namespace std;

GenQeueue::GenQeueue() {
  front = -1;
  rear = 0;
  numElements = 0;
  size = 10;
  myQueue = new char[size];
}
GenQeueue::~GenQueue() {

}
void GenQeueue::insert(char data) {
  myQueue.insertRear(data);
}
char GenQeueue::remove() {
  return myQueue.removeFront();
}
char GenQeueue::peek() {
  return myQueue.front;
}

bool GenQeueue::isFull() {
  //dynamic size.. will never be full
}
bool GenQeueue::isEmpty() {
  return myQueue == NULL;
}
