#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/// @brief A class Represents a drone in a physical system.
class Drone : public IEntity {
 public:
  // Drones are created with a name
  /**
  * @brief Parameter constructor.
  * @param[in] obj
  */
  Drone(JsonObject& obj);
  // Destructor
  /**
  * @brief Destructor.
  */
  ~Drone();
  /**
  * @brief Get the speed of Drone
  * @return the value of speed.
  */
  float GetSpeed() const { return speed; }

  // Gets the drone position
  /**
  * @brief Gets the drone position
  * @return return the position of the Drone.
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the Direction of the Drone.
  * @return return the direction of the Drone.
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the Destination of the Drone
  * @return return the destination for Drone
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get the color of the Drone
  * @return return the color Drone
  */
  std::string GetColor() const { return color; }
  /**
  * @brief Get the details of the Drone
  * @return return the details Drone
  */
  JsonObject GetDetails() const { return details; }
  /**
  * @brief Get the available of the Drone
  * @return return the available Drone
  */
  bool GetAvailability() const { return available; }
  /**
  * @brief Get the entity in scheduler
  * @param scheduler
  */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  // Updates the drone's position
  /**
  * @brief Update the details for entitys iin scheduler
  * @param dt
  * @param scheduler
  */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
  * @brief Set the position for Drone
  * @param pos_
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the drone's direction
  /**
  * @brief Set the Direction for Drone
  * @param dir_
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
  * @brief Set the Destination for Drone
  * @param des_
  */
  void SetDestination(Vector3 des_) { destination = des_; }

  // Rotates a drone
  /**
  * @brief Rotate the drone with angles
  * @param angle
  */
  void Rotate(double angle);
  /**
  * @brief make the drone jump with the heigth
  * @param height
  */
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  /**
  * @brief Parameter constructor.
  * @param drone
  */
  Drone(const Drone& drone) = delete;
  /**
  * @brief operator of drone
  * @param drone
  */
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details; //!< details
  Vector3 position; //!< position
  Vector3 direction;  //!< direction
  std::string color = "None"; // None means default color //!< color
  float jumpHeight = 0; //!< jumpHeight
  bool goUp = true; // jump helper  //!< goUp
  Vector3 destination;  //!< destination
  float speed;  //!< speed
  bool available; //!< available
  bool pickedUp;  //!< pickedUp
  std::string strategyName; //!< strategyName
  IEntity* nearestEntity = NULL;  //!< nearestEntity
  IStrategy* toTargetPosStrategy = NULL;  //!< toTargetPosStrategy
  IStrategy* toTargetDestStrategy = NULL; //!< toTargetDestStrategy
};

#endif
