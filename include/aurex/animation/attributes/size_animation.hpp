#pragma once
#include "aurex/animation/animation_node.hpp"
#include "types/types.hpp"
#include <math.hpp>

namespace Aurex{

using namespace Axiom;

class SizeAnimation : public AnimationNode{
public:
  SizeAnimation() : AnimationNode(0.0f) {}

  void Start() override;
  void Update(float dt) override;
  bool Finished() const;

  SizeAnimation& SetStartSize(Size size);
  SizeAnimation& SetEndSize(Size size);
  SizeAnimation& SetEaseType(EaseType type);

  Size Value() const;
private:
  Size m_finalSize{};
  Size m_startSize{};
  Size m_endSize{};
  EaseType m_easeType{};
};

}
