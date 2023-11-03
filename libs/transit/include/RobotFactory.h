#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>
/**
* @brief this class is for RobotFactory
*/
class RobotFactory : public IEntityFactory {
  public:
    /**
     * @brief Create Entity
     * 
     * @param[in] entity
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif