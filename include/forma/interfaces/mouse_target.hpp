#pragma once
#include "types/types.hpp"

namespace Forma{

enum class MouseButton{
  Left,
  Middle,
  Right
};

enum class MouseAction{
  Press,
  Release
};

struct MouseEvent{
  Vec2 position{};
  MouseButton button{};
  MouseAction action{};
};

class IMouseTarget{
public:
  ~IMouseTarget() = default;

  virtual void OnMouseDown(MouseEvent& event) {}
  virtual void OnMouseUp(MouseEvent& event) {}
  virtual void OnMouseMove(MouseEvent& event) {}
  virtual void OnMouseEnter(MouseEvent& event) {}
  virtual void OnMouseLeave(MouseEvent& event) {}
};

}
