#include "forma/animation/animation_builder.hpp"
#include "forma/animation/animation_controller.hpp"
#include "forma/animation/groups/parallel.hpp"

namespace Forma{

AnimationBuilder::AnimationBuilder(AnimationController& controller) : m_controller(controller), m_currentGroup(&m_controller.GetSequence()) {}

AnimationBuilder& AnimationBuilder::Start(){
  m_controller.Start();
  return *this;
}

AnimationBuilder& AnimationBuilder::Color(){
  m_currentTrack = &m_currentGroup->AddAndModify<ColorTrack>(m_controller.ColorTarget());
  return *this;
}

AnimationBuilder& AnimationBuilder::Position(){
  m_currentTrack = &m_currentGroup->AddAndModify<PositionTrack>(m_controller.PositionTarget());
  return *this;
}

AnimationBuilder& AnimationBuilder::Then(){
  return *this;
}

AnimationBuilder& AnimationBuilder::While(){
  m_currentGroup = &m_currentGroup->AddAndModify<Parallel>();
  return *this;
}

AnimationBuilder& AnimationBuilder::And(){
  return *this;
}

}
