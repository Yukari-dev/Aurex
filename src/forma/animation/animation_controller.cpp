#include "forma/animation/animation_controller.hpp"

namespace Forma{

AnimationController::AnimationController(IColorable* colorable) : m_colorable(colorable) {
  if(m_colorable)
    m_colorTrack = std::make_unique<ColorTrack>(*m_colorable);
}

void AnimationController::Start(){
  if(m_colorTrack)
    m_colorTrack->Start();
  for(auto& child : m_children)
    child->Start();
}

void AnimationController::Update(float dt){
  if(m_colorTrack)
    m_colorTrack->Update(dt);
}

void AnimationController::SetColorTarget(IColorable& target){
  m_colorable = &target;
  m_colorTrack = std::make_unique<ColorTrack>(target);
}

ColorTrack& AnimationController::Color(){
  return *m_colorTrack;
}

}
