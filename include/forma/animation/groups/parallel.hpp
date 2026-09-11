#pragma once
#include "forma/animation/animation_group.hpp"

namespace Forma{

class Parallel : public AnimationGroup{
public:
  Parallel();
  void Start() override;
  void Update(float dt) override;

protected:
  void UpdateDuration(float childDuratio) override;
};

}
