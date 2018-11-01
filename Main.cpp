#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include "FileIO.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  string filePath;
  if (argc != 2) { //Checks for valid command line arguments and saves argument to filePath variable
    cerr << "Incorrect number of arguments. Execution terminated." << endl;
    return 0;
  }
  else {
    filePath = argv[1];
  }

  Simulation simulation;
  simulation.init(filePath);
  cout << "end of file" << endl;

  return 0;
}
