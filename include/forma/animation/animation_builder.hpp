#pragma once
#include "forma/animation/groups/sequence.hpp"
#include "forma/animation/trackers/color_track.hpp"

namespace Forma{

class AnimationController;

class AnimationBuilder{
public:
  explicit AnimationBuilder(AnimationController& controller);

  void Start();
  void SetColorTarget(IColorable& target);
  ColorTrack& Color();
  AnimationBuilder& Then();
private:
  AnimationController& m_controller;
  Sequence *m_sequence{nullptr};
};

}
