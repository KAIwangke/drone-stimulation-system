#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include <vector>
#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief this class is use to do the Jump celebration, but it is useless now
 */
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
  * @brief Parameter constructor.
  * @param[in] strategy_
  */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
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

#endif  // JUMP_DECORATOR_H_