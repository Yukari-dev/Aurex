#pragma once
#include "forma/render/render_node.hpp"
#include "types/types.hpp"

namespace Forma{

class PanelRenderNode : public RenderNode{
public:
  void Draw(Renderer& renderer) override;

  Vec2 position{};
  Size size{};
  Color color{};
  int32_t order{};
};

}
