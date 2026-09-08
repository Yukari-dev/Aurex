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

  void SetDefaultFont(const std::string& fontName, float fontSize = 64.0f);

  Vec2 MeasureText(const std::string& text, float scale = 1.0f);

  void DrawPanel(const Vec2& position, const Size& size, const Color& color);
  void DrawLine(Vec2 from, Vec2 to, float thickness = 1.0f, const Color& color = {1.0f});
  void DrawText(const std::string& text, const Vec2& position, const Color& color, float scale = 1.0f);
private:
  void RenderNodeTree(RenderNode& node);
private:
  Axiom::Renderer2D& m_renderer;
};

}
