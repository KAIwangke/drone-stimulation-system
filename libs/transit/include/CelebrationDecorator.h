#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_
/**
 * include
 */
#include <vector>
#include "IStrategy.h"

/**
 * @brief this class is use to do the Celebration, but it is useless now
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] strategy_
  */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
    * @brief Move the entity
    * @param[in] entity
    * @param[in] dt
    */
  void Move(IEntity *entity, double dt);
  /**
  * @brief Check whether it is completed the celebration
  */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_