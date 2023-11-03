#include "Repair.h"

#include "AstarStrategy.h"

Repair::Repair(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  SetNewDestination();
}

void Repair::SetNewDestination() {
  destination = {Random(-1400, 1500), position.y, Random(-800, 800)};
}

float Repair::Random(float Min, float Max) {
  return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

JsonObject Repair::GetDetails() const { return details; }

void Repair::Rotate(double angle) {
  direction.x = direction.x * std::cos(angle) - direction.z * std::sin(angle);
  direction.z = direction.x * std::sin(angle) + direction.z * std::cos(angle);
}

void Repair::Update(double dt, std::vector<IEntity *> scheduler) {
  // if (strategy) {
  //   if (strategy->IsCompleted()) {
  //     SetNewDestination();
  //     strategy = new AstarStrategy(position, destination, graph);
  //   } else {
  //     strategy->Move(this, dt);
  //   }
  // } else {
  //   strategy = new AstarStrategy(position, destination, graph);
  // }
}