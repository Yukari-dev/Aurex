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

SizeType Layout::SizeType() const {
  return m_sizeType;
}

}
