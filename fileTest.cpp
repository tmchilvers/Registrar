#include <iostream>
#include <fstream>
#include <string>
#include "FileIO.h"

using namespace std;

int main()
{
  FileIO fileIO("README.md");
  ifstream& inFile = fileIO.getInFile();
  ofstream& outFile = fileIO.getOutFile();

  string line;
  while(getline(inFile, line))
  {
    for(int i = 0; i < line.size(); i++)
    {
      outFile << line[i];
    }
  }
}
