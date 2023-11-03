#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.
/**
 * @brief this class is use to run the simulation on web
 */
class SimulationModel {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] controller
  */
  SimulationModel(IController& controller);
  /**
  * @brief set the graph for simulation.
  * @param[in] graph
  */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /// Creates an simulation entity
  /**
  * @brief Creates an simulation entity
  * @param[in] entity
  */
  void CreateEntity(JsonObject& entity);

  /// Schedules a trip for an object in the scene
  /**
  * @brief Schedules a trip for an object in the scene
  * @param[in] details
  */
  void ScheduleTrip(JsonObject& details);

  /// Schedules a repair car trip for an object in the scene
  /**
  * @brief Schedules a repair car trip for an object in the scene
  * @param[in] details
  */
  void CARScheduleTrip(JsonObject& details);

  /// Updates the simulation
  /**
  * @brief update each entitys
  * @param[in] dt
  */
  void Update(double dt);

  // Adds a new entity type
  /**
  * @brief Adds a new entity type
  * @param[in] factory
  */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;  //!< controller
  std::vector<IEntity*> entities; //!< entities
  std::vector<IEntity*> scheduler;  //!< scheduler
  std::vector<IEntity*> carscheduler; //!< carscheduler
  const IGraph* graph;  //!< graph
  CompositeFactory* compFactory;  //!< compFactory
};

#endif
