#include "forma/animation/trackers/position_track.hpp"

namespace Forma{

PositionTrack::PositionTrack(IPositionable& pos)
  : AnimationNode(0.0f), m_target(pos), m_animation(std::make_unique<PositionAnimation>()) {}

void PositionTrack::Start(){
  m_animation->Start();
}

void PositionTrack::Update(float dt){
  if(IsFinished()) return;
  m_animation->Update(dt);
  auto value = m_animation->Value();
  m_target.SetPosition(value);
}

bool PositionTrack::IsFinished() const{
  return m_animation->Finished();
}

float PositionTrack::Duration() const{
  return m_duration;
}

void PositionTrack::SetDuration(float duration){
  For(duration);
}

void PositionTrack::SetEase(EaseType type){
  Using(type);
}

PositionTrack& PositionTrack::From(const Vec2& pos){
  m_animation->SetStartPos(pos);
  return *this;
}

PositionTrack& PositionTrack::To(const Vec2& pos){
  m_animation->SetEndPos(pos);
  return *this;
}

PositionTrack& PositionTrack::For(float duration){
  m_animation->SetDuration(duration);
  return *this;
}

PositionTrack& PositionTrack::Using(EaseType easeType){
  m_animation->SetEaseType(easeType);
  return *this;
}

}
