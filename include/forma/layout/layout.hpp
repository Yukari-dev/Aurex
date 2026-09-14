#pragma once
#include "types/types.hpp"
#include <math.hpp>

namespace Forma{

using namespace Axiom;

class Layout{
public:
  void Update(float dt);

  Layout& SetAnimatable(bool v);
  Layout& SetEaseType(EaseType easeType);
  Layout& SetSmoothing(float v);
  Layout& SetPosition(Vec2 position);
  Layout& SetSize(Size size);
  Layout& SetPositionType(PositionType positionType);
  Layout& SetAnchor(Anchor anchor, Anchor parentAnchor = Anchor::TopLeft);
  Layout& SetParentAnchor(Anchor anchor);
  Layout& SetSizeType(SizeType sizeType);
  Layout& SetTextAlign(TextAlign textAlign);

  bool Animatable() const;
  float Smoothing() const;
  Forma::EaseType EaseType() const;
  Vec2 Position() const;
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
  bool m_animatable{false};
  Forma::EaseType m_easeType{Forma::EaseType::OutCubic};
  float m_smoothing{1.0f};
  Vec2 m_position{};
  Vec2 m_targetPosition{};
  Forma::Size m_size{};
  Forma::Size m_targetSize{};
  Forma::PositionType m_positionType{Forma::PositionType::Absolute};
  Forma::Anchor m_anchor{Forma::Anchor::TopLeft};
  Forma::Anchor m_parentAnchor{Forma::Anchor::TopLeft};
  Forma::SizeType m_sizeType{Forma::SizeType::Fixed};
  Forma::TextAlign m_textAlign{TextAlign::Left};
};

}
