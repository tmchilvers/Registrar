
template <class T>
class IDoublyLinkedList
{
  public:
    virtual void insertFront(int d) = 0;
    virtual void removeBack(int d) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual ListNode *remove(int key) = 0;

    virtual T deletePos(int pos) = 0;
    virtual T find(int value) = 0;

    virtual void printList() = 0;
    virtual T getSize() = 0;
};
