#pragma once
#include "aurex/animation/animation_builder.hpp"
#include "aurex/animation/animation_controller.hpp"
#include "aurex/registry/component_registry.hpp"
#include "aurex/interfaces/positionable.hpp"
#include "aurex/interfaces/sizeable.hpp"
#include "aurex/ui_Context.hpp"
#include "aurex/layout/layout.hpp"
#include "types/types.hpp"
#include <auruim/node.hpp>
#include <cstdint>
#include <vector>
#include <memory>

namespace Aurex{

class Component : public IPositionable, public ISizeable{
public:
  explicit Component();
  virtual ~Component() = default;

  virtual void OnInitialize() {}
  virtual void OnUpdate(float dt) {}
  void Update(float dt);

  const Aurex::Layout& Layout() const;
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

  Aurex::Size Size() const override;
  void SetSize(const Aurex::Size& position) override;

  Aurex::Layout& Layout();

  template<typename T, typename... Args>
  T& Add(Args&& ...args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    child->Initialize(this, m_context);
    return static_cast<T&>(*Attach(std::move(child)));
  }

  Component *Attach(std::unique_ptr<Component> child);
  Component *Find(uint32_t id);
  void Remove(Component& component);
  void ClearChildren();

  void Initialize(Component* parent, UIContext* context);
protected:
  explicit Component(IColorable* colorable);
  uint32_t m_id{};
  int32_t m_order{};
  Aurex::Layout m_layout;
  Component *m_parent{nullptr};
  UIContext* m_context{nullptr};
  AnimationBuilder m_animationBuilder;
  AnimationController m_animationController;
  bool m_animatable{false};
  std::vector<std::unique_ptr<Component>> m_children;
};

}
