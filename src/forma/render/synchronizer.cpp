#include "forma/render/synchronizer.hpp"
#include "forma/render/renderData/panel_render_data.hpp"
#include "forma/render/renderNodes/panel_render_node.hpp"
#include "forma/render/renderable.hpp"

namespace Forma{

void Synchronizer::Sync(Component& root, RenderNode& parent){
  for(const auto& child : root.Children()){
    Component& comp = *child;
    RenderNode *currentParent = &parent;
    if (auto *renderable = dynamic_cast<IRenderable*>(&comp)){
      auto data = renderable->RenderData();
      if(auto *panelData = AsData<PanelRenderData>(data.get())){
        auto *node = parent.Find<PanelRenderNode>(comp.ID());

        if(!node){
          node = &parent.Add<PanelRenderNode>();
          node->SetID(comp.ID());
        }

        node->position = panelData->position;
        node->size = panelData->size;
        node->color = panelData->color;

        currentParent = node;
      }
    }
    Sync(comp, *currentParent);
  }
}

}
