#include "GenQueue.h"
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
  string line;
  int numWindows;
  int totalStudents;

  FileIO io(filePath);
  int numLines = io.countLines();//how many lines are in file
  int parsedFile[numLines]; //array of size file length

  ifstream& inFile = io.getInFile();

  int count = 0;
  while(getline(inFile, line))
  {
    parsedFile[count++] = stoi(line); //array is filled with lines from files as ints
  }

  int atTime; //the time that students arrive

  numWindows = parsedFile[0];
  for(int i = 1; i < numLines; i++) //populating the queue with students
  {
    //at what time
    int arrivalTime = parsedFile[i]; //first line indicates arrival time
    int numStudents = parsedFile[i+1]; //second line indicates how many students
    totalStudents += numStudents;
    for(int j = 0; j < numStudents; j++) { //adding students to Queue
      studentList.insertBack(new Student((parsedFile[(i+2)+j]), 0, arrivalTime));
    }
    i += (1 + numStudents);
  }

  // File Reading Complete =====================================================
  //Simulation begins here
  Window windowArray[numWindows];
  int studentWait[totalStudents];
  int k = 0;
  int time = 0;
  //===========================================================================
  while(true) { //main loop
  if(studentLine.isEmpty() && studentList.isEmpty()) {
    bool exit = true;
    for(int i = 0; i < numWindows; i++) {
      if(windowArray[i].hasStudent())
      exit = false;
    }
    if(exit)
    {
      break;
    }
  }

    //Iterate through student list to put them into Queue
    ListNode<Student> *curr = studentList.getFront();
    while(curr != NULL)
    {
      if(time == curr->data->arrivalTime)
      {
        studentLine.insert(curr->data);
        curr = curr->next;
        studentList.removeFront();
        continue;
      }
      curr = curr->next;
    }

    //time++;
    //increment current question time for active windows
    //check if any windows are full
    for(int i = 0; i < numWindows; i++) {
      if(windowArray[i].hasStudent()) { //if window is full, check if student has finished question

        int questionLength = windowArray[i].getStudent()->getQLength();
        int currentTime = windowArray[i].getCurrQTime();

        if(questionLength == currentTime) {
          //for now students are simply deleted, but should be moved to a "finished" pile for stats
          studentWait[k++] = windowArray[i].clearStudent()->getWaitTime(); //if student has finished question, remove student from window
        }
      }
    }

    //check if any windows are empty
    for(int i = 0; i < numWindows; i++) {
      if(!windowArray[i].hasStudent()) {
        if(!studentLine.isEmpty()) {
          windowArray[i].setStudent(studentLine.remove());
          windowArray[i].getStudent()->setWaitTime(time - windowArray[i].getStudent()->arrivalTime);
        }
      }
    }

    if(studentLine.isEmpty() && studentList.isEmpty()) {
      bool exit = true;
      for(int i = 0; i < numWindows; i++) {
        if(windowArray[i].hasStudent())
        exit = false;
      }
      if(exit)
      {
        break;
      }
    }

    time++;
    for(int i = 0; i < numWindows; i++)
    {
      if(!windowArray[i].hasStudent())
      {
        windowArray[i].incrementIdleTime();
      }

      else if(windowArray[i].hasStudent())
      {
        windowArray[i].incrementCurrQTime();
      }
    }
  }
// Calculate Stats ===========================================================

  //Student stats ==============================================================
  double meanStudents = 0;
  int longestStudent = studentWait[0];
  int temp = 0;
  int students10 = 0;

  for(int i = 0; i < totalStudents; i++)
  {
    temp = studentWait[i];
    if(longestStudent < temp)
    {
      longestStudent = temp;
    }

    if(studentWait[i] > 5)
    {
      students10++;
    }
    meanStudents+= studentWait[i];
  }
  cout << "\nMEAN OF STUDENT WAIT TIME: " << meanStudents / totalStudents << " min(s)" << endl;
  cout << "MEDIAN STUDENT WAIT TIME: " << calcMedian(studentWait,totalStudents) << " min(s)" << endl;
  cout << "LONGEST WAIT TIME FOR A STUDENT: " << longestStudent << " min(s)" << endl;
  cout << "NUMBER OF STUDENTS WHO WAITED FOR OVER 10 MINS: " << students10 << " student(s)\n" << endl;

  //Window Stats ===============================================================
  double meanWindow = 0;
  int longestWindow = windowArray[0].idleTime;
  temp = 0;
  int windows5 = 0;

  for(int i = 0; i < numWindows; i++)
  {
    temp = windowArray[i].idleTime;
    if(longestWindow < temp)
    {
      longestWindow = temp;
    }

    if(windowArray[i].idleTime > 5)
    {
      windows5++;
    }
    meanWindow+= windowArray[i].idleTime;
  }
  cout << "MEAN OF WINDOW IDLE TIME: " << meanWindow / numWindows << " min(s)" << endl;
  cout << "LONGEST IDLE TIME FOR A WINDOW: " << longestWindow << " min(s)" << endl;
  cout << "NUMBER OF WINDOWS IDLE FOR OVER 5 MINS: " << windows5 << " window(s)" << endl;
}

double Simulation::calcMedian(int arr[], int arrLength) {
  bubbleSort(arr,arrLength);
  if (arrLength % 2 != 0)
       return (double)arr[arrLength/2];

    return (double)(arr[(arrLength-1)/2] + arr[arrLength/2])/2.0;
}
void Simulation::swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void Simulation::bubbleSort(int arr[], int n)
{
   int i;
   int j;
   for (i = 0; i < n-1; i++)

       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
