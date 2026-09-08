#pragma once
#include <cstdint>
#include <memory>
#include <renderer2d.hpp>

namespace Forma{

class Component;

class UIContext{
public:
  UIContext(Axiom::Renderer2D& renderer);
  ~UIContext();
  
  Component& Root();
  
  Component *Find(uint32_t id);

  uint32_t GetID();

  Axiom::Renderer2D& Renderer2D() const;
private:
  Axiom::Renderer2D& m_renderer;
  uint32_t m_currentId{0};
  std::unique_ptr<Component> m_root{nullptr};
};

}
