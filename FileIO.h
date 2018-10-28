#ifndef FileIO_H
#define FileIO_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


//This class can read in a file and process the characters on each line.
//Must declare name of file as a string. Create the InFile object and put the name
//into the constructor argument
class FileIO
{
  public:
    //constructors
    FileIO(); //will only create an output file
    FileIO(string filePath); //will create an input file stream, and ask if output is necessary and create one if so
    ~FileIO(); //close file open and close stream

    //auxiliary functions
    void printFile();
    bool checkOpen();

    ifstream& getInFile(); //reference allows ability to get the file stream
    ofstream& getOutFile();

  private:
    ifstream inputFile;
    ofstream outputFile;
};

#endif
