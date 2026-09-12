#include "forma/animation/animation_builder.hpp"
#include "forma/animation/animation_controller.hpp"

namespace Forma{

AnimationBuilder::AnimationBuilder(AnimationController& controller) : m_controller(controller) {}

AnimationBuilder& AnimationBuilder::Start(){
  m_controller.Start();
  return *this;
}

AnimationBuilder& AnimationBuilder::Color(){
  m_currentTrack = &m_controller.AddColorTrack();
  return *this;
}

AnimationBuilder& AnimationBuilder::Then(){
  return *this;
}

}
