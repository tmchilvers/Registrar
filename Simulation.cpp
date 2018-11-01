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
  GenDoublyLL<Student> studentList;
  int tick;
  string line;
  int numWindows;

  FileIO io(filePath);
  int numLines = io.countLines();
  int parsedFile[numLines];

  ifstream& inFile = io.getInFile();

  int count = 0;
  while(getline(inFile, line))
  {
    parsedFile[count++] = stoi(line);
  }

  int atTime = 0; //the time that students arrive

  numWindows = parsedFile[0];
  for(int i = 1; i < numLines; i++)
  {
    //at what time


  }

  cout << "num: " << numWindows << endl;
}
