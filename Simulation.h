#ifndef SIMULATION_H
#define SIMULATION_H

#include "GenQueue.h"
#include "GenDoublyLL.h"
#include "SimStats.h"
#include "Simulation.h"
#include "Window.h"
#include "Student.h"
#include <iostream>

using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();

  void init(string filePath);
  double calcMedian(int arr[], int arrLength);
  void swap(int *first, int *second);
  void bubbleSort(int arr[], int n);

private:

};

#endif
