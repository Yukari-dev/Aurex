#pragma once
#include "forma/animation/animation_node.hpp"
#include <memory>
#include <utility>
#include <vector>

namespace Forma{

class Sequence : public AnimationNode{
public:
  Sequence() : AnimationNode(0.0f) {}
  void Start() override;
  void Update(float dt) override;

  bool IsFinished() const override { return !m_running && m_currentChild >= m_children.size(); }
  
  template <typename T, typename... Args>
  Sequence& Add(Args&&... args){
    auto animationNode = std::make_unique<T>(std::forward<Args>(args)...);
    m_duration += animationNode->Duration();
    m_children.push_back(std::move(animationNode));
    return *this;
  }

  size_t CurrentChildIndex() const { return m_currentChild; }
private:
  std::vector<std::unique_ptr<AnimationNode>> m_children;
  size_t m_currentChild{};
};

}
