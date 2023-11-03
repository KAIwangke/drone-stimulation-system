#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

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
class DijkstraStrategy : public IStrategy {
public:
/**
    * @brief Parameter constructor.
    * @param[in] position
    * @param[in] destination
    * @param[in] graph
    */
    DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    /**
     * @brief Destructor.
    *
    */
    ~DijkstraStrategy();
    /**
    * @brief Move the entity with astar
    * @param[in] entity
    * @param[in] dt
    */
    void Move(IEntity* entity, double dt);
    /**
    * @brief Check whether it is completed the trip
    */
    bool IsCompleted();

private:
    std::vector<std::vector<float>> path;   //!< path in the map
    int currentIndex;   //!< currentIndex
    int maxIndex;   //!< maxIndex
}; //end class
#endif // Dijkstra_STRATEGY_H_