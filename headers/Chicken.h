#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"

// Chicken class, inheriting from Animal
class Chicken : public Animal
{
private:
    int eggs; // Number of eggs the chicken has

public:
    // Constructor for Chicken
    Chicken();

    // Lay an egg and return true if successful, false otherwise
    bool layEgg();

    // Get the current number of eggs
    int getEggs();

    // Set the number of eggs for the chicken
    void setEggs(int _eggs);

    // Get the type of the entity (inherited from Animal)
    int get_type();

    // Simulate growth of the chicken (inherited from Animal)
    bool grow();

    // Simulate watering the chicken (inherited from Animal)
    void water();

    // Get the maximum watering level for the chicken
    int get_maxWateringLevel() { return 3; };

    // Destructor for Chicken
    ~Chicken() {};
};

#endif