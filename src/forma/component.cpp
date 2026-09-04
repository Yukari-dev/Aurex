#include "forma/component.hpp"
#include <algorithm>
#include <memory>

namespace Forma{

Component::Component(){
}

Component *Component::Parent() const {
  return m_parent; 
}

uint32_t Component::ID() const {
  return m_id;
}

Layout Component::GetLayout() const {
  return m_layout;
}

void Component::Remove(Component& component){
  if(&component == this || &component == m_parent)
    return;
  m_children.erase(
    std::remove_if(
      m_children.begin(), m_children.end(),
      [&component](const std::unique_ptr<Component>& child){
        return child.get() == &component;
      }
    ),
    m_children.end()
  );
}

void Component::Initialize(Component *parent, UIContext* context){
  m_parent = parent;
  m_context = context;
   m_id = m_context->GetID();
}

}
