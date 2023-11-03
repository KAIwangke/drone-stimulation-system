#ifndef HELICOPTER_FACTORY_H_
#define HELICOPTER_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"

#include <vector>
/**
 * @brief this class is for the HelicopterFactory
 */
class HelicopterFactory : public IEntityFactory {
  public:
    /**
    * @brief Destructor.
    */
    virtual ~HelicopterFactory() {}
    /**
    * @brief Create Entity.
    * @param entity
    */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif