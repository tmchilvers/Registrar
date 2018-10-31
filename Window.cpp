#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include <iostream>

using namespace std;

Window::Window() {
  currStudent = NULL;
  currQTime = 0;
}
Window::~Window() {
  clearStudent();
}

Student Window::getStudent() {
  return currStudent;
}

void Window::setStudent(Student& s) {
  currStudent = s;
}

Student* Window::clearStudent() {
  Student temp(currStudent);
  currStudent = NULL;
  return temp;
}

bool Window::hasStudent() {
  return currStudent == NULL;
}

int getCurrQTime() {
  return currQTime;
}
void setCurrQTime(int t) {
  currQTime = t;
}
