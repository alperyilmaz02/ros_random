#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <time.h>
#include "ros/ros.h"
#include "std_msgs/Float64.h"


//FUNCTION DECLERATIONS

// prints parameters of the double vector
void dprint(std::vector <double> const &dVector);

// prints parameters of the int vector
void iprint(std::vector <int> &iVector);

// converts double values in vector to integer values
void toInt(std::vector <double> const &iVector, std::vector <int> &dVector);

//find smallest and largest numbers, get their arithmetic mean 
float findIt(std::vector <int> const &iVector);

#endif
