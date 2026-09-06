#pragma once
#include "forma/interfaces/mouse_target.hpp"
#include "forma/render/render_node.hpp"
#include "forma/render/render_tree.hpp"
#include "forma/ui_Context.hpp"
#include "types/types.hpp"
#include <unordered_map>

namespace Forma{

class InputSystem{
public:
  InputSystem(UIContext& context);
  void Update(RenderTree& tree);

  void SetMousePosition(Vec2 pos);
  Vec2 MousePosition() const;

  void SetMouseButton(MouseButton button, MouseAction actions);
private:
  Vec2 m_mousePosition{};
  RenderNode *m_hoveredNode{nullptr};
  std::unordered_map<MouseButton, uint32_t> m_pressedNodes;
  UIContext& m_context;
};

}
