#pragma once
#include "forma/component.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/render_tree.hpp"

namespace Forma{

class Synchronizer{
public:
  void Sync(Component& root, RenderTree& renderTree);

  template <typename T>
  T* AsData(RenderData* data){
    return dynamic_cast<T*>(data);
  }
};

}
