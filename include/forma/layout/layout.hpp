#pragma once
#include "types/types.hpp"

namespace Forma{

class Layout{
public:
  Layout& SetPosition(Vec2 position);
  Layout& SetSize(Size size);
  Layout& SetPositionType(PositionType positionType);
  Layout& SetSizeType(SizeType sizeType);

  Forma::Vec2 Position() const;
  Forma::Size Size() const;
  Forma::PositionType PositionType() const;
  Forma::SizeType SizeType() const;

private:
  Forma::Vec2 m_position{};
  Forma::Size m_size{};
  Forma::PositionType m_positionType{Forma::PositionType::Absolute};
  Forma::SizeType m_sizeType{Forma::SizeType::Fixed};
};

}
