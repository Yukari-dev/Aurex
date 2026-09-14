#pragma once
#include "aurex/render/render_node.hpp"
#include <memory>

namespace Aurex{

class RenderData{
public:
  virtual ~RenderData() = default;

  virtual std::unique_ptr<RenderNode> CreateNode() const = 0;
  virtual void UpdateNode(RenderNode& node) const = 0;
};

}
