#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Car.h"

#include <vector>
/**
* @brief this class is for CarFactory
*/
class CarFactory : public IEntityFactory {
  public:
    /**
     * @brief Destructor.
     */
    virtual ~CarFactory() {}
    /**
     * @brief Create Entity
     * 
     * @param[in] entity
     */
    IEntity* CreateEntity(JsonObject& entity);
}; //end class

#endif