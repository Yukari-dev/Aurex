#include "forma/component.hpp"
#include <algorithm>
#include <memory>

namespace Forma{

Component::Component(){
}

Component *Component::Parent() const {
  return m_parent; 
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
  SetID(m_context->GetID());
}

void Component::SetID(uint32_t id){
  m_id = id;
}

}
