#pragma once
#include "forma/layout/layout.hpp"
#include "types/types.hpp"

namespace Forma{

class LayoutResolver{
public:
  static Vec2 ResolvePosition(const Layout& layout, const Rect& parentRect, const Size& childRect);
  static Size ResolveSize(const Layout& layout, Size parentSize);
private:
  static Vec2 GetAnchorPoint(Anchor anchor, const Rect& rect);
  static Vec2 ResolvePositionType(const Layout& layout, Vec2 parentPosition);
  static Vec2 ResolveAnchor(const Layout& layout, Rect parentRect, Size childSize);
};

}
