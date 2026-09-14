#include "aurex/animation/attributes/position_animation.hpp"
#include <math.hpp>

namespace Aurex{

void PositionAnimation::Start(){
  m_elapsed = 0.0f;
  m_running = true;
  m_finalPos = m_startPos;
}

void PositionAnimation::Update(float dt){
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
  m_finalPos = EaseLerp(m_startPos.ToGlm(), m_endPos.ToGlm(), progress, m_easeType);
}

bool PositionAnimation::Finished() const{
  return !m_running;
}

Vec2 PositionAnimation::Value() const {
  return m_finalPos;
}

PositionAnimation& PositionAnimation::SetStartPos(Vec2 pos){
  m_startPos = pos;
  return *this;
}

PositionAnimation& PositionAnimation::SetEndPos(Vec2 pos){
  m_endPos = pos;
  return *this;
}

PositionAnimation& PositionAnimation::SetEaseType(EaseType ease){
  m_easeType = ease;
  return *this;
}

}
