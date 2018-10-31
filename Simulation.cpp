#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Simulation() {

}
~Simulation() {

}

void init(string filePath) {

  GenQueue<Student> line;
  GenDoublyLL<Student> studentList;
  int tick;
  string line;
  int numWindows;

  FileIO io(filePath);

}
