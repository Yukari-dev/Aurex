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

void Panel::OnDragStart(MouseEvent& event){
  std::cout << "Drag started\n";
}

void Panel::OnDragEnd(MouseEvent& event){
  std::cout << "Drag ended\n";
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
