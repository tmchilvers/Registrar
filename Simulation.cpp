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
      cout << "Student added. Arrival time: " << arrivalTime <<
      " and question length: " << parsedFile[(i+2)+j] << endl;
      //cout << "printing list:" << endl;
      //studentList.printList();
    }
    i += (1 + numStudents);


  }
   /*//Clears the queue and tests to make sure it clears correctly.
  while(!studentLine.isEmpty()) {
    cout << studentLine.peek()->getQLength() << " , " << studentLine.peek()->getWaitTime() << endl;
    studentLine.remove();
  }*/

  //cout << "num of windows: " << numWindows << endl;

  // File Reading Complete =====================================================
  //Simulation begins here
  cout << "printing list" << endl;
  studentList.printList();
  Window windowArray[numWindows];
  int studentWait[totalStudents];
  int k = 0;
  int time = 0;
  //===========================================================================
  while(true) { //main loop
  cout << "TIME: " << time << endl << endl;
  if(studentLine.isEmpty() && studentList.isEmpty()) {
    bool exit = true;
    for(int i = 0; i < numWindows; i++) {
      if(windowArray[i].hasStudent())
      exit = false;
    }
    cout << "here" << endl;
    if(exit)
    {
      break;
    }
  }

    cout << "print list: " << endl;
    studentList.printList();
    //Iterate through student list to put them into Queue
    ListNode<Student> *curr = studentList.getFront();
    while(curr != NULL)
    {
      cout << curr->data->arrivalTime << endl;
      if(time == curr->data->arrivalTime)
      {
        studentLine.insert(curr->data);
        cout << "student added to queue" << endl;
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
        //if a window is empty, fill it with next student in queue **Don't forget to set student's wait time**
      /*if(time == 5) {
        exit(EXIT_FAILURE);
      }*/
      if(!windowArray[i].hasStudent()) {

        if(!studentLine.isEmpty()) {
          cout << "something" << endl;
          cout << "queue size: " << studentLine.getSize() << endl;
          studentLine.printQueue();
          cout << "WAITTIME: " << studentLine.peek()->getWaitTime() << endl;
          windowArray[i].setStudent(studentLine.remove());
          cout << "Student removed from queue." << endl;

          //setting wait time correctly
          /*if(windowArray[i].getStudent()->getWaitTime() < 0) {
            windowArray[i].getStudent()->setWaitTime(0);
          }*/

          windowArray[i].getStudent()->setWaitTime(time - windowArray[i].getStudent()->arrivalTime);

          cout << "Filled window " << i << " with student." << endl;
          cout << "Student waited " << windowArray[i].getStudent()->getWaitTime() << " minutes." << endl;
          cout << "stop 1" << endl;
        }
      }
    }


    if(studentLine.isEmpty() && studentList.isEmpty()) {
      bool exit = true;
      for(int i = 0; i < numWindows; i++) {
        if(windowArray[i].hasStudent())
        exit = false;
      }
      cout << "here" << endl;
      if(exit)
      {
        break;
      }
    }

    time++;
    cout << "stop 2" << endl;
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


//print wait times
  for(int i = 0; i < totalStudents; i++) {
    cout << "Student " << i << " waited for " << studentWait[i] << " minutes" <<
    endl;
  }

  for(int i = 0; i < numWindows; i++) {
    cout << "Window " << i << " was idle for " << windowArray[i].idleTime <<
    " minutes" << endl;
  }

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
