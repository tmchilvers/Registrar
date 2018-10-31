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
  while(getline(inFile, line) && count < numLines)
  {
    parsedFile[count++] = stoi(line);
  }
}
