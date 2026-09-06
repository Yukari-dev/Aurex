#include "forma/components/panel.hpp"
#include "forma/render/renderData/panel_render_data.hpp"
#include <algorithm>
#include <iostream>

namespace Forma{

Panel::Panel(Vec2 position, Size size, Forma::Color color) : m_color(color){
  Layout().SetPosition(position);
  Layout().SetSize(size);
  SetColor(color);
}

Panel::Panel() {

}

std::unique_ptr<Forma::RenderData> Panel::RenderData() const {
  auto data = std::make_unique<PanelRenderData>();

  data->position = Layout().Position();
  data->size = Layout().Size();
  data->color = Color();
  data->order = m_order;

  return data;
}

void Panel::OnMouseEnter(MouseEvent& event){
 m_color = m_color - 150;
}

void Panel::OnMouseLeave(MouseEvent& event) {
 m_color = m_defaultColor;
}

void Panel::OnMouseMove(MouseEvent& event) {

}

Panel& Panel::SetColor(Forma::Color color){
  m_color = color;
  m_defaultColor = color;
  return *this;
}

Color Panel::Color() const{
  return m_color;
}

}
