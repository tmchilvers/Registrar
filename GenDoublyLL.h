#ifndef GENDOUBLYLL_H
#define GENDOUBLYLL_H

#include <iostream>

using namespace std;

/*

*/
//template class================================================================
template <class T>
class GenDoublyLL
{
  private:
    ListNode *front;
    ListNode *back;
    unsigned int size;

  public:
    GenDoublyLL();
    ~GenDoublyLL();

    void insertFront(T d);
    void removeBack(T d);
    T removeFront();
    T removeBack();
    ListNode *remove(T key);

    T deletePos(int pos);
    int find(T value);

    void printList();
    unsigned int getSize();
}

//template functions============================================================
//constructors / destructor=====================================================
template <class T>
GenDoubleLL<T>::GenDoubleLL()
{
  front = NULL;
  size = 0;
}

GenDoubleLL<T>::~GenDoubleLL()
{
  // ??????
}

void GenDoubleLL<T>::insertFront(T d)
{
  ListNode *node = new ListNode(d);

  if(size == 0) //empty ListNode
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

void GenDoubleLL<T>::insertBack(T d)
{
  ListNode *node = new ListNode();
   if (size == 0) {
     front = node;
   }
   else
   {
     back->next = node;
     mode->prev = back;
   }
   back = node;
   size++;
}

T GenDoubleLL<T>::removeFront()
{
  ListNode *temp = front;

  if(size == 0)
  {
    cerr << "Nothing to remove" << endl;
  }

  else if (front->next == NULL) { //only node in listNode;
    back = NULL;
  }

  else // more than one node in listNode
  {
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;

  T data = temp->data;
  temp->next = NULL;

  T data = temp->data;
  delete temp;
  size--;
  return data;
}

T GenDoubleLL<T>::removeBack()
{
  //??????
}

ListNode* GenDoubleLL<T>::remove()
{
  ListNode *current = front;

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

int GenDoubleLL<T>::find(T value)
{
  int idx = -1;
  ListNode *curr = front;

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

T GenDoubleLL<T>::deletePos(int pos)
{
  int idx = 0;

  ListNode *curr = front;
  ListNode *prev = front;

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

unsigned int GenDoubleLL<T>::getSize()
{
  return size;
}

void GenDoubleLL<T>::printList()
{
  ListNode *curr = front;

  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}
