#include "forma/layout_resolver.hpp"

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

}
