#include "forma/animation/animation_controller.hpp"

namespace Forma{

AnimationController::AnimationController(IColorable* colorable) : m_colorable(colorable) {
}

void AnimationController::Start(){
  m_sequence.Start();
}

void AnimationController::Update(float dt){
  m_sequence.Update(dt);
}

AnimationBuilder AnimationController::Animation(){
  return AnimationBuilder(*this);
}

ColorTrack& AnimationController::AddColorTrack(){
  return m_sequence.AddAndModify<ColorTrack>(*m_colorable);
}

void AnimationController::SetColorTarget(IColorable& target){
 m_colorable = &target;
}

IColorable& AnimationController::ColorTarget() const{
  return *m_colorable;
}

Sequence& AnimationController::GetSequence(){
  return m_sequence;
}

}
