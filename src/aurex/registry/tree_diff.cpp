#include "aurex/registry/tree_diff.hpp"

namespace Aurex{

Diff ComputeDiff(const Auruim::Node& oldTree, const Auruim::Node& newTree){
  Diff diff{};
  
  if(newTree.children.size() != oldTree.children.size()){
    diff.structureChanged = true;
    return diff;
  }

  if(oldTree.type != newTree.type){
    diff.structureChanged = true;
    return diff;
  }

  for(size_t i = 0; i < oldTree.children.size(); ++i){
    if(oldTree.children[i].type != newTree.children[i].type){
      diff.structureChanged = true;
      return diff;
    }
  }

  for(auto& [name, newValue] : newTree.props){
    const Auruim::Value *oldVal = nullptr;

    for(auto& [oldName, oldValue] : oldTree.props){
      if(oldName == name) { oldVal = &oldValue; break; }
    }

    if(!oldVal || *oldVal != newValue){
      diff.changed.push_back({ {}, newTree.type, name, newValue});
    }
  }

  for(size_t i = 0; i < oldTree.children.size(); ++i){
    Diff childDiff = ComputeDiff(oldTree.children[i], newTree.children[i]);

    if(childDiff.structureChanged){
      diff.structureChanged = true;
      return diff;
    }

    for(auto& change : childDiff.changed){
      change.path.insert(change.path.begin(), i);
      diff.changed.push_back(std::move(change));
    }
  }

  return diff;
}

void ApplyDiff(const Diff& diff, Component& root, ComponentRegistry& reg){
  for(auto& change : diff.changed){
    Component *target = FindByPath(root, change.path);
    if(!target) continue;

    reg.Apply(*target, change.type, change.property, change.newValue);
  }
}

Component *FindByPath(Component& root, const std::vector<size_t>& path){
  if (root.Children().empty()) return nullptr;
  Component *current = root.Children()[0].get();
  for(size_t idx : path){
    auto& children = current->Children();
    if(idx >= children.size()) return nullptr;
    current = children[idx].get();
  }
  return current;
}

}
