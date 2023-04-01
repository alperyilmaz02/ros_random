#include "example.hpp"
#include <iostream>
using namespace std;

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
