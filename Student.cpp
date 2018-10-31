#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include <iostream>

using namespace std;

Student::Student() {
  waitTime = 0;
  qLength = 0;
}
Student::Student(int qL) {
  waitTime = 0;
  qLength = qL;
}
Student::Student(Student other) {
  waitTime = other.getWaitTime();
  qLength = other.getQLength();
}
Student::~Student() {

}

int Student::getWaitTime() {
  return waitTime;
}
void Student::setWaitTime(int t) {
  waitTime = t;
}

int Student::getQLength() {
  return qLength;
}
void Student::setQLength(int t) {
  qLength = t;
}

bool Student::isWaitOver10() {
  return waitTime > 10;
}
