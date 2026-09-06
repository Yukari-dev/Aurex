#include "forma/render/renderer.hpp"
#include "forma/render/render_tree.hpp"
#include "forma/render/render_node.hpp"

namespace Forma{

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

void Renderer::DrawPanel(const Vec2& position, const Size& size, const Color& color){
  m_renderer.DrawRect(
    position.ToGlm(), size.ToGlm(), color.ToGlm()
  );
}

}
