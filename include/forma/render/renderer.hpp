#pragma once
#include "types/types.hpp"
#include <renderer2d.hpp>

namespace Forma{

class RenderTree;
class RenderNode;

class Renderer{
public:
  explicit Renderer(Axiom::Renderer2D& renderer);
  void Render(RenderTree& tree);

  void DrawPanel(const Vec2& position, const Size& size, const Color& color);
private:
  void RenderNodeTree(RenderNode& node);
private:
  Axiom::Renderer2D& m_renderer;
};

}
