#ifndef CAR_H
#define CAR_H

#include <vector>
#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"
/**
* @brief this class is for Car entity
*/
class Car : public IEntity {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] obj
  */
  Car(JsonObject& obj);
  /**
  * @brief Destructor.
  *
  */
  ~Car() override = default;
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
   * @brief Set position of car
   * @param pos_
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Set Direction of car
   * @param dir_
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Set Destination of car
   * @param des_
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotate the car with angles
   * @param angle
   */
  void Rotate(double angle);
  /**
   * @brief Update the details of the car
   * @param dt
   * @param scheduler
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Generate a random number
   * @param Min
   * @param Max
   */
  float Random(float Min, float Max);
  /**
   * @brief Get broken value of the car
   *
   * @return broken
   */ 
  int Getbroken() { return broken; }
  /**
   * @brief Set the number of broken for car
   * @param tmp
   */
  void Setbroken(int tmp) {broken = tmp;}

  /**
   * @brief Get the strategy name of car
   *
   * @return strategyName
   */ 
  std::string GetStrategyName() {return strategyName;}

  /**
   * @brief Set the Destination for car
   *
   */
  void SetNewDestination();

 private:
  JsonObject details;    //!< car details
  Vector3 position;      //!< car position
  Vector3 direction;     //!< car direction
  Vector3 destination;   //!< car destination
  IStrategy* strategy = NULL;     //!< car strategy
  float speed;           //!< car speed
  int stop = 0;          //!< car, whether in the broken car list
  int broken = 100;      //!< car, whetehr crash happend
  std::string strategyName; //!< car strategyName
}; //end class

#endif  // CAR_H
