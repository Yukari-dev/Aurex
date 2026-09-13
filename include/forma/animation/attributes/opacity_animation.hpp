#pragma once
#include "forma/animation/animation_node.hpp"
#include <math.hpp>

namespace Forma{

using namespace Axiom;

class OpacityAnimation : public AnimationNode{
public:
  OpacityAnimation() : AnimationNode(0.0f) {}

  void Start() override;
  void Update(float dt) override;
  bool Finished() const;

  OpacityAnimation& SetStartOpacity(float color);
  OpacityAnimation& SetEndOpacity(float color);
  OpacityAnimation& SetEaseType(EaseType ease);

  float Value() const;

private:
  float m_finalOpacity{};
  float m_startOpacity{};
  float m_endOpacity{};
  EaseType m_easeType{};
};

}
