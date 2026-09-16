#pragma once
#include "aurex/component.hpp"
#include "aurex/registry/component_registry.hpp"
#include <auruim/node.hpp>
#include <auruim/value.hpp>
#include <string>
#include <vector>

namespace Aurex{

struct PropetyChange{
  std::vector<size_t> path;
  std::string type{};
  std::string property{};
  Auruim::Value newValue{};
};

struct NodeAdded {
  Auruim::Node node{};
  Component *parent{nullptr};
};

struct NodeRemoved{
  Component *parent{nullptr};
};

struct Diff{
  std::vector<PropetyChange> changed{};
  bool structureChanged{false};
};

Diff ComputeDiff(const Auruim::Node& oldTree, const Auruim::Node& newTree);

Component *FindByPath(Component& root, const std::vector<size_t>& path);

void ApplyDiff(const Diff& diff, Component& root, ComponentRegistry& reg);

}
