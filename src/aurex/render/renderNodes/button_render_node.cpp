#include "aurex/render/renderNodes/button_render_node.hpp"
#include "aurex/render/renderer.hpp"

namespace Aurex{

void ButtonRenderNode::Draw(Renderer& renderer){
  renderer.DrawPanel(
    position, size, color
  );
}

bool ButtonRenderNode::Contains(Vec2 hitPoint) const {
  return hitPoint.x >= position.x && hitPoint.x <= position.x + size.width &&
         hitPoint.y >= position.y &&
         hitPoint.y <= position.y + size.height;
}

}
