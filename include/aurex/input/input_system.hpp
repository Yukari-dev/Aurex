#pragma once
#include "aurex/interfaces/mouse_target.hpp"
#include "aurex/render/render_node.hpp"
#include "aurex/render/render_tree.hpp"
#include "aurex/ui_Context.hpp"
#include "types/types.hpp"
#include <unordered_map>

namespace Aurex{

struct MouseCapture{
  uint32_t id{};
  Vec2 startPosition{};
  Vec2 lastPosition{};
  bool dragging{false};
};

struct TextEvent{
  uint32_t codepoint{};
};

class InputSystem{
public:
  InputSystem(UIContext& context);
  void Update(RenderTree& tree);

  void SetMouseProperties(Vec2 pos);
  Vec2 MousePosition() const;
  Vec2 MouseDelta() const;

  void SetMouseButton(MouseButton button, MouseAction actions);

  void SetFocus(Component *component);
  void SetKeyboardKey(uint32_t key, uint32_t scancode, int32_t action);
  void SetTextInput(unsigned int codepoint);

  template <typename T>
  T *AsInterface(Component* val){
    return dynamic_cast<T*>(val);
  }
private:
  Vec2 m_mousePosition{};
  Vec2 m_previousMousePosition{};
  Vec2 m_mouseDelta{};
  uint32_t m_currentKeyCode{};
  RenderNode *m_hoveredNode{nullptr};
  RenderNode *m_draggedNode{nullptr};
  uint32_t m_focusedID{};
  std::unordered_map<MouseButton, uint32_t> m_pressedNodes;
  std::unordered_map<MouseButton, MouseCapture> m_captures;
  UIContext& m_context;
};

}
