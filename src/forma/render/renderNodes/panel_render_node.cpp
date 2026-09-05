#include "forma/render/renderNodes/panel_render_node.hpp"
#include "forma/render/renderer.hpp"

namespace Forma{

void PanelRenderNode::Draw(Renderer& renderer){
  renderer.DrawPanel(
    position, size, color
  );
}

}
