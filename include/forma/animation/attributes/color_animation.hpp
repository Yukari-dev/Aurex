#pragma once
#include "forma/animation/animation_node.hpp"
#include "types/types.hpp"
#include <math.hpp>

namespace Forma{

using namespace Axiom;

class ColorAnimation : public AnimationNode{
public:
  ColorAnimation() : AnimationNode(0.0f) {}

  void Start() override;
  void Update(float dt) override;
  bool Finished() const;

  ColorAnimation& SetStartColor(Color color);
  ColorAnimation& SetEndColor(Color color);
  ColorAnimation& SetEaseType(EaseType ease);

  Color Value() const;

private:
  Color m_finalColor{};
  Color m_startColor{};
  Color m_endColor{};
  EaseType m_easeType;
};

}
