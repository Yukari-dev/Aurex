#pragma once
#include "forma/ui_Context.hpp"
#include "forma/layout.hpp"
#include <cstdint>
#include <vector>
#include <memory>

namespace Forma{

class Component{
public:
  explicit Component();
  virtual ~Component() = default;

  uint32_t ID() const;
  Forma::Layout& Layout();
  const Forma::Layout& Layout() const;
  Component *Parent() const;
  const std::vector<std::unique_ptr<Component>>& Children() const;

  template<typename T, typename... Args>
  T& Add(Args&& ...args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    child->Initialize(this, m_context);
    T& ref = *child;
    m_children.push_back(std::move(child));
    return ref;
  }

  void Remove(Component& component);

  void Initialize(Component* parent, UIContext* context);
protected:
  uint32_t m_id{};
  Forma::Layout m_layout;
  Component *m_parent{nullptr};
  UIContext* m_context{nullptr};
  std::vector<std::unique_ptr<Component>> m_children;
};

}
