#pragma once
#include "forma/render/renderNodes/panel_render_node.hpp"
#include "forma/render/render_data.hpp"
#include "types/types.hpp"

namespace Forma{

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
