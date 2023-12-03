#ifndef BARLEY_H
#define BARLEY_H
#include "Plant.h"

class Barley : public Plant
{
private:

public:
    // Constructor to initialize a Barley object
    Barley();

    // Implementation of the virtual function to get the type of the plant
    // Output: The type of the plant (in this case, type 2 for Barley)
    int get_type();

    // Implementation of the virtual function to simulate growth of the plant
    // Output: True if the plant has grown, false otherwise
    bool grow();

    // Implementation of the virtual function to water the plant
    void water();

    //max watering level for barley is 4
    int get_maxWateringLevel() {return(4);};
};

#endif