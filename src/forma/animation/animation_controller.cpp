#include "forma/animation/animation_controller.hpp"

namespace Forma{

AnimationController::AnimationController(IPositionable *positionable, IColorable* colorable) : m_colorable(colorable), m_positionable(positionable) {
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

PositionTrack& AnimationController::AddPositionTrack(){
  return m_sequence.AddAndModify<PositionTrack>(*m_positionable);
}

void AnimationController::SetColorTarget(IColorable& target){
 m_colorable = &target;
}

IPositionable& AnimationController::PositionTarget() const{
  return *m_positionable;
}

IColorable& AnimationController::ColorTarget() const{
  return *m_colorable;
}

Sequence& AnimationController::GetSequence(){
  return m_sequence;
}

}
