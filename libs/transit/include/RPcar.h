#ifndef RPcar_H_
#define RPcar_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a RPcar in a physical system.
// RPcars move using euler integration based on a specified
// velocity and direction.
/// @brief A class Represents a repair car in a physical system.
class RPcar : public IEntity {
 public:
  // RPcars are created with a name
  /**
  * @brief Parameter constructor.
  * @param[in] obj
  */
  RPcar(JsonObject& obj);
  // Destructor
  /**
  * @brief Destructor.
  */
  ~RPcar();
  /**
  * @brief Get the speed of Rpcar
  * @return the value of speed.
  */
  float GetSpeed() const { return speed; }

  // Gets the RPcar position
  /**
  * @brief Gets the Rpcar Rpcar
  * @return return the position of the Rpcar.
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the Direction of the Rpcar.
  * @return return the direction of the Rpcar.
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the Destination of the Rpcar
  * @return return the destination for Rpcar
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get the color of the Rpcar
  * @return return the color Rpcar
  */
  std::string GetColor() const { return color; }
  /**
  * @brief Get the details of the Rpcar
  * @return return the details Rpcar
  */
  JsonObject GetDetails() const { return details; }
  /**
  * @brief Get the available of the Rpcar
  * @return return the available Rpcar
  */
  bool GetAvailability() const { return available; }
  /**
  * @brief Get the entity in scheduler
  * @param scheduler
  */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  // Updates the RPcar's position
  /**
  * @brief Update the details for entitys iin scheduler
  * @param dt
  * @param scheduler
  */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
  * @brief Set the position for Rpcar
  * @param pos_
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the RPcar's direction
  /**
  * @brief Set the Direction for Rpcar
  * @param dir_
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
  * @brief Set the Destination for Rpcar
  * @param des_
  */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
  * @brief Get the isrpcar for Rpcar
  * @param des_
  */
  int Getisrpcar(){return isrpcar;}

  // Rotates a RPcar
  /**
  * @brief Rotate the Rpcar with angles
  * @param angle
  */
  void Rotate(double angle);
  /**
  * @brief make the Rpcar jump with the heigth
  * @param height
  */
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that RPcars cannot be coppied.
  RPcar(const RPcar& RPcar) = delete;
  RPcar& operator=(const RPcar& RPcar) = delete;

 private:
  JsonObject details; //!< details
  Vector3 position; //!< position
  Vector3 direction;  //!< direction
  std::string color = "None"; // None means default color //!< color
  float jumpHeight = 0; //!< jumpHeight
  bool goUp = true; // jump helper //!< goUp
  Vector3 destination;  //!< destination
  float speed;  //!< speed
  bool available; //!< available
  bool pickedUp;  //!< pickedUp
  std::string strategyName; //!< strategyName
  IEntity* nearestEntity = NULL;  //!< nearestEntity
  IStrategy* toTargetPosStrategy = NULL;  //!< toTargetPosStrategy
  IStrategy* toTargetDestStrategy = NULL; //!< toTargetDestStrategy
  int isrpcar;  //!< isrpcar, check whether this entity is Rpcar
};

#endif
