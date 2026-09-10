#pragma once
#include "forma/animation/animation_node.hpp"
#include <memory>
#include <utility>
#include <vector>

namespace Forma{

class AnimationGroup : public AnimationNode {
public:
  using AnimationNode::AnimationNode;

  template <typename T, typename... Args>
  AnimationGroup& Add(Args&&... args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    T& ref = *child;
    UpdateDuration(child->Duration());
    m_children.push_back(std::move(child));
    return *this;
  }

  const std::vector<std::unique_ptr<AnimationNode>>& Children() const { return m_children; }
  size_t ChildrenCount() const { return m_children.size(); }
protected:
  virtual void UpdateDuration(float childDuration) = 0;
private:
  std::vector<std::unique_ptr<AnimationNode>> m_children;
};

}
