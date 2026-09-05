#pragma once
#include "forma/render/render_node.hpp"
#include <memory>

namespace Forma{

class RenderTree{
public:
  RenderTree();

  RenderNode& Root();
private:
  std::unique_ptr<RenderNode> m_root{nullptr};
};

}
