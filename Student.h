#include "GenQueue.h"
#include "LinkedList.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Window.h"
#include <iostream>

using namespace std;

class Student {
public:
  Student();
  ~Student();

  int getWaitTime();
  void setWaitTime(int t);

  int getQLength();
  void setQLength(int t);

  bool isWaitOver10();
private:
  int waitTime; //wait time in minutes
  int qLength; //length of student's question in minutes
};
