#pragma once
#include "forma/animation/animation_node.hpp"
#include "types/types.hpp"
#include <math.hpp>

namespace Forma{

using namespace Axiom;

class PositionAnimation : public AnimationNode{
public:
  PositionAnimation() : AnimationNode(0.0f) {}

  void Start() override;
  void Update(float dt) override;
  bool Finished() const;

  PositionAnimation& SetStartPos(Vec2 pos);
  PositionAnimation& SetEndPos(Vec2 pos);
  PositionAnimation& SetEaseType(EaseType type);

  Vec2 Value() const;
private:
  Vec2 m_finalPos{};
  Vec2 m_startPos{};
  Vec2 m_endPos{};
  EaseType m_easeType{};
};

}
