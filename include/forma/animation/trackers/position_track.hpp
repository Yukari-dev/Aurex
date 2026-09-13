#pragma once
#include "forma/animation/animation_node.hpp"
#include "forma/animation/attributes/position_animation.hpp"
#include "forma/animation/trackers/track.hpp"
#include "forma/interfaces/positionable.hpp"
#include "types/types.hpp"
#include <memory>
#include <stdexcept>
#include <typeinfo>

namespace Forma{

class PositionTrack : public AnimationNode, public ITrackable{
public:
  explicit PositionTrack(IPositionable& positionable);

  void Start() override;
  void Update(float dt) override;
  bool IsFinished() const override;
  float Duration() const override;

  PositionTrack& From(const Vec2& pos);
  PositionTrack& To(const Vec2& pos);
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
  void SetDuration(float duration) override;
  void SetEase(EaseType easeType) override;
private:
  IPositionable& m_target;
  bool m_hasDefaultValue{true};
  std::unique_ptr<PositionAnimation> m_animation;
};

}
