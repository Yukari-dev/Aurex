#include "forma/layout/layout.hpp"
#include <math.hpp>

namespace Forma{

using namespace Axiom;

void Layout::Update(float dt){
  if(m_animatable){
    m_position = EaseLerp(m_position.ToGlm(), m_targetPosition.ToGlm(), m_smoothing * dt, m_easeType);
    m_size = EaseLerp(m_size.ToGlm(), m_targetSize.ToGlm(), m_smoothing * dt, m_easeType);
    return;
  }
  m_position = m_targetPosition;
  m_size = m_targetSize;
}

Layout& Layout::SetAnimatable(bool v){
  m_animatable = v;
  return *this;
}


Layout& Layout::SetEaseType(Forma::EaseType easeType){
  m_easeType = easeType;
  return *this;
}

Layout& Layout::SetSmoothing(float v){
  m_smoothing = v;
  return *this;
}

Layout& Layout::SetPosition(Vec2 position){
  m_targetPosition = position;
  return *this;
}

Layout& Layout::SetSize(Forma::Size size){
  m_targetSize = size;
  return *this;
}

Layout& Layout::SetPositionType(Forma::PositionType type){
  m_positionType = type;
  return *this;
}

Layout& Layout::SetAnchor(Forma::Anchor anchor, Forma::Anchor parentAnchor){
  m_anchor = anchor;
  if(parentAnchor != Anchor::TopLeft)
    m_parentAnchor = parentAnchor;
  return *this;
}

Layout& Layout::SetParentAnchor(Forma::Anchor anchor){
  m_parentAnchor = anchor;
  return *this;
}

Layout& Layout::SetSizeType(Forma::SizeType sizeType){
  m_sizeType = sizeType;
  return *this;
}

Layout& Layout::SetTextAlign(Forma::TextAlign align){
  m_textAlign = align;
  return *this;
}

bool Layout::Animatable() const{
  return m_animatable;
}

Forma::EaseType Layout::EaseType() const{
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

Forma::Rect Layout::Rect() const{
  return Forma::Rect{m_position, m_size};
}

Forma::TextAlign Layout::TextAlign() const{
  return m_textAlign;
}

bool Layout::HasAnchor() const{
  return m_positionType == PositionType::Anchor;
}

bool Layout::HasTextAlign() const {
  return m_textAlign != TextAlign::None;
}

}
