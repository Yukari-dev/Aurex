#pragma once
#include "aurex/render/renderNodes/label_render_node.hpp"
#include "aurex/render/render_data.hpp"
#include "types/types.hpp"

namespace Aurex{

class LabelRenderData : public RenderData{
public:
  std::unique_ptr<RenderNode> CreateNode() const override{
    return std::make_unique<LabelRenderNode>();
  }

  void UpdateNode(RenderNode& node) const override{
    auto& label = static_cast<LabelRenderNode&>(node);

    label.position = node.position;
    label.text = text;
    label.textScale = textScale;
    label.size = size;
    label.color = color;
    label.opacity = opacity;
    label.SetOrder(order);
  }

  std::string text{};
  float textScale{};
  Vec2 position{};
  Size size{};
  Color color{};
  float opacity{};
  int32_t order{};
};

}
