//this class represents a single linked list
class DoublyLinkedList
{
    private:
      ListNode *front;
      ListNode *back;
      unsigned int size;   //unsigned means can't be negative

    public:
      DoublyLinkedList();
      ~DoublyLinkedList();

      void insertFront(int d);
      void removeBack(int d);
      int removeFront();
      int removeBack();
      ListNode *remove(int key);

      int deletePos(int pos);
      int find(int value);

      void printList();
      unsigned int getSize();
};
