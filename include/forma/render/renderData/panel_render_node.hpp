#pragma once
#include "forma/render/render_node.hpp"
#include "types/types.hpp"

namespace Forma{

class PanelRenderNode : public RenderNode{
public:
  Vec2 position{};
  Size size{};
  Color color{};
};

}
