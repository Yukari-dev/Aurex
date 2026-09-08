#pragma once
#include <cstdint>

namespace Forma{

struct KeyEvent{
  uint32_t scancode{};
  char character{};
};

class IKeyboardTarget{
public:
  virtual ~IKeyboardTarget() = default;

  virtual void OnKeyDown(KeyEvent& event) {}
  virtual void OnKeyUp(KeyEvent& event) {}
};

}
