#pragma once
#include "aurex/animation/animation_node.hpp"
#include <functional>

namespace Aurex{

class Callback : public AnimationNode{
public:
  using CallbackFunction = std::function<void()>;
  explicit Callback(CallbackFunction function);

  void Start() override;
  void Update(float dt) override;

private:
  CallbackFunction m_callbackFunction{};
  bool m_executed{false};
};

}
