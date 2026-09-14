#pragma once
#include "aurex/animation/animation_group.hpp"

namespace Aurex{

class Parallel : public AnimationGroup{
public:
  Parallel();
  void Start() override;
  void Update(float dt) override;

protected:
  void UpdateDuration(float childDuratio) override;
};

}
