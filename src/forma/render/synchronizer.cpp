#include "forma/render/synchronizer.hpp"
#include "forma/render/components/panel_render_data.hpp"
#include "forma/render/renderData/panel_render_node.hpp"
#include "forma/render/renderable.hpp"

namespace Forma{

void Synchronizer::Sync(Component& root, RenderTree& renderTree){
  for(const auto& child : root.Children()){
    Component& comp = *child;
    auto *renderable = dynamic_cast<IRenderable*>(&comp);
    if(renderable){
      auto data = renderable->RenderData();
      if(auto *panelData = AsData<PanelRenderData>(data.get())){
        auto& root = renderTree.Root();
        auto* node = root.Find<PanelRenderNode>(comp.ID());

        if (!node) {
          node = &root.Add<PanelRenderNode>();
          node ->SetID(comp.ID());
        }

        node->position = panelData->position;
        node->size = panelData->size;
        node->color = panelData->color;
      }
    }
    Sync(comp, renderTree);
  }
}

}
