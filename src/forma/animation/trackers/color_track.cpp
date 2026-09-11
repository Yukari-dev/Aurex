#include "forma/animation/trackers/color_track.hpp"

namespace Forma{

ColorTrack::ColorTrack(IColorable& color) : m_target(color) {
  m_animation = std::make_unique<ColorAnimation>();
  m_animation->SetStartColor(color.Color());
}

void ColorTrack::Start(){
  m_animation->Start();
}

void ColorTrack::Update(float dt){
  m_animation->Update(dt);
  m_target.SetColor(m_animation->Value());
}

ColorTrack& ColorTrack::From(const Color& color){
  m_animation->SetStartColor(color);
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
