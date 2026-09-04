#pragma once
#include <cstdint>
#include <memory>

namespace Forma{

class Component;

class UIContext{
public:
  UIContext();
  ~UIContext();
  
  Component& Root();

  uint32_t GetID();
private:
  uint32_t m_currentId{0};
  std::unique_ptr<Component> m_root{nullptr};
};

}
