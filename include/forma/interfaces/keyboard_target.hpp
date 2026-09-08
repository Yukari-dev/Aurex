#pragma once
#include "forma/input/input_system.hpp"
#include <cstdint>

namespace Forma{

struct KeyEvent{
  char character{};
  uint32_t key{};
  uint32_t scancode{};
  uint32_t action{};
};

class IKeyboardTarget{
public:
  virtual ~IKeyboardTarget() = default;

  virtual void OnKeyDown(KeyEvent& event) {}
  virtual void OnKeyUp(KeyEvent& event) {}
  virtual void OnTextInput(TextEvent& event) {}
};

}
