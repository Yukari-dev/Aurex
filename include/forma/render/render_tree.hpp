#pragma once
#include "forma/render/render_node.hpp"
#include <memory>

namespace Forma{

class RenderTree{
public:
  RenderTree();

  RenderNode& Root();

  RenderNode *HitTest(Vec2 point);
private:
  std::unique_ptr<RenderNode> m_root{nullptr};
};

}
