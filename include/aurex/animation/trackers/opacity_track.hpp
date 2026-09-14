#pragma once
#include "aurex/animation/animation_node.hpp"
#include "aurex/animation/attributes/opacity_animation.hpp"
#include "aurex/animation/trackers/track.hpp"
#include "aurex/interfaces/colorable.hpp"
#include <memory>
#include <stdexcept>
#include <typeinfo>

namespace Aurex{

class OpacityTrack : public AnimationNode, public ITrackable{
public:
  explicit OpacityTrack(IColorable& colorable);

  void Start() override;
  void Update(float dt) override;
  bool IsFinished() const override;
  float Duration() const override;

  OpacityTrack& From(const float& opacity);
  OpacityTrack& To(const float& opacity);
  OpacityTrack& Delay(float delay);
  OpacityTrack& For(float duration);
  OpacityTrack& Using(EaseType easeType);

  void SetFrom(const void* value, const std::type_info& type) override{
    if(type != typeid(float))
      throw std::invalid_argument("OpacityTrack expect Color.");
    From(*static_cast<const float*>(value));
  }
  void SetTo(const void* value, const std::type_info& type) override{
    if(type != typeid(float))
      throw std::invalid_argument("OpacityTrack expect Color.");
    To(*static_cast<const float*>(value));
  }
  void SetDelay(float delay) override;
  void SetDuration(float duration) override;
  void SetEase(EaseType easeType) override;
private:
  IColorable& m_target;
  bool m_hasDefaultValue{true};
  std::unique_ptr<OpacityAnimation> m_animation;
};

}
