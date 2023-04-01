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
void findIt(std::vector <int> const &iVector);

int main(){

    srand(time(0));
    size_t size = 10;

    vector<double> doubleVector(size);   //declares a dobule vector
    vector<int> intVector(size);   //declares a integer vector

    for (int i = 0; i < 10; i++)
        doubleVector[i] = (double)rand() / RAND_MAX * 99 + 1; //generates a double value and fills vector with this values
    
    dprint(doubleVector); //prints double vector
    toInt(doubleVector,intVector); // generates a new vector from double vector converting doubles to integer
    iprint(intVector); //prints integer vector
    findIt(intVector); // finds smallest and largest numbers in vector and finds their arithmetic mean

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

void findIt(std::vector <int> const &iVector){
    int small, large;
    small = 1000; // just gave it a random value that is too high
    large = 0;  // just gave it a random value that is too small
    for (int i = 0; i < iVector.size(); i++){
        
        if (iVector[i] < small){ // compares the values and assign the smallest one "small" value
            small = iVector[i];
        }
        if (iVector[i] > large){ // compares the values and assign the largest one "large" value
            large = iVector[i];
        }
    }
    cout << "smallest number in vector is:" << small;
    cout << "\n";
    cout << "largest number in vector is:" << large;
    cout << "\n";

    float arith;
    arith = (small + large) / 2.0;
    cout << "The arithmetic mean of smallest and largest number in vector is:" << arith;
    cout << "\n";
}
