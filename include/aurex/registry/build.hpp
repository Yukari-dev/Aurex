#pragma once
#include "aurex/component.hpp"
#include <memory>

namespace Aurex{

std::unique_ptr<Component> BuildTree(
  const Auruim::Node& node,
  ComponentRegistry& reg,
  UIContext& ctx,
  Component *parent
);

}
