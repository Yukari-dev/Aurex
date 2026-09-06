#include "forma/layout/layout_resolver.hpp"

namespace Forma{

Vec2 LayoutResolver::ResolvePosition(const Layout& layout, Vec2 parentPosition){
  switch(layout.PositionType()){
    case PositionType::Absolute:
      return layout.Position();
    case PositionType::Relative:
      return parentPosition + layout.Position();
  }
  return layout.Position();
}

Size LayoutResolver::ResolveSize(const Layout& layout, Size parentSize){
  switch(layout.SizeType()){
    case SizeType::Fixed:
      return layout.Size();
    case SizeType::Fill:
      return parentSize;
  }
  return layout.Size();
}

}
