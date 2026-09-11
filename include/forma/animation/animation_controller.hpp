#pragma once
#include "forma/animation/animation_node.hpp"
#include "forma/animation/trackers/color_track.hpp"
#include "forma/interfaces/colorable.hpp"
#include <memory>
#include <utility>
#include <vector>

namespace Forma{

class Component;

class AnimationController {
public:
  AnimationController(IColorable* target = nullptr);
  
  template <typename T, typename... Args>
  T& Add(Args&&... args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    T& ref = *child;
    m_children.push_back(std::move(child));
    return ref;
  }

  void Update(float dt);

  void SetColorTarget(IColorable& target);
  ColorTrack& Color();
private:
  IColorable *m_colorable{nullptr};
  std::unique_ptr<ColorTrack> m_colorTrack{nullptr};
  std::vector<std::unique_ptr<AnimationNode>> m_children;
};

}
