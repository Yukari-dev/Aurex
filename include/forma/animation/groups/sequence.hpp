#pragma once
#include "forma/animation/animation_group.hpp"
#include <vector>

namespace Forma{

class Sequence : public AnimationGroup{
public:
  Sequence();
  void Start() override;
  void Update(float dt) override;

  bool IsFinished() const override { return !m_running && m_currentChild >= Children().size(); }

  size_t CurrentChildIndex() const { return m_currentChild; }
protected:
  void UpdateDuration(float childDuratio) override;
private:
  size_t m_currentChild{};
};

}
