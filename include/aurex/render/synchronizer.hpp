#pragma once
#include "aurex/component.hpp"
#include "aurex/render/render_data.hpp"
#include "aurex/render/render_node.hpp"

namespace Aurex{

class Synchronizer{
public:
  void Sync(Component& root, RenderNode& parent, Rect parentRect);

  template <typename T>
  T* AsData(RenderData* data){
    return dynamic_cast<T*>(data);
  }
};

}
