#include "aurex/layout/layout.hpp"
#include <cmath>
#include <math.hpp>

namespace Aurex{

using namespace Axiom;

void Layout::Update(float dt){
  if(m_animatable){
    float factor = 1.0f - std::exp(-m_smoothing * dt);
    m_position = EaseLerp(m_position.ToGlm(), m_targetPosition.ToGlm(), factor, m_easeType);
    m_size = EaseLerp(m_size.ToGlm(), m_targetSize.ToGlm(), factor, m_easeType);
    return;
  }
  m_position = m_targetPosition;
  m_size = m_targetSize;
}

Layout& Layout::SetAnimatable(bool v){
  m_animatable = v;
  return *this;
}

Layout& Layout::SetEaseType(Aurex::EaseType easeType){
  m_easeType = easeType;
  return *this;
}

Layout& Layout::SetSmoothing(float v){
  m_smoothing = v;
  return *this;
}

Layout& Layout::SetPosition(Vec2 position){
  m_targetPosition = position;
  if (!m_animatable) {
    m_position = position;
  }
  return *this;
}

Layout& Layout::SetSize(Aurex::Size size){
  m_targetSize = size;
  if (!m_animatable) {
    m_size = size;
  }
  return *this;
}

Layout& Layout::SetPositionType(Aurex::PositionType type){
  m_positionType = type;
  return *this;
}

Layout& Layout::SetAnchor(Aurex::Anchor anchor, Aurex::Anchor parentAnchor){
  m_anchor = anchor;
  if(parentAnchor != Anchor::TopLeft)
    m_parentAnchor = parentAnchor;
  return *this;
}

Layout& Layout::SetParentAnchor(Aurex::Anchor anchor){
  m_parentAnchor = anchor;
  return *this;
}

Layout& Layout::SetSizeType(Aurex::SizeType sizeType){
  m_sizeType = sizeType;
  return *this;
}

Layout& Layout::SetTextAlign(Aurex::TextAlign align){
  m_textAlign = align;
  return *this;
}

bool Layout::Animatable() const{
  return m_animatable;
}

Aurex::EaseType Layout::EaseType() const{
  return m_easeType;
}

float Layout::Smoothing() const{
  return m_animatable;
}

Vec2 Layout::Position() const{
  return m_position;
}

Size Layout::Size() const{
  return m_size;
}

PositionType Layout::PositionType() const {
  return m_positionType;
}

Anchor Layout::Anchor() const {
  return m_anchor;
}

Anchor Layout::ParentAnchor() const{
  return m_parentAnchor;
}

SizeType Layout::SizeType() const {
  return m_sizeType;
}

Aurex::Rect Layout::Rect() const{
  return Aurex::Rect{m_position, m_size};
}

Aurex::TextAlign Layout::TextAlign() const{
  return m_textAlign;
}

bool Layout::HasAnchor() const{
  return m_positionType == PositionType::Anchor;
}

bool Layout::HasTextAlign() const {
  return m_textAlign != TextAlign::None;
}

}
