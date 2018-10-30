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

  Student getStudent();
  void setStudent(Student& s);
private:
  Student *currStudent;
};

#endif
