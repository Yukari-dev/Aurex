#pragma once
#include "forma/animation/animation_node.hpp"

namespace Forma{

class Delay : public AnimationNode{
public:
  Delay(float duration) : AnimationNode(duration) {}
  void Start() override;
  void Update(float ft) override;
};

}
