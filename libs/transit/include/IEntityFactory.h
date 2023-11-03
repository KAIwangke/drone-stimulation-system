#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"
/**
 * @brief this class is for the IEntityFactory
 */
class IEntityFactory {
  public:
    /**
    * @brief Destructor.
    */
    virtual ~IEntityFactory() {}
    /**
    * @brief Create Entity.
    * @param entity
    */
    virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif