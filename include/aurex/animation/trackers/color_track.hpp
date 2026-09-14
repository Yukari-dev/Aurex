#pragma once
#include "aurex/animation/animation_node.hpp"
#include "aurex/animation/attributes/color_animation.hpp"
#include "aurex/animation/trackers/track.hpp"
#include "aurex/interfaces/colorable.hpp"
#include "types/types.hpp"
#include <memory>
#include <stdexcept>
#include <typeinfo>

namespace Aurex{

class ColorTrack : public AnimationNode, public ITrackable{
public:
  explicit ColorTrack(IColorable& colorable);

  void Start() override;
  void Update(float dt) override;
  bool IsFinished() const override;
  float Duration() const override;

  ColorTrack& From(const Color& color);
  ColorTrack& To(const Color& color);
  ColorTrack& Delay(float delay);
  ColorTrack& For(float duration);
  ColorTrack& Using(EaseType easeType);

  void SetFrom(const void* value, const std::type_info& type) override{
    if(type != typeid(Color))
      throw std::invalid_argument("ColorTrack expect Color.");
    From(*static_cast<const Color*>(value));
  }
  void SetTo(const void* value, const std::type_info& type) override{
    if(type != typeid(Color))
      throw std::invalid_argument("ColorTrack expect Color.");
    To(*static_cast<const Color*>(value));
  }
  void SetDelay(float delay) override;
  void SetDuration(float duration) override;
  void SetEase(EaseType easeType) override;
private:
  IColorable& m_target;
  bool m_hasDefaultValue{true};
  std::unique_ptr<ColorAnimation> m_animation;
};

}
