#ifndef BEELINE_H_
#define BEELINE_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
public:
    /**
    * @brief Parameter constructor.
    * @param[in] position
    * @param[in] destination
    */
    BeelineStrategy(Vector3 position, Vector3 destination);
    /**
     * @brief Destructor.
    */
    ~BeelineStrategy();
    /**
    * @brief Move the entity with beeline
    * @param[in] entity
    * @param[in] dt
    */
    void Move(IEntity* entity, double dt);
    /**
    * @brief Check whether it is completed the trip
    */
    bool IsCompleted();

private:
    Vector3 position;   //!< position
    Vector3 destination;    //!< destination
}; //end class
#endif // BEELINE_H_