#include "forma/animation/attributes/color_animation.hpp"
#include <math.hpp>

namespace Forma{

void ColorAnimation::Start(){
  m_elapsed = 0.0f;
  m_running = true;
  m_finalColor = m_startColor;
}

void ColorAnimation::Update(float dt){
  if(!m_running) return;

  if(m_elapsed < m_delay){
    m_elapsed += dt;
    return;
  }

  m_elapsed += dt;
  const float animationTime = m_elapsed - m_delay;
  if(animationTime <= 0)
    return;
  float progress = animationTime / m_duration;
  if(progress >= 1.0f){
    progress = 1.0f;
    m_elapsed = m_duration;
    m_running = false;
  }
  m_finalColor = EaseLerp(m_startColor.ToGlm(), m_endColor.ToGlm(), progress, m_easeType);
}

bool ColorAnimation::Finished() const{
  return !m_running;
}

Color ColorAnimation::Value() const {
  return m_finalColor;
}

ColorAnimation& ColorAnimation::SetStartColor(Color color){
  m_startColor = color;
  return *this;
}

ColorAnimation& ColorAnimation::SetEndColor(Color color){
  m_endColor = color;
  return *this;
}

ColorAnimation& ColorAnimation::SetEaseType(EaseType ease){
  m_easeType = ease;
  return *this;
}

}
