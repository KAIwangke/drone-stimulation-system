#ifndef RPcar_FACTORY_H_
#define RPcar_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RPcar.h"

#include <vector>
/**
 * @brief this class is for the RPcarFactory
 */
class RPcarFactory : public IEntityFactory {
  public:
    /**
    * @brief Destructor.
    */
    virtual ~RPcarFactory() {}
    /**
    * @brief Create Entity.
    * @param entity
    */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif