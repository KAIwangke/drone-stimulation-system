#include "Car.h"

#include "AstarStrategy.h"

#include "DataCollection.h"
using namespace std;
Car::Car(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
  strategyName= "astar";
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  SetNewDestination();
}

void Car::SetNewDestination() {
  destination = {Random(-1400, 1500), position.y, Random(-800, 800)};
}

float Car::Random(float Min, float Max) {
  return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

JsonObject Car::GetDetails() const { return details; }

void Car::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Car::Update(double dt, std::vector<IEntity *> scheduler) {
  if(broken != 11){
    broken = ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX))
    * (2000 - (0))) + (0);
    if (strategy) {
      if (strategy->IsCompleted()) {
        SetNewDestination();
        strategy = new AstarStrategy(position, destination, graph);
      } else {
        strategy->Move(this, dt);
      }
    } else {
        strategy = new AstarStrategy(position, destination, graph);
    }
    Rotate(-3.1415926/4);
  }
  else if(broken == 11){
    strategy=NULL;
  }
}