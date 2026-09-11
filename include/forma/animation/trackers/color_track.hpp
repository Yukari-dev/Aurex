#pragma once
#include "forma/animation/animation_node.hpp"
#include "forma/animation/attributes/color_animation.hpp"
#include "forma/interfaces/colorable.hpp"
#include "types/types.hpp"
#include <memory>

namespace Forma{

class ColorTrack : public AnimationNode{
public:
  explicit ColorTrack(IColorable& colorable);

  void Start() override;
  void Update(float dt) override;
  bool IsFinished() const override;
  float Duration() const override;

  ColorTrack& From(const Color& color);
  ColorTrack& To(const Color& color);
  ColorTrack& For(float duration);
  ColorTrack& Using(EaseType easeType);
private:
  IColorable& m_target;
  std::unique_ptr<ColorAnimation> m_animation;
};

}
