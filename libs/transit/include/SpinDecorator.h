#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief this class is use to do the spin celebration, but it is useless now
 */
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] strategy_
  */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
  * @brief Check whether it is completed the celebration
  */
  bool IsCompleted();
  /**
    * @brief Move the entity
    * @param[in] entity
    * @param[in] dt
    */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // SPIN_DECORATOR_H_