#include "aurex/render/renderer.hpp"
#include "aurex/render/render_tree.hpp"
#include "aurex/render/render_node.hpp"
#include <cstdio>

namespace Aurex{

Renderer::Renderer(Axiom::Renderer2D& renderer) : m_renderer(renderer){

}

void Renderer::Render(RenderTree& tree){
  RenderNodeTree(tree.Root());
}

void Renderer::RenderNodeTree(RenderNode& node){
  if(!node.Visible())
    return;

  node.Draw(*this);

  node.SortChildren();

  for(const auto& child : node.Children()){
    RenderNodeTree(*child);
  }
}

void Renderer::SetDefaultFont(const std::string& fontName, float fontSize){
  m_renderer.SetDefaultFont(fontName, fontSize);
}

Vec2 Renderer::MeasureText(const std::string& text, float scale){
  return {m_renderer.MeasureText(text, scale).x, m_renderer.MeasureText(text, scale).y};
}

void Renderer::DrawPanel(const Vec2& position, const Size& size, const Color& color, float alpha){
  m_renderer.DrawRect(
    position.ToGlm(), size.ToGlm(), color.Normalize().ToGlm(), alpha
  );
}

void Renderer::DrawLine(Vec2 from, Vec2 to, float thickness, const Color& color, float alpha){
  m_renderer.DrawLine(from.ToGlm(), to.ToGlm(), thickness, color.Normalize().ToGlm(), alpha);
}

void Renderer::DrawText(const std::string& text, const Vec2& position, const Color& color, float scale, float alpha){
  m_renderer.DrawText(text, position.ToGlm(), color.Normalize().ToGlm(), scale, alpha);
}

}
