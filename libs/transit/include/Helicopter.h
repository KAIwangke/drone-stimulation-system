#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"
/// @brief A class Represents a Helicopter in a physical system.
class Helicopter : public IEntity {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] obj
  */
  Helicopter(JsonObject& obj);
  /**
  * @brief Destructor.
  */
  ~Helicopter() override = default;
  /**
  * @brief Gets the helicopter position
  * @return return the position of the helicopter.
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the Direction of the helicopter.
  * @return return the direction of the helicopter.
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the Destination of the helicopter
  * @return return the destination for helicopter
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get the details of the helicopter
  * @return return the details helicopter
  */
  JsonObject GetDetails() const override;
  /**
  * @brief Get the speed of helicopter
  * @return the value of speed.
  */
  float GetSpeed() const { return speed; }
   /**
  * @brief Set the position for helicopter
  * @param pos_
  */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
  * @brief Set the Direction for helicopter
  * @param dir_
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
  * @brief Set the Destination for helicopter
  * @param des_
  */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
  * @brief Rotate the helicopter with angles
  * @param angle
  */
  void Rotate(double angle);
  /**
  * @brief Update the details for entitys iin scheduler
  * @param dt
  * @param scheduler
  */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
  * @brief Generate random number
  * @param Min
  * @param Max
  */
  float Random(float Min, float Max);
  /**
  * @brief Set the Destination for helicopter
  */
  void SetNewDestination();

 private:
  JsonObject details; //!< details
  Vector3 position; //!< position
  Vector3 direction;  //!< direction
  Vector3 destination;  //!< destination
  IStrategy* strategy = NULL; //!< strategy
  float speed;  //!< speed
};

#endif  // HELICOPTER_H
