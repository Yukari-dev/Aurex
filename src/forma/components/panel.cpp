#include "forma/components/panel.hpp"
#include "forma/render/renderData/panel_render_data.hpp"

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

void Panel::SetColor(Forma::Color color){
  m_color = color;
}

Color Panel::Color() const{
  return m_color;
}

}
