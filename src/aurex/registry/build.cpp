#include "aurex/registry/build.hpp"

namespace Aurex{

std::unique_ptr<Component> BuildTree(
  const Auruim::Node& node,
  ComponentRegistry& reg,
  UIContext& ctx,
  Component *parent
){
  auto comp = reg.Create(node.type);
  if(!comp)
    return nullptr;
  comp->Initialize(parent, &ctx);

  for(auto& [name, value] : node.props){
    reg.Apply(*comp, node.type, name, value);
  }

  for(auto& childNode : node.children){
    auto child = BuildTree(childNode, reg, ctx, comp.get());
    if(!child) return nullptr;
    comp->Attach(std::move(child));
  }


  return comp;
}

}
