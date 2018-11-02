#include "GenQueue.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  GenQueue<int> gen;
  gen.insert(new int(5));
  gen.insert(new int(6));
  gen.insert(new int(7));
  gen.insert(new int(8));


    cout << *gen.remove() << endl;
      cout << *gen.remove() << endl;
        cout << *gen.remove() << endl;
          cout << *gen.remove() << endl;


            cout << gen.getSize() << endl;


  return 0;
}
