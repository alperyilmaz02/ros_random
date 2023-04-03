#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;

//FUNCTION DECLERATIONS

// prints parameters of the double vector
void dprint(std::vector <double> const &dVector);

// prints parameters of the int vector
void iprint(std::vector <int> &iVector);

// converts double values in vector to integer values
void toInt(std::vector <double> const &iVector, std::vector <int> &dVector);

//find smallest and largest numbers, get their arithmetic mean 
float findIt(std::vector <int> const &iVector);


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "talker");

  ros::NodeHandle nodeHandler;

  ros::Publisher chatter_pub = nodeHandler.advertise<std_msgs::Float64>("bias", 1000);

  ros::Rate loop_rate(10);
  
  srand(time(0));
  
  vector<double> doubleVector(10);   //initialize a double vector
  vector<int> intVector(10);   //initialize a integer vector
  
  while (ros::ok())
{
    for (int i = 0; i < 10; i++)
      doubleVector[i] = (double)rand() / RAND_MAX * 99 + 1; //generates a double value and fills vector with this values
  
    //dprint(doubleVector); //prints double vector
    toInt(doubleVector,intVector); // generates a new vector from double vector converting doubles to integer
    //iprint(intVector); //prints integer vector
    float arith = findIt(intVector); // finds smallest and largest numbers in vector and finds their arithmetic mean
    
    std_msgs::Float64 msg; //float64 msg type object
    msg.data = arith;
    ROS_INFO("%f", msg.data);  // This will print the message value in the terminal
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
}

  return 0;
}


//FUNCTIONS DEFINITIONS

void dprint(std::vector <double> const &dVector) {
   std::cout << "Double vector elements are : ";

    for(int i=0; i < dVector.size(); i++)
        std::cout << dVector.at(i) << ' ';
    cout << "\n";
}

void iprint(std::vector <int> &iVector) {
   std::cout << "Integer vector elements are : ";

    for(int i=0; i < iVector.size(); i++)
        std::cout << iVector.at(i) << ' ';
    cout << "\n";
}

void toInt(std::vector <double> const &dVector, std::vector <int> &iVector) {

    for(int i=0; i < dVector.size(); i++){
        iVector[i] = int(dVector[i]);
    }
}

float findIt(std::vector <int> const &iVector){
    int small, large;
    small = iVector[0]; // gave it the first value in the vector
    large = iVector[0];  // gave it the first value in the vector
    for (int i = 0; i < iVector.size(); i++){
        
        if (iVector[i] < small){ // compares the values and assign the smallest one "small" value
            small = iVector[i];
        }
        if (iVector[i] > large){ // compares the values and assign the largest one "large" value
            large = iVector[i];
        }
    }
     //cout << "smallest number in vector is:" << small;
     //cout << "\n";
     //cout << "largest number in vector is:" << large;
     //cout << "\n";

    float arith;
    arith = (small + large) / 2.0;
     //cout << "The arithmetic mean of smallest and largest number in vector is:" << arith;
     //cout << "\n";

    return arith;
}
