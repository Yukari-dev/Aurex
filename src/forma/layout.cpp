#include "forma/layout.hpp"

namespace Forma{

void Layout::SetPosition(Vec2 position){
  m_position = position;
}

void Layout::SetSize(Forma::Size size){
  m_size = size;
}

Vec2 Layout::Position() const{
  return m_position;
}

Size Layout::Size() const{
  return m_size;
}

}
