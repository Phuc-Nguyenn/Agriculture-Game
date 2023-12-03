#include "Plot.h"
#include <iostream>

// Constructor for Plot class
Plot::Plot(std::string texture_filename, float pos_x, float pos_y) : GameTile(texture_filename, pos_x, pos_y){
    entity = nullptr; // Initialize entity pointer to null
}

// Function to check if the plot contains a plant
bool Plot::get_isPlant(){
  if(entity)
    return entity->get_isPlant();
  else
    return false;
}

// Function to check if the plot contains an animal
bool Plot::get_isAnimal(){
  if(entity)
    return entity->get_isAnimal();
  else
    return false;
}

// Function to place an entity (plant or animal) on the plot
bool Plot::placeEntity(Entity *_entity){
    if(this->isEmpty() == false){
        std::cout<< "Entity not placed since plot is occupied" << std::endl;
        return false;
    }
    setUpBackSprite("sprites/Transparent.png", 16, 0);
    setUpFrontSprite(_entity->textureFilenames[0]);
    this->entity = _entity;
    std::cout<< "Entity placed successfully on an empty plot" << std::endl;
    return true;
}

// Function to clear the plot (remove entity and reset flags)
bool Plot::clear(){
    delete entity;
    entity->set_isAnimal(false);
    entity->set_isPlant(false);
    return true;
}

// Function to water the entity on the plot
void Plot::water(){
    this->entity->water();
    if(this->entity->get_isPlant() == true && entity->get_isWatered() == entity->get_maxWateringLevel() && entity->get_growthStage() != 3) {
        setUpFrontSprite(entity->textureFilenames[entity->get_growthStage()+4]);
    }
}

// Function to fertilize the entity on the plot
void Plot::fertilise(Inventory *Inventory){
    this->entity->fertilise(Inventory);
}

// Function to feed the entity on the plot
void Plot::feed(Inventory *Inventory){
    this->entity->eatGrain(Inventory);
}

// Function to harvest the entity on the plot and add to inventory
bool Plot::harvest(Inventory *inventory){
    if(isEmpty()==false){
        // Checks the type of entity and harvests depending on type
        switch (entity->get_type())
        {
            case 1:
                if(entity->get_growthStage() == 3){
                    inventory->wheatGrainAdd(1); // Adds wheat to the inventory and destroys plant
                    std::cout << "Wheat harvested and added to inventory!" << std::endl;
                }
                plotReset();
                return 1;
                break;
            case 2:
                if(entity->get_growthStage() == 3){
                    inventory->barleyGrainAdd(1); // Adds barley to the inventory and destroys plant
                    std::cout<<"Barley harvested and added to inventory"<<std::endl;
                }
                plotReset();
                return 1;
                break;
            case 3:
                if(entity->getEggs()>0){
                    std::cout<<entity->getEggs()<<" eggs added to inventory"<<std::endl;
                    inventory->eggsAdd(entity->getEggs());
                    entity->setEggs(0);
                    std::cout<<"Eggs gathered and added to inventory"<<std::endl;
                    // Adds any accumulated eggs to the inventory
                }
                return 1;
                break;
            case 4: 
                if(entity->getWool()>0){
                    std::cout<<"1 wool added to inventory"<<std::endl;
                    inventory->woolAdd(entity->getWool());
                    entity->setWool(0);
                    setUpFrontSprite("./sprites/sheepSprite/sheepShornSprite.png");
                    std::cout<<"Sheep has been shorn and wool added to inventory"<<std::endl;
                    // Adds any accumulated wool to the inventory
                }
                return 1;
                break;
            default:
                plotReset();
                return 0;
                break;
        }
    }
    return false;
}

// Function to slaughter an animal entity on the plot and add meat to inventory
void Plot::Slaughter(Inventory *Inventory){
    if(entity->get_isPlant() == true){
        std::cout<<"Error: Slaughter called on a non-animal entity"<<std::endl;
    }
    else if(entity->get_type() == 3){
        Inventory->meatAdd(1);
        plotReset();
        std::cout<<"A chicken has been slaughtered"<<std::endl;
    }
    else if(entity->get_type() == 4){
        Inventory->meatAdd(3);
        plotReset();
        std::cout<<"A sheep has been slaughtered"<<std::endl;
    }
}

// Function to reset the plot by removing the entity and resetting flags
void Plot::plotReset() {
  if(entity)
    delete entity;
  entity = nullptr;
  setUpFrontSprite("sprites/Transparent.png");
}

// Function to check if the plot is empty
bool Plot::isEmpty(){
    if(entity == nullptr){
        return true;
    }
    else{
        return false;
    }
}

// Function to grow the entity on the plot
bool Plot::growEntity() {
  if(entity->grow()) {
    return true;
  }
  else 
    return false;
}

// Function to check if the entity on the plot has died and reset if needed
bool Plot::checkDeath(){
    if(entity && entity->checkDeath() == 1){
        plotReset();
        return 1;
    }
    return 0;
}

// Function to update the sprite of the entity on the plot
bool Plot::updateSprite(){
  if(this->isEmpty() == false)
  {
    std::string newFilename = entity->getCorrectFilename();
    setUpFrontSprite(newFilename);
    return 1;
  }
  return 0;
}