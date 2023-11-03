#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/**
* @brief this class is for Robot entity
*/
class Robot : public IEntity {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] obj
  */
  Robot(JsonObject& obj);
  /**
  * @brief Destructor.
  *
  */
  ~Robot() override = default;
  /**
   * @brief Get position
   *
   * @return position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Get direction
   *
   * @return direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Get destination
   *
   * @return destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Get availability of entity
   *
   * @return available
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Get details of entity
   *
   * @return details
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Get speed
   *
   * @return speed
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Get the strategy name of robot
   *
   * @return strategyName
   */ 
  std::string GetStrategyName() {return strategyName;}
  /**
   * @brief Set availability of entity
   *
   * @param choice
   */ 
  void SetAvailability(bool choice);
  /**
   * @brief Set Position of entity
   *
   * @param pos_
  */ 
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Set Direction of entity
   *
   * @param dir_
  */ 
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Set Destination of entity
   *
   * @param des_
  */ 
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Set StrategyName of entity
   *
   * @param strategyName_
  */
  void SetStrategyName(std::string strategyName_) { strategyName = strategyName_;}
  /**
   * @brief Rotate entity by angle
   *
   * @param angle
  */
  void Rotate(double angle);

 private:
  JsonObject details; //!< robot details
  Vector3 position; //!< robot position
  Vector3 direction;  //!< robot direction
  Vector3 destination;  //!< robot destination
  float speed;  //!< robot speed
  bool available; //!< robot available
  std::string strategyName;  //!< robot strategyName
};

#endif  // ROBOT_H
