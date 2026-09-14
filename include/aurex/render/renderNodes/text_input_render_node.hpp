#pragma once
#include "aurex/render/render_node.hpp"
#include "types/types.hpp"

namespace Aurex{

class TextInputRenderNode : public RenderNode{
public:
  void Draw(Renderer& renderer) override;

  bool Contains(Vec2 hitPoint) const override;

  Vec2 position{};
  Size size{};
  Color color{};
  int32_t order{};
  std::string text{};
  float scale{};
  size_t cursorPosition{};
};

}
