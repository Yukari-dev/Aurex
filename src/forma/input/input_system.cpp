#include "forma/input/input_system.hpp"
#include "forma/component.hpp"
#include "forma/interfaces/mouse_target.hpp"

namespace Forma{

InputSystem::InputSystem(UIContext& context) : m_context(context) {}

void InputSystem::Update(RenderTree& tree){
  auto *hit = tree.HitTest(m_mousePosition);

  if(hit != m_hoveredNode){
    if(m_hoveredNode){
      auto *comp = m_context.Find(m_hoveredNode->ID());
      if(auto *target = dynamic_cast<IMouseTarget*>(comp)){
        MouseEvent event{};
        event.position = m_mousePosition;
        target->OnMouseLeave(event);
      }
    }

    if(hit){
      auto *comp = m_context.Find(hit->ID());
      if(auto *target = dynamic_cast<IMouseTarget*>(comp)){
        MouseEvent event{};
        event.position = m_mousePosition;
        target->OnMouseEnter(event);
      }
    }

    m_hoveredNode = hit;
  }

  if(hit){
    auto *comp = m_context.Find(hit->ID());
    if(auto *target = dynamic_cast<IMouseTarget*>(comp)){
      MouseEvent event{};
      event.position = m_mousePosition;
      target->OnMouseMove(event);
    }
  }
}

void InputSystem::SetMouseButton(MouseButton button, MouseAction action){
  if(action == MouseAction::Press){
    if(!m_hoveredNode) return;

    m_pressedNodes[button] = m_hoveredNode->ID();

    auto *comp = m_context.Find(m_hoveredNode->ID());
    auto *target = dynamic_cast<IMouseTarget*>(comp);

    if(target){
      MouseEvent event{};
      event.position = m_mousePosition;
      event.button = button;
      event.action = action;

      target->OnMouseDown(event);
    }

    return;
  }

  if(action == MouseAction::Release){
    auto it = m_pressedNodes.find(button);
    if(it == m_pressedNodes.end()) return;
    auto *pressedNode = m_context.Find(it->second);
    auto *target = dynamic_cast<IMouseTarget*>(pressedNode);

    if(target){
      MouseEvent event{};
      event.position = m_mousePosition;
      event.button = button;
      event.action = action;

      target->OnMouseUp(event);
    }
  }
}

void InputSystem::SetMousePosition(Vec2 pos){
  m_mousePosition = pos;
}

Vec2 InputSystem::MousePosition() const{
  return m_mousePosition;
}

}
