#include "aurex/animation/trackers/opacity_track.hpp"

namespace Aurex{

OpacityTrack::OpacityTrack(IColorable& color)
  : AnimationNode(0.0f), m_target(color), m_animation(std::make_unique<OpacityAnimation>()) {}

void OpacityTrack::Start(){
  if(m_hasDefaultValue)
    m_animation->SetStartOpacity(m_target.Opacity());
  m_animation->Start();
}

void OpacityTrack::Update(float dt){
  if(IsFinished()) return;
  m_animation->Update(dt);
  auto value = m_animation->Value();
  m_target.SetOpacity(value);
}

bool OpacityTrack::IsFinished() const{
  return m_animation->Finished();
}

float OpacityTrack::Duration() const{
  return m_duration;
}

void OpacityTrack::SetDelay(float delay){
  Delay(delay);
}

void OpacityTrack::SetDuration(float duration){
  For(duration);
}

void OpacityTrack::SetEase(EaseType type){
  Using(type);
}

OpacityTrack& OpacityTrack::From(const float& opacity){
  m_animation->SetStartOpacity(opacity);
  m_hasDefaultValue = false;
  return *this;
}

OpacityTrack& OpacityTrack::To(const float& opacity){
  m_animation->SetEndOpacity(opacity);
  return *this;
}

OpacityTrack& OpacityTrack::Delay(float delay){
  m_animation->SetDelay(delay);
  return *this;
}

OpacityTrack& OpacityTrack::For(float duration){
  m_animation->SetDuration(duration);
  return *this;
}

OpacityTrack& OpacityTrack::Using(EaseType easeType){
  m_animation->SetEaseType(easeType);
  return *this;
}

}
