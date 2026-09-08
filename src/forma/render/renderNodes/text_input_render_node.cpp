#include "forma/render/renderNodes/text_input_render_node.hpp"
#include "forma/render/renderer.hpp"

namespace Forma{

void TextInputRenderNode::Draw(Renderer& renderer){
  renderer.DrawPanel(position, size, color);
  Vec2 textSize = renderer.MeasureText(text, scale);
  float cursorX = static_cast<float>(cursorPosition) + position.x + textSize.x;
  renderer.DrawLine({cursorX, position.y}, {cursorX, position.y + textSize.y});
}

bool TextInputRenderNode::Contains(Vec2 hitPoint) const {
  return hitPoint.x >= position.x && hitPoint.x <= position.x + size.width &&
         hitPoint.y >= position.y &&
         hitPoint.y <= position.y + size.height;
}

}
