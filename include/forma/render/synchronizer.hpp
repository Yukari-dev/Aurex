#pragma once
#include "forma/component.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/render_node.hpp"

namespace Forma{

class Synchronizer{
public:
  void Sync(Component& root, RenderNode& parent, Vec2 parentPosition = {0, 0}, Size size = {0, 0});

  template <typename T>
  T* AsData(RenderData* data){
    return dynamic_cast<T*>(data);
  }
};

}
