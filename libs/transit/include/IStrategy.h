#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;
/**
 * @brief this class is for the IStrategy,which is abstract class for other strategy.
 */
class IStrategy {
    public:
        /**
        * @brief Move the entity with beeline
        * @param[in] entity
        * @param[in] dt
        */
        virtual void Move(IEntity* entity, double dt) = 0;
        /**
        * @brief Check whether it is completed the trip
        */
        virtual bool IsCompleted() = 0;
    protected:
        // IGraph object to be used in the simulation.
        const IGraph* graph;    //!< graph
}; //close class 

#endif // ISTRATEGY_H_