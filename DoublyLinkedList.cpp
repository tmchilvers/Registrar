DoublyLinkedList::DoublyLinkedList()
{
  front = NULL;
  size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
  //food for thought
}

unsigned int DoublyLinkedList::getSize()
{
  return size;
}

void DoublyLinkedList::printList()
{
  ListNode *curr = front;

  while(curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void DoublyLinkedList::insertFront(int d)
{
  ListNode *node = new ListNode(d);

  if(size == 0) //empty ListNode
  {
    back = node;
  }

  else //not empty
  {
    front->prev = node;
    mode->next = front;
  }

  front = node;
  size++;
}

void DoublyLinkedList::insertBack(int d)
{
  ListNode *node = new ListNode();
   // if (size == 0) {
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

int DoublyLinkedList::removeFront()
{
  ListNode *temp = front;

  //check if isEmpty

  if (front->next == NULL) { //only node in listNode;
    back = NULL;
  }

  else // more than one node in listNode
  {
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;

  int data = temp->data;
  temp->next = NULL;

  int data = temp->data;
  delete temp;
  size--;
  return data;
}

int DoublyLinkedList::removeBack()
{
  //building character figure it out
}

ListNode* DoublyLinkedList::remove(int key)
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


int DoublyLinkedList::find(int value)
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

int DoublyLinkedList::deletePos(int pos)
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

  int d = curr->data;
  size--;

  delete curr;

  return d;
}
