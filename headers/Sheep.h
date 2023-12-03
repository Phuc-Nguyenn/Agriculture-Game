#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

// Declare the Sheep class, which inherits from the Animal class
class Sheep : public Animal
{
    private:
        bool wool;  // Private member variable to store if the sheep has wool

    public:
        // Constructor for the Sheep class
        Sheep();

        // Method to simulate the sheep producing wool
        void produceWool();

        // Getter method to retrieve the wool status
        bool getWool();

        // Setter method to set the wool status
        void setWool(bool _wool);

        // Method to get the type of animal (assuming it's defined in the Animal class)
        int get_type();

        // Method to simulate the growth of the sheep
        bool grow();

        // Method to provide water to the sheep
        void water();

        // Getter method to retrieve the maximum watering level for the sheep
        int get_maxWateringLevel() { return 3; };

        // Destructor for the Sheep class
        ~Sheep() {};
};

#endif  // End of the include guard to prevent multiple inclusions
