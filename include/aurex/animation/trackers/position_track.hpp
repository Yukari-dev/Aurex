#pragma once
#include "aurex/animation/animation_node.hpp"
#include "aurex/animation/attributes/position_animation.hpp"
#include "aurex/animation/trackers/track.hpp"
#include "aurex/interfaces/positionable.hpp"
#include "types/types.hpp"
#include <memory>
#include <stdexcept>
#include <typeinfo>

namespace Aurex{

class PositionTrack : public AnimationNode, public ITrackable{
public:
  explicit PositionTrack(IPositionable& positionable);

  void Start() override;
  void Update(float dt) override;
  bool IsFinished() const override;
  float Duration() const override;

  PositionTrack& From(const Vec2& pos);
  PositionTrack& To(const Vec2& pos);
  PositionTrack& Delay(float delay);
  PositionTrack& For(float duration);
  PositionTrack& Using(EaseType easeType);

  void SetFrom(const void* value, const std::type_info& type) override{
    if(type != typeid(Vec2))
      throw std::invalid_argument("PositionTrack expect Color.");
    From(*static_cast<const Vec2*>(value));
  }
  void SetTo(const void* value, const std::type_info& type) override{
    if(type != typeid(Vec2))
      throw std::invalid_argument("PositionTrack expect Color.");
    To(*static_cast<const Vec2*>(value));
  }
  void SetDelay(float delay) override;
  void SetDuration(float duration) override;
  void SetEase(EaseType easeType) override;
private:
  IPositionable& m_target;
  bool m_hasDefaultValue{true};
  std::unique_ptr<PositionAnimation> m_animation;
};

}
