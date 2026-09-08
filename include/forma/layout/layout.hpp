#pragma once
#include "types/types.hpp"

namespace Forma{

class Layout{
public:
  Layout& SetPosition(Vec2 position);
  Layout& SetSize(Size size);
  Layout& SetPositionType(PositionType positionType);
  Layout& SetAnchor(Anchor anchor);
  Layout& SetParentAnchor(Anchor anchor);
  Layout& SetSizeType(SizeType sizeType);
  Layout& SetTextAlign(TextAlign textAlign);

  Forma::Vec2 Position() const;
  Forma::Size Size() const;
  Forma::PositionType PositionType() const;
  Forma::Anchor Anchor() const;
  Forma::Anchor ParentAnchor() const;
  Forma::SizeType SizeType() const;
  Forma::Rect Rect() const;
  Forma::TextAlign TextAlign() const;

  bool HasAnchor() const;
  bool HasTextAlign() const;
private:
  Forma::Vec2 m_position{};
  Forma::Size m_size{};
  Forma::PositionType m_positionType{Forma::PositionType::Absolute};
  Forma::Anchor m_anchor{Forma::Anchor::TopLeft};
  Forma::Anchor m_parentAnchor{Forma::Anchor::TopLeft};
  Forma::SizeType m_sizeType{Forma::SizeType::Fixed};
  Forma::TextAlign m_textAlign{TextAlign::Left};
};

}
