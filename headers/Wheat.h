#ifndef WHEAT_H
#define WHEAT_H
#include "Plant.h"

class Wheat : public Plant
{
  private:

  public:
    // Constructor to initialize a Wheat object
    Wheat();

    // Implementation of the virtual function to get the type of the plant
    // Output: The type of the plant (in this case, type 1 for Wheat)
    int get_type();

    // Implementation of the virtual function to water the plant
    void water();

    //implementation of virtual function of water for wheat
    int get_maxWateringLevel() {return(5);}; //max for wheat is 5

    // Implementation of the virtual function to simulate growth of the plant
    // Output: True if the plant has grown, false otherwise
    bool grow();
};

#endif