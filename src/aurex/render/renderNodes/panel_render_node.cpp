#include "aurex/render/renderNodes/panel_render_node.hpp"
#include "aurex/render/renderer.hpp"

namespace Aurex{

void PanelRenderNode::Draw(Renderer& renderer){
  renderer.DrawPanel(
    position, size, color, opacity
  );
}

bool PanelRenderNode::Contains(Vec2 hitPoint) const {
  return hitPoint.x >= position.x && hitPoint.x <= position.x + size.width &&
         hitPoint.y >= position.y &&
         hitPoint.y <= position.y + size.height;
}

}
