#pragma once
#include "types/types.hpp"

namespace Forma{

class Layout{
public:
  void SetPosition(Vec2 position);
  void SetSize(Size size);

  Vec2 GetPosition() const;
  Size GetSize() const;
private:
  Vec2 m_position{};
  Size m_size{};
};

}
