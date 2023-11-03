#define _USE_MATH_DEFINES
#include "RPcar.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "AstarStrategy.h"
#include<bits/stdc++.h>
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

#include <cmath>
#include <limits>
using namespace std;

RPcar::RPcar(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;

  isrpcar = 1;
}

RPcar::~RPcar() {
  // Delete dynamically allocated variables
}

void RPcar::GetNearestEntity(std::vector<IEntity*> carscheduler) {
  // float minDis = std::numeric_limits<float>::max();
  // int count = 0;
  // for (auto entity : carscheduler) {
  //   count ++ ;
  //   if (entity->GetAvailability()) {
  //     float disToEntity = this->position.Distance(entity->GetPosition());
  //     if (disToEntity <= minDis) {
  //       minDis = disToEntity;
  //       nearestEntity = entity;
  //     }
  //   }
  // }
  // cout << count << endl;
  // cout << "I m not here" << endl;
  // cout << carscheduler.size() << endl;
  nearestEntity = carscheduler[0];
  // for (int i = 0 ;i < carscheduler.size(); i++){
  //   JsonObject detailsTemp = carscheduler[i]->GetDetails();
  //   cout<<detailsTemp["name"]<<endl;
  // }
  //JsonObject detailsTemp = carscheduler[0]->GetDetails();
  //cout<<detailsTemp["name"]<<endl;
  // cout << "I m here" << endl;

  if(nearestEntity){
    nearestEntity->SetAvailability(false);  // set availability to the nearest entity
    available = false;
    pickedUp = false;

    destination = nearestEntity->GetPosition(); 
    Vector3 rpstation = {0,270,280};
    toTargetPosStrategy = new AstarStrategy(this->GetPosition(), destination, graph);
    
    std::string targetStrategyName = nearestEntity->GetStrategyName();
    // std::cout << nearestEntity->GetStrategyName() << std::endl;
    if(targetStrategyName.compare("astar") == 0){
        toTargetDestStrategy = new AstarStrategy(nearestEntity->GetPosition(), rpstation, graph);
        //toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dfs") == 0){
        toTargetDestStrategy = new DfsStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
       
    } else if (targetStrategyName.compare("dijkstra") == 0){
        toTargetDestStrategy = new DijkstraStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
   
    } 

  }
}

void RPcar::Update(double dt, std::vector<IEntity*> carscheduler) {
  if (available && carscheduler.size() > 0) {
    GetNearestEntity(carscheduler);
    // cout << "I m not here" << endl;
    // nearestEntity = carscheduler.at(0);
    // cout << "I m not here" << endl;

  }

  if(toTargetPosStrategy){
    toTargetPosStrategy->Move(this, dt);
    if(toTargetPosStrategy->IsCompleted()){
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;

      color = "#fa0003"; // changes color to red when picked up
      
    }
  } 
  else if (toTargetDestStrategy) {
    toTargetDestStrategy->Move(this, dt);
    // cout << "I m not here" << endl;
    // cout << nearestEntity->GetDestination().x << "," << nearestEntity->GetDestination().y << "," << nearestEntity->GetDestination().z << endl;
    // Moving the robot
    nearestEntity->SetPosition(this->GetPosition());
    nearestEntity->SetDirection(this->GetDirection());
    if(toTargetDestStrategy->IsCompleted()){
        delete toTargetDestStrategy;
        toTargetDestStrategy = NULL;
        available = true;
        nearestEntity->Setbroken(100);
        nearestEntity->Setstop(0);
        // cout << "I m not here" << endl;
        // for (int i = 0 ;i < carscheduler.size(); i++){
        //   JsonObject detailsTemp = carscheduler[i]->GetDetails();
        //   cout<<detailsTemp["name"]<<endl;
        // }
        carscheduler.erase(carscheduler.begin());
        // for (int i = 0 ;i < carscheduler.size(); i++){
        //   JsonObject detailsTemp = carscheduler[i]->GetDetails();
        //   cout<<detailsTemp["name"]<<endl;
        // }
        // cout << "I m here" << endl;
        //cout<<nearestEntity->Getbroken()<<endl;
        //cout<<carscheduler.size()<<endl;
        // cout << nearestEntity->GetDestination().x << "," << nearestEntity->GetDestination().y << "," << nearestEntity->GetDestination().z << endl;
        nearestEntity = NULL;
        color = "None"; // resets color when trip is complete
        
        // nearestEntity->Setbroken(100);
        // nearestEntity->Setstop(0);
        //carscheduler.erase(carscheduler.begin());
        // cout << nearestEntity->Getbroken() << endl;
        // cout << nearestEntity->Getstop() << endl;
    }
  }
  Rotate(-3.1415926/4);
}

void RPcar::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void RPcar::Jump(double height) {
  if(goUp){
    position.y += height;
    jumpHeight += height;
    if(jumpHeight > 5){
      goUp = false;
    }
  } else {
    position.y -= height;
    jumpHeight -= height;
    if(jumpHeight < 0){
      goUp = true;
    }
  }
}
