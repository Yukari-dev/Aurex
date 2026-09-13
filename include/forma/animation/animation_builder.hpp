#pragma once
#include "forma/animation/animation_group.hpp"
#include "forma/animation/trackers/track.hpp"
#include <math.hpp>

namespace Forma{

class Component;

class AnimationController;

class AnimationBuilder{
public:
  explicit AnimationBuilder(AnimationController& controller);

  AnimationBuilder& Start();

  template <typename T>
  AnimationBuilder& From(const T& value){
    if(m_currentTrack)
      m_currentTrack->From(value);
    return *this;
  }

  template <typename T>
  AnimationBuilder& To(const T& value){
    if(m_currentTrack)
      m_currentTrack->To(value);
    return *this;
  }

  AnimationBuilder& Using(Axiom::EaseType type){
    if(m_currentTrack)
      m_currentTrack->SetEase(type);
    return *this;
  }

  AnimationBuilder& For(float duration){
    if(m_currentTrack)
      m_currentTrack->SetDuration(duration);
    return *this;
  }

  AnimationBuilder& Color();
  AnimationBuilder& Opacity();
  AnimationBuilder& Position();
  AnimationBuilder& Size();
  AnimationBuilder& Delay(float duration);

  AnimationBuilder& Then();
  AnimationBuilder& While();
  AnimationBuilder& And();
private:
  AnimationController& m_controller;

  AnimationGroup *m_currentGroup{nullptr};
  ITrackable* m_currentTrack{nullptr};
};

}
