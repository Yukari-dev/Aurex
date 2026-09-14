#pragma once
#include "aurex/animation/animation_node.hpp"

namespace Aurex{

class Delay : public AnimationNode{
public:
  Delay(float duration) : AnimationNode(duration) {}
  void Start() override;
  void Update(float ft) override;
};

}
