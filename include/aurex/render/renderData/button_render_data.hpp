#pragma once
#include "aurex/render/renderNodes/button_render_node.hpp"
#include "aurex/render/render_data.hpp"
#include "types/types.hpp"

namespace Aurex{

class ButtonRenderData : public RenderData{
public:
  std::unique_ptr<RenderNode> CreateNode() const override{
    return std::make_unique<ButtonRenderNode>();
  }

  void UpdateNode(RenderNode& node) const override{
    auto& button = static_cast<ButtonRenderNode&>(node);

    button.position = node.position;
    button.size = node.size;
    button.color = color;
    button.SetOrder(order);
  }

  Vec2 position{};
  Size size{};
  Color color{};
  int32_t order{};
};

}
