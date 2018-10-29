class IDoublyLinkedList
{
  public:
    virtual void insertFront(int d) = 0;
    virtual void removeBack(int d) = 0;
    virtual int removeFront() = 0;
    virtual int removeBack() = 0;
    virtual ListNode *remove(int key) = 0;

    virtual int deletePos(int pos) = 0;
    virtual int find(int value) = 0;

    virtual void printList() = 0;
    virtual unsigned int getSize() = 0;
};
