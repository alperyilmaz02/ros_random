#include "example.h"

using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle nodeHandler;

  //parameters initializations that will be taken from yaml file
  int frekans;
  std::string topicName;

  // Get the parameters from the parameter server
  nodeHandler.getParam("frekans", frekans);
  nodeHandler.getParam("topicName", topicName);


  ros::Publisher chatter_pub = nodeHandler.advertise<std_msgs::Float64>(topicName, 1000);

  ros::Rate loop_rate(frekans);
  
  srand(time(0));
  
  vector<double> doubleVector(10);  //initialize a double vector
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

