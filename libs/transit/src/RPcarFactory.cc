#include "RPcarFactory.h"

IEntity* RPcarFactory::CreateEntity(JsonObject& entity){
  std::string type = entity["type"];
  if(type.compare("rpcar") == 0){
    std::cout << "RPcar Created" << std::endl;
    return new RPcar(entity);
  }
  return nullptr;
}