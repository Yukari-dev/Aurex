#pragma once
#include "forma/render/render_node.hpp"
#include "forma/render/render_tree.hpp"
#include "forma/ui_Context.hpp"
#include "types/types.hpp"

namespace Forma{

class InputSystem{
public:
  InputSystem(UIContext& context);
  void Update(RenderTree& tree);

  void SetMousePosition(Vec2 pos);
  Vec2 MousePosition() const;
private:
  Vec2 m_mousePosition{};
  RenderNode *m_hoveredNode{nullptr};
  UIContext& m_context;
};

}
