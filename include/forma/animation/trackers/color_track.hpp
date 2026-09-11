#pragma once
#include "forma/animation/attributes/color_animation.hpp"
#include "forma/interfaces/colorable.hpp"
#include "types/types.hpp"
#include <memory>

namespace Forma{

class ColorTrack{
public:
  explicit ColorTrack(IColorable& colorable);

  void Start();
  void Update(float dt);
  bool Finished() const;

  ColorTrack& From(const Color& color);
  ColorTrack& To(const Color& color);
  ColorTrack& For(float duration);
  ColorTrack& Using(EaseType easeType);
private:
  IColorable& m_target;
  std::unique_ptr<ColorAnimation> m_animation;
};

}
