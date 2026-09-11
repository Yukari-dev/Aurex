#include "forma/components/panel.hpp"
#include "forma/render/renderData/panel_render_data.hpp"

namespace Forma{

Panel::Panel(Vec2 position, Size size, Forma::Color color) : m_color(color), Component(){
  Layout().SetPosition(position);
  Layout().SetSize(size);
  SetColor(color);
  Animation().SetColorTarget(*this);
}

Panel::Panel() : Component(){
  Animation().SetColorTarget(*this);
}

std::unique_ptr<Forma::RenderData> Panel::RenderData() const {
  auto data = std::make_unique<PanelRenderData>();

  data->position = Layout().Position();
  data->size = Layout().Size();
  data->color = Color();
  data->order = m_order;

  return data;
}

}
