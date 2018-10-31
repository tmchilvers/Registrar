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

void init(ifstream& file) {
  GenQueue<Student> line;
  GenDoublyLL<Student> studentList;
  int tick;
  string line;
  int numWindows;

  if(getline(file,line)) { //read first line
    numWindows = stoi(line);
  }
  else {
    //empty file
    cerr << "File empty." << endl;
    exit(EXIT_FAILURE);
  }

  //read successive lines
  while(getline(file,line)) {
    for(int i = 0; i < stoi(line); i++) {
      string tempLine;
      getline(file,tempLine)
      studentList.insertFront(new Student(stoi(tempLine)))
    }
  }
}
