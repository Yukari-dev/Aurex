#pragma once
#include "types/types.hpp"
#include <math.hpp>

namespace Aurex{

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
  Aurex::EaseType EaseType() const;
  Vec2 Position() const;
  Aurex::Size Size() const;
  Aurex::PositionType PositionType() const;
  Aurex::Anchor Anchor() const;
  Aurex::Anchor ParentAnchor() const;
  Aurex::SizeType SizeType() const;
  Aurex::Rect Rect() const;
  Aurex::TextAlign TextAlign() const;

  bool HasAnchor() const;
  bool HasTextAlign() const;
private:
  bool m_animatable{false};
  Aurex::EaseType m_easeType{Aurex::EaseType::OutCubic};
  float m_smoothing{1.0f};
  Vec2 m_position{};
  Vec2 m_targetPosition{};
  Aurex::Size m_size{};
  Aurex::Size m_targetSize{};
  Aurex::PositionType m_positionType{Aurex::PositionType::Absolute};
  Aurex::Anchor m_anchor{Aurex::Anchor::TopLeft};
  Aurex::Anchor m_parentAnchor{Aurex::Anchor::TopLeft};
  Aurex::SizeType m_sizeType{Aurex::SizeType::Fixed};
  Aurex::TextAlign m_textAlign{TextAlign::None};
};

}
