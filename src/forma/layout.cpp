#include "forma/layout.hpp"

namespace Forma{


void Layout::SetPosition(Vec2 position){
  m_position = position;
}

void Layout::SetSize(Size size){
  m_size = size;
}

Vec2 Layout::GetPosition() const{
  return m_position;
}

Size Layout::GetSize() const{
  return m_size;
}

}
