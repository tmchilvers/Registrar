#ifndef WINDOW_H
#define WINDOW_H

#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Window.h"
#include "Student.h"
#include <iostream>

using namespace std;

class Window {
public:
  Window();
  ~Window();

  Student* getStudent();
  void setStudent(Student* s);
  Student* clearStudent();
  bool hasStudent();

  int getCurrQTime();
  void setCurrQTime(int t);
  void incrementCurrQTime();

  int idleTime;
  void incrementIdleTime();

private:
  Student *currStudent;
  int currQTime;
};

#endif
