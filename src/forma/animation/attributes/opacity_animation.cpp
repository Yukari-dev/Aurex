#include "forma/animation/attributes/opacity_animation.hpp"
#include <math.hpp>

namespace Forma{

void OpacityAnimation::Start(){
  m_elapsed = 0.0f;
  m_running = true;
  m_finalOpacity = m_startOpacity;
}

void OpacityAnimation::Update(float dt){
  if(!m_running) return;

  if(m_elapsed < m_delay){
    m_elapsed += dt;
    return;
  }

  m_elapsed += dt;

  const float animationTime = m_elapsed - m_delay;
  float progress = animationTime / m_duration;
  if(progress >= 1.0f){
    progress = 1.0f;
    m_elapsed = m_duration;
    m_running = false;
  }
  m_finalOpacity = EaseLerp(m_startOpacity, m_endOpacity, progress, m_easeType);
}

bool OpacityAnimation::Finished() const{
  return !m_running;
}

float OpacityAnimation::Value() const {
  return m_finalOpacity;
}

OpacityAnimation& OpacityAnimation::SetStartOpacity(float opacity){
  m_startOpacity = opacity;
  return *this;
}

OpacityAnimation& OpacityAnimation::SetEndOpacity(float opacity){
  m_endOpacity = opacity;
  return *this;
}

OpacityAnimation& OpacityAnimation::SetEaseType(EaseType ease){
  m_easeType = ease;
  return *this;
}

}
