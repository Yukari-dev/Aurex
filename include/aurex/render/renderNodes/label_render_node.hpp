#pragma once
#include "aurex/render/render_node.hpp"
#include "types/types.hpp"
#include <string>

namespace Aurex{

class LabelRenderNode : public RenderNode{
public:
  void Draw(Renderer& renderer) override;

  bool Contains(Vec2 hitPoint) const override;

  std::string text{};
  float textScale{};
  Vec2 position{};
  Color color{};
  float opacity{};
  int32_t order{};
};

}
