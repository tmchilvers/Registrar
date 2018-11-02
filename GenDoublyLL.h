#ifndef GENDOUBLYLL_H
#define GENDOUBLYLL_H

#include "ListNode.h"
#include <iostream>

using namespace std;

//template class================================================================
template <class T>
class GenDoublyLL
{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

  public:
    GenDoublyLL();
    ~GenDoublyLL();

    void insertFront(T*);
    void insertBack(T*);
    T* removeFront();
    T* removeBack();
    ListNode<T> *remove(T key);

    T deletePos(int pos);
    int find(T value);

    bool isEmpty();

    void printList();
    unsigned int getSize();
    ListNode<T>* getFront();
    ListNode<T>* getBack();
};

//template functions============================================================
//constructors / destructor=====================================================
template <class T>
GenDoublyLL<T>::GenDoublyLL()
{
  front = NULL;
  size = 0;
}

template <class T>
GenDoublyLL<T>::~GenDoublyLL()
{
  while(front)
  {
    ListNode<T> *node = front;
    front = front->next;
    delete node;
  }
}

template <class T>
void GenDoublyLL<T>::insertFront(T* d)
{
  ListNode<T> *node = new ListNode<T>(d);

  if(size == 0) //empty ListNode<T>
  {
    back = node;
  }

  else //not empty
  {
    front->prev = node;
    node->next = front;
  }

  front = node;
  size++;
}

template <class T>
void GenDoublyLL<T>::insertBack(T* d)
{
  ListNode<T> *node = new ListNode<T>(d);
   if (size == 0) {
     front = node;
   }
   else
   {
     back->next = node;
     node->prev = back;
   }
   back = node;
   size++;
}

template <class T>
T* GenDoublyLL<T>::removeFront()
{
  ListNode<T> *temp = front;

  if(size == 0)
  {
    cerr << "Nothing to remove from Front" << endl;
    exit(EXIT_FAILURE);
  }

  else if (front->next == NULL) { //only node in ListNode<T>;
    back = NULL;
  }

  else // more than one node in ListNode<T>
  {
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;

  T* data = temp->data;

  delete temp;
  size--;
  return data;
}

template <class T>
T* GenDoublyLL<T>::removeBack()
{
  ListNode<T> *temp = back;
  if(size == 0)
  {
    cerr << "Nothing to remove" << endl;
    exit(EXIT_FAILURE);
  }

  else if (front->next == NULL) //only one element
  {
    front = NULL;
  }

  else
  {
    back->prev->next = NULL;
  }
  back = back->prev;
  temp->prev = NULL;

  T data = temp->data;
  delete temp;
  size--;
  return data;
}

template <class T>
ListNode<T>* GenDoublyLL<T>::remove(T key)
{
  ListNode<T> *current = front;

  while(current->data != key)
  {
    current = current->next;

    if (current == NULL) {
      return NULL;
    }
  }

  //we found it

  if (current == front) {
    front = current->next;
  }

  else{
    current->prev->next = current->next;
  }

  if (current = back) {
    back = current->prev;
  }

  else
  {
    current->next->prev = current->prev;
  }

  current->next = NULL;
  current->prev = NULL;

  --size;

  return current;
}

template <class T>
int GenDoublyLL<T>::find(T value)
{
  int idx = -1;
  ListNode<T> *curr = front;

  while(curr != NULL) //begin search for value
  {
    idx++;

    if(curr->data == value) //we found it
    {
      break;
    }
    else //we did not find it continue searching
    {
      curr = curr->next;
    }
  }

  if(curr == NULL)
  {
    idx = -1;
  }

 return idx;
}

template <class T>
T GenDoublyLL<T>::deletePos(int pos)
{
  int idx = 0;

  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(idx != pos) //this loop is responsible for putting our pointers in their correct positions
  {
    prev = curr;
    curr = curr->next;
    ++idx;
  }

  //found the position, lets proceed to delete

  prev->next = curr->next;
  curr->next = NULL;

  T d = curr->data;
  size--;

  delete curr;

  return d;
}

template <class T>
unsigned int GenDoublyLL<T>::getSize()
{
  return size;
}

template <class T>
void GenDoublyLL<T>::printList()
{
  ListNode<T> *curr = front;

  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
ListNode<T>* GenDoublyLL<T>::getFront()
{
  return front;
}

template <class T>
bool GenDoublyLL<T>::isEmpty() {
  return size == 0;
}

template <class T>
ListNode<T>* GenDoublyLL<T>::getBack()
{
  return back;
}

#endif
