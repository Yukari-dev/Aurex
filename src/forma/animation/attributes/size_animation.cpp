#include "forma/animation/attributes/size_animation.hpp"
#include <math.hpp>

namespace Forma{

void SizeAnimation::Start(){
  m_elapsed = 0.0f;
  m_running = true;
  m_finalSize = m_startSize;
}

void SizeAnimation::Update(float dt){
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
  m_finalSize = EaseLerp(m_startSize.ToGlm(), m_endSize.ToGlm(), progress, m_easeType);
}

bool SizeAnimation::Finished() const{
  return !m_running;
}

Size SizeAnimation::Value() const {
  return m_finalSize;
}

SizeAnimation& SizeAnimation::SetStartSize(Size pos){
  m_startSize = pos;
  return *this;
}

SizeAnimation& SizeAnimation::SetEndSize(Size pos){
  m_endSize = pos;
  return *this;
}

SizeAnimation& SizeAnimation::SetEaseType(EaseType ease){
  m_easeType = ease;
  return *this;
}

}
