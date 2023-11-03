#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"
/**
* @brief this class is for Composite all the Factory
*/
class CompositeFactory : public IEntityFactory {
  public:
    /**
    * @brief Parameter constructor.
    * @param[in] entity
    */
    IEntity* CreateEntity(JsonObject& entity);
    /**
    * @brief Add a Factory for a entity
    * @param[in] factoryEntity
    */
    void AddFactory(IEntityFactory* factoryEntity);
    /**
     * @brief Destructor.
    */
    virtual ~CompositeFactory();

  private:
    std::vector<IEntityFactory*> componentFactories;  //!< componentFactories
};  //end class

#endif