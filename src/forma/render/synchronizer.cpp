#include "forma/render/synchronizer.hpp"
#include "forma/layout_resolver.hpp"
#include "forma/render/renderData/panel_render_data.hpp"
#include "forma/render/renderNodes/panel_render_node.hpp"
#include "forma/render/renderable.hpp"
#include <unordered_set>

namespace Forma{

void Synchronizer::Sync(Component& root, RenderNode& parent, Vec2 parentPosition){
  std::unordered_set<uint32_t> seen;

  for(const auto& child : root.Children()){
    Component& comp = *child;
    RenderNode *currentParent = &parent;
    Vec2 position = LayoutResolver::ResolvePosition(comp.Layout(), parentPosition);
    if (auto *renderable = dynamic_cast<IRenderable*>(&comp)){
      auto data = renderable->RenderData();
      if(auto *panelData = AsData<PanelRenderData>(data.get())){
        auto *node = parent.Find<PanelRenderNode>(comp.ID());

        if(!node){
          node = &parent.Add<PanelRenderNode>();
          node->SetID(comp.ID());
        }

        node->position = position;
        node->size = panelData->size;
        node->color = panelData->color;
        node->SetOrder(panelData->order);
        seen.insert(node->ID());

        currentParent = node;
      }
    }
    Sync(comp, *currentParent, position);
  }
  
  std::vector<RenderNode*> toRemove;
  for(auto& node : parent.Children()){
    if (!seen.contains(node->ID()))
      toRemove.push_back(node.get());
  }

  for(auto& node : toRemove){
    parent.Remove(*node);
  }
}

}
