#include "GenQueue.h"
#include "LinkedList.h"
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
