#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include <iostream>

using namespace std;

Student::Student() {
  waitTime = 0;
  qLength = 0;
}

Student::Student(int qL, int wT, int aT) {
  waitTime = wT;
  qLength = qL;
  arrivalTime = aT;
}

Student::Student(Student& other) {
  waitTime = other.getWaitTime();
  qLength = other.getQLength();
}

Student::~Student() {
  cout << "HERE" << endl;
}

int Student::getWaitTime() {
  return waitTime;
}

void Student::setWaitTime(int t) {
  waitTime = t;
}

void Student::incrementWaitTime()
{
  waitTime++;
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
