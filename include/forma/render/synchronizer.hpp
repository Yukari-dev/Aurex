#pragma once
#include "forma/component.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/render_node.hpp"

namespace Forma{

class Synchronizer{
public:
  void Sync(Component& root, RenderNode& parent, Rect parentRect);

  template <typename T>
  T* AsData(RenderData* data){
    return dynamic_cast<T*>(data);
  }
};

}
