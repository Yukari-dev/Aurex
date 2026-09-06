#include "forma/layout/layout.hpp"

namespace Forma{

Layout& Layout::SetPosition(Vec2 position){
  m_position = position;
  return *this;
}

Layout& Layout::SetSize(Forma::Size size){
  m_size = size;
  return *this;
}

Layout& Layout::SetPositionType(Forma::PositionType type){
  m_positionType = type;
  return *this;
}

Layout& Layout::SetAnchor(Forma::Anchor anchor){
  m_anchor = anchor;
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

bool Layout::HasAnchor() const{
  return m_positionType == PositionType::Anchor;
}

}
