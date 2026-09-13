#include "forma/animation/animation_controller.hpp"

namespace Forma{

AnimationController::AnimationController(IPositionable *positionable, ISizeable *sizeable, IColorable* colorable) 
  : m_colorable(colorable), m_positionable(positionable), m_sizeable(sizeable){
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

SizeTrack& AnimationController::AddSizeTrack(){
  return m_sequence.AddAndModify<SizeTrack>(*m_sizeable);
}

void AnimationController::SetColorTarget(IColorable& target){
 m_colorable = &target;
}

IPositionable& AnimationController::PositionTarget() const{
  return *m_positionable;
}

ISizeable& AnimationController::SizeTarget() const{
  return *m_sizeable;
}

IColorable& AnimationController::ColorTarget() const{
  return *m_colorable;
}

Sequence& AnimationController::GetSequence(){
  return m_sequence;
}

}
