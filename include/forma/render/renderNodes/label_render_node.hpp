#pragma once
#include "forma/render/render_node.hpp"
#include "types/types.hpp"
#include <string>

namespace Forma{

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
