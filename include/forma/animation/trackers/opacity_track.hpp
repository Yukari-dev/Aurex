#pragma once
#include "forma/animation/animation_node.hpp"
#include "forma/animation/attributes/opacity_animation.hpp"
#include "forma/animation/trackers/track.hpp"
#include "forma/interfaces/colorable.hpp"
#include <memory>
#include <stdexcept>
#include <typeinfo>

namespace Forma{

class OpacityTrack : public AnimationNode, public ITrackable{
public:
  explicit OpacityTrack(IColorable& colorable);

  void Start() override;
  void Update(float dt) override;
  bool IsFinished() const override;
  float Duration() const override;

  OpacityTrack& From(const float& opacity);
  OpacityTrack& To(const float& opacity);
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
  void SetDuration(float duration) override;
  void SetEase(EaseType easeType) override;
private:
  IColorable& m_target;
  bool m_hasDefaultValue{true};
  std::unique_ptr<OpacityAnimation> m_animation;
};

}
