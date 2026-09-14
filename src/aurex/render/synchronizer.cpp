#include "aurex/render/synchronizer.hpp"
#include "aurex/layout/layout_resolver.hpp"
#include "aurex/render/renderable.hpp"
#include <unordered_set>

namespace Aurex{

void Synchronizer::Sync(Component& root, RenderNode& parent, Rect parentRect){
  std::unordered_set<uint32_t> seen;

  for(const auto& child : root.Children()){
    Component& comp = *child;
    RenderNode *currentParent = &parent;
    Size size = LayoutResolver::ResolveSize(comp.Layout(), parentRect.Size());
    Vec2 position = LayoutResolver::ResolvePosition(comp.Layout(), parentRect, size);
    if (auto *renderable = dynamic_cast<IRenderable*>(&comp)){
      auto data = renderable->RenderData();

      auto *node = parent.FindNode(comp.ID());

      if(!node){
        auto newNode = data->CreateNode();
        newNode->SetID(comp.ID());
        node = &parent.Add(std::move(newNode));
      }

      node->position = position;
      node->size = size;
      data->UpdateNode(*node);

      seen.insert(node->ID());

      currentParent = node;
    }
    Sync(comp, *currentParent, Rect{position, size});
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
