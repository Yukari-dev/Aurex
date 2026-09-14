#pragma once
#include "aurex/animation/animation_node.hpp"
#include <memory>
#include <utility>
#include <vector>

namespace Aurex{

class AnimationGroup : public AnimationNode {
public:
  using AnimationNode::AnimationNode;

  template <typename T, typename... Args>
  AnimationGroup& Add(Args&&... args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    UpdateDuration(child->Duration());
    m_children.push_back(std::move(child));
    return *this;
  }

  template <typename T, typename... Args>
  T& AddAndModify(Args&&... args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    T& ref = *child;
    UpdateDuration(child->Duration());
    m_children.push_back(std::move(child));
    return ref;
  }

  const std::vector<std::unique_ptr<AnimationNode>>& Children() const { return m_children; }
  size_t ChildrenCount() const { return m_children.size(); }
protected:
  virtual void UpdateDuration(float childDuration) = 0;
private:
  std::vector<std::unique_ptr<AnimationNode>> m_children;
};

}
