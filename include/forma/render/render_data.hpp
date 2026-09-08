#pragma once
#include "forma/render/render_node.hpp"
#include <memory>

namespace Forma{

class RenderData{
public:
  virtual ~RenderData() = default;

  virtual std::unique_ptr<RenderNode> CreateNode() const = 0;
  virtual void UpdateNode(RenderNode& node) const = 0;
};

}
