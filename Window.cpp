#include "GenQueue.h"
#include "LinkedList.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include <iostream>

using namespace std;

Window::Window() {

}
Window::~Window() {

}

Student Window::getStudent() {
  return currStudent
}
void Window::setStudent(Student& s) {
  currStudent = s;
}
