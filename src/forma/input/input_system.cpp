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

  for(auto& [button, capture] : m_captures){
    if(!capture.id) continue;
    Vec2 delta = m_mousePosition - capture.lastPosition;

    float dx = m_mousePosition.x - capture.startPosition.x;
    float dy = m_mousePosition.y - capture.startPosition.y;

    float distanceSquared = dx * dx + dy * dy;

    auto *target = dynamic_cast<IMouseTarget*>(m_context.Find(hit->ID()));
    if(!target) continue;

    MouseEvent event{};
    event.position = m_mousePosition;
    event.button = button;
    event.delta = delta;

    if(!capture.dragging && distanceSquared > 9.0f){
      capture.dragging = true;
      target->OnDragStart(event);
    }

    if(capture.dragging)
      target->OnDragMove(event);
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

      MouseCapture capture{};
      capture.id = comp->ID();
      capture.startPosition = m_mousePosition;
      capture.lastPosition = m_mousePosition;
      capture.dragging = false;
      m_captures[button] = capture;

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
      event.delta = m_mouseDelta;
      
      auto cIt = m_captures.find(button);
      if(cIt != m_captures.end() && cIt->second.dragging)
        target->OnDragEnd(event);

      target->OnMouseUp(event);

      if(m_hoveredNode && m_hoveredNode->ID() == pressedNode->ID())
        target->OnClick(event);

      m_captures.erase(cIt);
    }
    m_pressedNodes.erase(it);
  }
}

void InputSystem::SetMouseProperties(Vec2 pos){
  m_mousePosition = pos;
  m_mouseDelta = m_mousePosition - m_previousMousePosition;
  m_previousMousePosition = m_mousePosition;
}

Vec2 InputSystem::MousePosition() const{
  return m_mousePosition;
}

Vec2 InputSystem::MouseDelta() const{
  return m_mouseDelta;
}

}
