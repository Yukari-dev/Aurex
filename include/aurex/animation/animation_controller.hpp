#pragma once
#include "aurex/animation/animation_builder.hpp"
#include "aurex/animation/animation_node.hpp"
#include "aurex/animation/groups/sequence.hpp"
#include "aurex/animation/trackers/color_track.hpp"
#include "aurex/animation/trackers/position_track.hpp"
#include "aurex/animation/trackers/size_track.hpp"
#include "aurex/interfaces/colorable.hpp"
#include "aurex/interfaces/positionable.hpp"
#include "aurex/interfaces/sizeable.hpp"
#include <memory>
#include <utility>
#include <vector>

namespace Aurex{

class Component;

class AnimationController {
public:
  AnimationController(IPositionable *positionable = nullptr, ISizeable *sizeable = nullptr, IColorable *colorable= nullptr);
  
  template <typename T, typename... Args>
  T& Add(Args&&... args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    T& ref = *child;
    m_children.push_back(std::move(child));
    return ref;
  }

  void Start();
  void Update(float dt);

  AnimationBuilder Animation();
  ColorTrack& AddColorTrack();
  PositionTrack& AddPositionTrack();
  SizeTrack& AddSizeTrack();

  void SetColorTarget(IColorable& target);
  IColorable& ColorTarget() const;
  IPositionable& PositionTarget() const;
  ISizeable& SizeTarget() const;
  Sequence& GetSequence();
private:
  IColorable *m_colorable{nullptr};
  IPositionable *m_positionable{nullptr};
  ISizeable *m_sizeable{nullptr};
  Sequence m_sequence;
  std::vector<std::unique_ptr<AnimationNode>> m_children;
};

}
