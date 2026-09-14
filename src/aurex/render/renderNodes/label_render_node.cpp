#include "aurex/render/renderNodes/label_render_node.hpp"
#include "aurex/render/renderer.hpp"

namespace Aurex{

void LabelRenderNode::Draw(Renderer& renderer){
  renderer.DrawText(text, position, color, textScale, opacity);
}

bool LabelRenderNode::Contains(Vec2 hitPoint) const {
  return hitPoint.x >= position.x && hitPoint.x <= position.x + size.width &&
         hitPoint.y >= position.y &&
         hitPoint.y <= position.y + size.height;
}

}
