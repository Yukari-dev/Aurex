#include "aurex/animation/animation_builder.hpp"
#include "aurex/animation/animation_controller.hpp"
#include "aurex/animation/attributes/delay.hpp"
#include "aurex/animation/groups/parallel.hpp"
#include "aurex/animation/trackers/opacity_track.hpp"

namespace Aurex{

AnimationBuilder::AnimationBuilder(AnimationController& controller) : m_controller(controller), m_currentGroup(&m_controller.GetSequence()) {}

AnimationBuilder& AnimationBuilder::Start(){
  m_controller.Start();
  return *this;
}

AnimationBuilder& AnimationBuilder::Opacity(){
  m_currentTrack = &m_currentGroup->AddAndModify<OpacityTrack>(m_controller.ColorTarget());
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

AnimationBuilder& AnimationBuilder::Size(){
  m_currentTrack = &m_currentGroup->AddAndModify<SizeTrack>(m_controller.SizeTarget());
  return *this;
}

AnimationBuilder& AnimationBuilder::Delay(float duration){
  m_currentGroup->Add<Aurex::Delay>(duration);
  return *this;
}

AnimationBuilder& AnimationBuilder::Then(){
  m_currentGroup = &m_controller.GetSequence();
  m_currentTrack = nullptr;
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
