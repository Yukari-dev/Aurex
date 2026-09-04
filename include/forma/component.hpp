#pragma once
#include "forma/ui_Context.hpp"
#include <cstdint>
#include <vector>
#include <memory>

namespace Forma{

class Component{
public:
  explicit Component();
  virtual ~Component() = default;

  Component *Parent() const;

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
  void SetID(uint32_t id);
protected:
  uint32_t m_id{};
  Component *m_parent{nullptr};
  UIContext* m_context{nullptr};
  std::vector<std::unique_ptr<Component>> m_children;
};

}
