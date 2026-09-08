#include "forma/render/renderNodes/label_render_node.hpp"
#include "forma/render/renderer.hpp"

namespace Forma{

void LabelRenderNode::Draw(Renderer& renderer){
  renderer.DrawText(text, position, color, textScale);
}

bool LabelRenderNode::Contains(Vec2 hitPoint) const {
  return hitPoint.x >= position.x && hitPoint.x <= position.x + size.width &&
         hitPoint.y >= position.y &&
         hitPoint.y <= position.y + size.height;
}

}
