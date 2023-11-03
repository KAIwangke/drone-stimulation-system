#ifndef Repair_H
#define Repair_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"
/// @brief A class Represents a repair station in a physical system.
class Repair : public IEntity {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] obj
  */
  Repair(JsonObject& obj);
  /**
  * @brief Destructor.
  */
  ~Repair() override = default;
  /**
  * @brief Gets the repair position
  * @return return the position of the repair.
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the Direction of the repair.
  * @return return the direction of the repair.
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the Destination of the repair
  * @return return the destination for repair
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get the details of the repair
  */
  JsonObject GetDetails() const override;
  /**
  * @brief Get the speed of the repair
  * @return speed
  */
  float GetSpeed() const { return speed; }
  /**
  * @brief Set the position for repair
  * @param pos_
  */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
  * @brief Set the Direction for repair
  * @param dir_
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
  * @brief Set the Destination for repair
  * @param des_
  */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
  * @brief Rotate the repair with angles
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
  * @brief Generate random number with in range
  * @param Min
  * @param Max
  */
  float Random(float Min, float Max);
  /**
  * @brief Set the new Destination for repair
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

#endif  // Repair_H
