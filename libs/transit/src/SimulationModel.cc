#include "SimulationModel.h"
#include "DroneFactory.h"
#include "RobotFactory.h"
#include "CarFactory.h"
#include "RPcarFactory.h"
#include "RepairFactory.h"
#include "HelicopterFactory.h"
#include "DataCollection.h"
#include <iostream>
#include <ctime>
using namespace std;

SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  compFactory = new CompositeFactory();
  AddFactory(new DroneFactory());
  AddFactory(new RobotFactory());
  AddFactory(new CarFactory());
  AddFactory(new RepairFactory());
  AddFactory(new RPcarFactory());
  AddFactory(new HelicopterFactory());
}

void SimulationModel::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  std::string name = entity["name"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;

  IEntity* myNewEntity = compFactory->CreateEntity(entity);
  myNewEntity->SetGraph(graph);
  
  // Call AddEntity to add it to the view
  controller.AddEntity(*myNewEntity);
  entities.push_back(myNewEntity);
}

/// Schedules a trip for an object in the scene
void SimulationModel::ScheduleTrip(JsonObject& details) {
  std::string name = details["name"];
  JsonArray start = details["start"];
  JsonArray end = details["end"];
  std::cout << name << ": " << start << " --> " << end << std::endl;

  for (auto entity : entities) {  // Add the entity to the scheduler
    
    JsonObject detailsTemp = entity->GetDetails();
    std::string nameTemp = detailsTemp["name"];
    std::string typeTemp = detailsTemp["type"];
    // std :: cout << nameTemp << ": " << typeTemp << std::endl;
    if (name.compare(nameTemp) == 0 && typeTemp.compare("robot") == 0 && entity->GetAvailability()) {
      std::string strategyName = details["search"];
      entity->SetStrategyName(strategyName);
      entity->SetDestination(Vector3(end[0], end[1], end[2]));
      scheduler.push_back(entity);
      break;
    } 
  }
  controller.SendEventToView("TripScheduled", details);
}

/// Updates the simulation
void SimulationModel::Update(double dt) {
  if(carscheduler.size() > 0){
    for (int i = 0; i < carscheduler.size(); i++){
      if(carscheduler[i]->Getbroken() != 11 && carscheduler[i]->Getstop() == 0){
        carscheduler.erase(carscheduler.begin() + i);
      }
    }
  }
  
  for (int i = 0; i < entities.size(); i++) {
    //std::cout << "OK" << std::endl;
    //std::cout << entities[i]->Getbroken() << std::endl;
    if (entities[i]->Getbroken()== 11 && entities[i]->Getstop()== 0){
      DataCollection* p = DataCollection::GetInstance();
      JsonObject detailsTemp = entities[i]->GetDetails();
      std::string nameTemp = detailsTemp["name"];
      p->IncreNumCrash();
      time_t rawtime;
      struct tm * timeinfo;
      char buffer[80];
      time (&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
      std::string str(buffer);
      p->Settime(str);
      p->Setcarname(nameTemp);
      p->OutputCsv(p->Getfilename(), entities[i]->GetPosition());


      
      // std::cout << nameTemp << std::endl;
      carscheduler.push_back(entities[i]);
      entities[i]->Setstop(1);
      cout<< nameTemp <<", Crash happend!"<< endl;
    }
    
    if(entities[i]->Getisrpcar() == 1){
      //cout<< "hi1"<< endl;
      entities[i]->Update(dt, carscheduler);
      //cout<< "hi2"<< endl;
    } else {
      entities[i]->Update(dt, scheduler);
    }
    controller.UpdateEntity(*entities[i]);
  }
}

// void SimulationModel::simulationCarBroken(JsonObject& details){

//   for (auto entity : entities) {  // Add the entity to the scheduler
    
//     JsonObject detailsTemp = entity->GetDetails();
//     std::string nameTemp = detailsTemp["name"];
//     std::string typeTemp = detailsTemp["type"];
//     std :: cout << nameTemp << ": " << typeTemp << std::endl;
//     if (name.compare(nameTemp) == 0 && typeTemp.compare("robot") == 0 && entity->GetAvailability()) {
//       std::string strategyName = details["search"];
//       entity->SetStrategyName(strategyName);
//       entity->SetDestination(Vector3(end[0], end[1], end[2]));
//       scheduler.push_back(entity);
//       break;
//     } 
//   }
// }

/// Updates the broken car simulation
// void SimulationModel::Updatebroken(double dt) {
//   for (int i = 0; i < entities.size(); i++) {
//     entities[i]->Update(dt, entities);
//     controller.UpdateEntity(*entities[i]);
//   }
// }

void SimulationModel::AddFactory(IEntityFactory* factory) {
  compFactory->AddFactory(factory);
}
