#pragma once
#include "forma/animation/animation_builder.hpp"
#include "forma/animation/animation_controller.hpp"
#include "forma/interfaces/positionable.hpp"
#include "forma/interfaces/sizeable.hpp"
#include "forma/ui_Context.hpp"
#include "forma/layout/layout.hpp"
#include "types/types.hpp"
#include <cstdint>
#include <vector>
#include <memory>

namespace Forma{

class Component : public IPositionable, public ISizeable{
public:
  explicit Component();
  virtual ~Component() = default;

  virtual void OnInitialize() {}
  virtual void OnUpdate(float dt) {}
  void Update(float dt);

  const Forma::Layout& Layout() const;
  AnimationBuilder& Animation();
  const AnimationBuilder& Animation() const;
  const std::vector<std::unique_ptr<Component>>& Children() const;
  IColorable& ColorTarget();

  uint32_t ID() const;

  int32_t Order() const;
  void SetOrder(int32_t o);

  Component *Parent() const;

  Vec2 Position() const override;
  void SetPosition(const Vec2& position) override;

  Forma::Size Size() const override;
  void SetSize(const Forma::Size& position) override;

  Forma::Layout& Layout();

  template<typename T, typename... Args>
  T& Add(Args&& ...args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    child->Initialize(this, m_context);
    T& ref = *child;
    m_children.push_back(std::move(child));
    return ref;
  }

  void Remove(Component& component);

  Component *Find(uint32_t id);

  void Initialize(Component* parent, UIContext* context);
protected:
  explicit Component(IColorable* colorable);
  uint32_t m_id{};
  int32_t m_order{};
  Forma::Layout m_layout;
  Component *m_parent{nullptr};
  UIContext* m_context{nullptr};
  AnimationBuilder m_animationBuilder;
  AnimationController m_animationController;
  bool m_animatable{false};
  std::vector<std::unique_ptr<Component>> m_children;
};

}
