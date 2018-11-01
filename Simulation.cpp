#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Simulation::Simulation() {

}
Simulation::~Simulation() {

cout << "DESTRUCTOR" << endl;
}

void Simulation::init(string filePath) {
  GenQueue<Student> studentLine;
  //GenDoublyLL<Student> studentList;
  int tick;
  string line;
  int numWindows;

  FileIO io(filePath);
  int numLines = io.countLines();//how many lines are in file
  int parsedFile[numLines]; //array of size file length

  ifstream& inFile = io.getInFile();

  int count = 0;
  while(getline(inFile, line))
  {
    parsedFile[count++] = stoi(line); //array is filled with lines from files as ints
  }

  int atTime = 0; //the time that students arrive

  numWindows = parsedFile[0];
  for(int i = 1; i < numLines; i++) //populating the queue with students
  {
    //at what time
    int arrivalTime = parsedFile[i]; //first line indicates arrival time
    int numStudents = parsedFile[i+1]; //second line indicates how many students
    for(int j = 0; j < numStudents; j++) { //adding students to Queue
      studentLine.insert(new Student((parsedFile[(i+2)+j]),(0-arrivalTime)));
    }
    i += (1 + numStudents);


  }
   /*//Clears the queue and tests to make sure it clears correctly.
  while(!studentLine.isEmpty()) {
    cout << studentLine.peek()->getQLength() << " , " << studentLine.peek()->getWaitTime() << endl;
    studentLine.remove();
  }*/

  cout << "num of windows: " << numWindows << endl;
}
