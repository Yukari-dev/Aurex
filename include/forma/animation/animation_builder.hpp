#pragma once
#include "forma/animation/trackers/color_track.hpp"

namespace Forma{

class Component;

class AnimationController;

class AnimationBuilder{
public:
  explicit AnimationBuilder(AnimationController& controller);

  AnimationBuilder& Start();

  AnimationBuilder& From(const Color& color){
    if(m_currentTrack)
      m_currentTrack->From(color);
    return *this;
  }

  AnimationBuilder& To(const Color& color){
    if(m_currentTrack)
      m_currentTrack->To(color);
    return *this;
  }

  AnimationBuilder& Using(EaseType type){
    if(m_currentTrack)
      m_currentTrack->Using(type);
    return *this;
  }

  AnimationBuilder& For(float duration){
    if(m_currentTrack)
      m_currentTrack->For(duration);
    return *this;
  }

  AnimationBuilder& Color();

  AnimationBuilder& Then();
  AnimationBuilder& While();
  AnimationBuilder& And();
private:
  AnimationController& m_controller;
  ColorTrack* m_currentTrack{nullptr};
};

}
