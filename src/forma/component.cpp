#include "forma/component.hpp"
#include <algorithm>
#include <memory>

namespace Forma{

Component::Component() : m_animationController(this, this), m_animationBuilder(m_animationController) {}

Component::Component(IColorable *colorable) : m_animationController(this, this, colorable), m_animationBuilder(m_animationController) {}

void Component::Update(float dt){
  m_animationController.Update(dt);
  m_layout.Update(dt);
  OnUpdate(dt);
  for(auto& child : m_children)
    child->Update(dt);
}

Component *Component::Parent() const {
  return m_parent; 
}

uint32_t Component::ID() const {
  return m_id;
}

Layout& Component::Layout() {
  return m_layout;
}

Vec2 Component::Position() const{
  return Layout().Position();
}

void Component::SetPosition(const Vec2& position){
  Layout().SetPosition(position);
}

Size Component::Size() const{
  return Layout().Size();
}

void Component::SetSize(const Forma::Size& position){
  Layout().SetSize(position);
}

const Layout& Component::Layout() const {
  return m_layout;
}

AnimationBuilder& Component::Animation() {
  return m_animationBuilder;
}

const AnimationBuilder& Component::Animation() const {
  return m_animationBuilder;
}

const std::vector<std::unique_ptr<Component>>& Component::Children() const{
  return m_children;
}

int32_t Component::Order() const{
  return m_order;
}

void Component::SetOrder(int32_t o){
  m_order = o;
}

void Component::Initialize(Component* parent, UIContext* context) {
  m_parent = parent;
  m_context = context;
  m_id = m_context->GetID();
  OnInitialize();
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

Component *Component::Find(uint32_t id){
  if(ID() == id) return this;

  for(const auto& child : m_children){
    if(auto * found = child->Find(id))
      return found;
  }
  return nullptr;
}

}
