#pragma once
#include "forma/layout/layout.hpp"
#include "types/types.hpp"

namespace Forma{

class LayoutResolver{
public:
  static Vec2 ResolvePosition(const Layout& layout, Vec2 parentPosition);
  static Size ResolveSize(const Layout& layout, Size parentSize);
};

}
