#include "forma/animation/animation_builder.hpp"
#include "forma/animation/animation_controller.hpp"

namespace Forma{

AnimationBuilder::AnimationBuilder(AnimationController& controller) 
: m_controller(controller), m_sequence(&controller.GetSequence()) {}

void AnimationBuilder::Start(){
  m_controller.Start();
}

void AnimationBuilder::SetColorTarget(IColorable& target){
  m_controller.SetColorTarget(target);
}

ColorTrack& AnimationBuilder::Color(){
  return m_sequence->AddAndModify<ColorTrack>(m_controller.ColorTarget());
}

AnimationBuilder& AnimationBuilder::Then(){
  return *this;
}

}
