#pragma once
#include "types/types.hpp"

namespace Forma{

struct MouseEvent{
  Vec2 position{};
  int button{};
  bool handled{false};
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
