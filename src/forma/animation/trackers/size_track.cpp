#include "forma/animation/trackers/size_track.hpp"

namespace Forma{

SizeTrack::SizeTrack(ISizeable& pos)
  : AnimationNode(0.0f), m_target(pos), m_animation(std::make_unique<SizeAnimation>()) {}

void SizeTrack::Start(){
  if(m_hasDefaultValue)
    m_animation->SetStartSize(m_target.Size());
  m_animation->Start();
}

void SizeTrack::Update(float dt){
  if(IsFinished()) return;
  m_animation->Update(dt);
  auto value = m_animation->Value();
  m_target.SetSize(value);
}

bool SizeTrack::IsFinished() const{
  return m_animation->Finished();
}

float SizeTrack::Duration() const{
  return m_duration;
}

void SizeTrack::SetDuration(float duration){
  For(duration);
}

void SizeTrack::SetEase(EaseType type){
  Using(type);
}

SizeTrack& SizeTrack::From(const Size& size){
  m_animation->SetStartSize(size);
  m_hasDefaultValue = false;
  return *this;
}

SizeTrack& SizeTrack::To(const Size& size){
  m_animation->SetEndSize(size);
  return *this;
}

SizeTrack& SizeTrack::For(float duration){
  m_animation->SetDuration(duration);
  return *this;
}

SizeTrack& SizeTrack::Using(EaseType easeType){
  m_animation->SetEaseType(easeType);
  return *this;
}

}
