#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>
/**
 * @brief this class is for the DroneFactory
 */
class DroneFactory : public IEntityFactory {
  public:
    /**
    * @brief Destructor.
    */
    virtual ~DroneFactory() {}
    /**
    * @brief Create Entity.
    * @param entity
    */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif