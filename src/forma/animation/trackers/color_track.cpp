#include "forma/animation/trackers/color_track.hpp"

namespace Forma{

ColorTrack::ColorTrack(IColorable& color)
  : AnimationNode(0.0f), m_target(color), m_animation(std::make_unique<ColorAnimation>()) {}

void ColorTrack::Start(){
  if(m_hasDefaultValue)
    m_animation->SetStartColor(m_target.Color());
  m_animation->Start();
}

void ColorTrack::Update(float dt){
  if(IsFinished()) return;
  m_animation->Update(dt);
  auto value = m_animation->Value();
  m_target.SetColor(value);
}

bool ColorTrack::IsFinished() const{
  return m_animation->Finished();
}

float ColorTrack::Duration() const{
  return m_duration;
}

void ColorTrack::SetDuration(float duration){
  For(duration);
}

void ColorTrack::SetEase(EaseType type){
  Using(type);
}

ColorTrack& ColorTrack::From(const Color& color){
  m_animation->SetStartColor(color);
  m_hasDefaultValue = false;
  return *this;
}

ColorTrack& ColorTrack::To(const Color& color){
  m_animation->SetEndColor(color);
  return *this;
}

ColorTrack& ColorTrack::For(float duration){
  m_animation->SetDuration(duration);
  return *this;
}

ColorTrack& ColorTrack::Using(EaseType easeType){
  m_animation->SetEaseType(easeType);
  return *this;
}

}
