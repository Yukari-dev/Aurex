#include "forma/animation/animation_controller.hpp"

namespace Forma{

AnimationController::AnimationController(IColorable* colorable) : m_colorable(colorable) {
  if(m_colorable)
    m_colorTrack = std::make_unique<ColorTrack>(*m_colorable);
}

void AnimationController::Start(){
  m_sequence.Start();
}

void AnimationController::Update(float dt){
  m_sequence.Update(dt);
}

void AnimationController::SetColorTarget(IColorable& target){
 m_colorable = &target;
}

ColorTrack& AnimationController::Color(){
  return *m_colorTrack;
}

IColorable& AnimationController::ColorTarget() const{
  return *m_colorable;
}

Sequence& AnimationController::GetSequence(){
  return m_sequence;
}

}
