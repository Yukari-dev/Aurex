#pragma once
#include "types/types.hpp"
#include <math.hpp>

namespace Aurex{

class IColorable{
public:
  virtual ~IColorable() = default;
  
  void ColorUpdate(float dt){
    if(m_animatable){
      float factor = 1.0f - std::exp(-m_smoothing * dt);
      m_color = EaseLerp(m_color.ToGlm(), m_targetColor.ToGlm(), factor, m_easeType);
      m_opacity = EaseLerp(m_opacity, m_targetOpacity, factor, m_easeType);
      return;
    }
    m_color = m_targetColor;
    m_opacity = m_targetOpacity;
  }

  void SetAnimatable(bool v) { m_animatable = v; }
  void SetSmoothing(float v) { m_smoothing = v; }
  void SetEaseType(Axiom::EaseType v) { m_easeType = v; }

  Aurex::Color Color() const { return m_color; }
  void SetColor(Aurex::Color color) { m_targetColor = color; }
  float Opacity() const { return m_opacity; }
  void SetOpacity(float opacity) { m_targetOpacity = opacity; }
protected:
  bool m_animatable{false};
  float m_smoothing{1.0f};
  Axiom::EaseType m_easeType{Axiom::EaseType::OutCubic};
  Aurex::Color m_color{};
  Aurex::Color m_targetColor{};

  float m_opacity{1.f};
  float m_targetOpacity{1.0f};
};

}
