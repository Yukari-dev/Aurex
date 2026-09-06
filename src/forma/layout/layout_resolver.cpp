#include "forma/layout/layout_resolver.hpp"

namespace Forma{

Vec2 LayoutResolver::ResolvePosition(const Layout& layout, const Rect& parentRect, const Size& childSize){
  if(layout.HasAnchor())
    return ResolveAnchor(layout, parentRect, childSize);

  return ResolvePositionType(layout, parentRect.Position());
}

Vec2 LayoutResolver::ResolvePositionType(const Layout& layout, Vec2 parentPosition){
  switch(layout.PositionType()){
    case PositionType::Absolute:
      return layout.Position();
    case PositionType::Relative:
      return parentPosition + layout.Position();
    default:
      return layout.Position();
  }
}

Vec2 LayoutResolver::ResolveAnchor(const Layout& layout, Rect parentRect, Size childSize){
  Rect childRect = Rect{0, 0, childSize.width, childSize.height};
  Vec2 childAnchor = GetAnchorPoint(layout.Anchor(), childRect);
  Vec2 parentAnchor = GetAnchorPoint(layout.ParentAnchor(), parentRect);

  return parentAnchor - childAnchor + layout.Position();
}

Size LayoutResolver::ResolveSize(const Layout& layout, Size parentSize){
  switch(layout.SizeType()){
    case SizeType::Fixed:
      return layout.Size();
    case SizeType::Fill:
      return parentSize;
    case SizeType::Percent:
      return parentSize * layout.Size();
  }
  return layout.Size();
}

Vec2 LayoutResolver::GetAnchorPoint(Anchor anchor, const Rect& rect){
  switch(anchor){
    case Anchor::TopLeft: return rect.Position();
    case Anchor::TopCenter: return {rect.HalfWidth(), rect.y};
    case Anchor::TopRight: return {rect.FullWidth(), rect.y};

    case Anchor::Left: return {rect.x, rect.HalfHeight()};
    case Anchor::Center: return {rect.HalfWidth(), rect.HalfHeight()};
    case Anchor::Right: return {rect.FullWidth(), rect.HalfHeight()};

    case Anchor::BottomLeft: return {rect.x, rect.FullHeight()};
    case Anchor::BottomCenter: return {rect.HalfWidth(), rect.FullHeight()};
    case Anchor::BottomRight: return {rect.FullWidth(), rect.FullHeight()};
    default:
      return rect.Position();
  }
}

}
