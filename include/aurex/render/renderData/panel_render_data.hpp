#pragma once
#include "aurex/render/renderNodes/panel_render_node.hpp"
#include "aurex/render/render_data.hpp"
#include "types/types.hpp"

namespace Aurex{

class PanelRenderData : public RenderData{
public:
  std::unique_ptr<RenderNode> CreateNode() const override{
    return std::make_unique<PanelRenderNode>();
  }

  void UpdateNode(RenderNode& node) const override{
    auto& panel = static_cast<PanelRenderNode&>(node);

    panel.position = node.position;
    panel.size = node.size;
    panel.color = color;
    panel.opacity = opacity;
    panel.SetOrder(order);
  }

  Vec2 position{};
  Size size{};
  Color color{};
  float opacity{};
  int32_t order{};
};

}
