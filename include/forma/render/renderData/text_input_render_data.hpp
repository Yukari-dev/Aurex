#pragma once
#include "forma/render/renderNodes/text_input_render_node.hpp"
#include "forma/render/render_data.hpp"
#include "types/types.hpp"
#include <string>

namespace Forma{

class TextInputRenderData : public RenderData{
public:
  std::unique_ptr<RenderNode> CreateNode() const override{
    return std::make_unique<TextInputRenderNode>();
  }

  void UpdateNode(RenderNode& node) const override{
    auto& textInput = static_cast<TextInputRenderNode&>(node);

    textInput.position = node.position;
    textInput.size = node.size;
    textInput.color = color;
    textInput.text = text;
    textInput.scale = scale;
    textInput.SetOrder(order);
  }

  Vec2 position{};
  Size size{};
  Color color{};
  std::string text{};
  float scale{};
  size_t cursorPosition{};
  int32_t order{};
};

}
