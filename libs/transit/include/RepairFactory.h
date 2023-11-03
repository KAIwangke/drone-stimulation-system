#ifndef Repair_FACTORY_H_
#define Repair_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Repair.h"

#include <vector>
/**
 * @brief this class is for the repairFactory
 */
class RepairFactory : public IEntityFactory {
  public:
    /**
    * @brief Destructor.
    */
    virtual ~RepairFactory() {}
    /**
    * @brief Create Entity.
    * @param entity
    */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif