#include "Wheat.h"
#include "Barley.h"

Wheat::Wheat(){
    growthStage = 0;
    wateringLevel = 0;
    isFertilised = false;
    textureFilenames.push_back("sprites/wheatSprite/wheat0.png");
    textureFilenames.push_back("sprites/wheatSprite/wheat1.png");
    textureFilenames.push_back("sprites/wheatSprite/wheat2.png");
    textureFilenames.push_back("sprites/wheatSprite/wheat3.png");
    textureFilenames.push_back("sprites/wheatSprite/wheat0watered.png");
    textureFilenames.push_back("sprites/wheatSprite/wheat1watered.png");
    textureFilenames.push_back("sprites/wheatSprite/wheat2watered.png");
    std::cout << "Wheat plant created." << std::endl;
}

int Wheat::get_type(){
    return 1;
}

void Wheat::water() {
    if(wateringLevel < 5){
        wateringLevel++;
        std::cout << "wheat plant watered to hydration level: " << wateringLevel << std::endl;
        return;
    } else {
        std::cout << "watering level ="<< wateringLevel <<" (wheat has been watered)" << std::endl;
    }
}

bool Wheat::grow(){
  /*conditions for growth*/
  if(growthStage < 3 && wateringLevel == 5 && isFertilised){
    growthStage++;
    std::cout << "a wheat plant grew to the next stage!" << std::endl;
    wateringLevel--;
    return true;
  }
  else if (growthStage == 3) std::cout << "a wheat plant is at max growth stage!" << std::endl;
  wateringLevel--;
  return false;
}