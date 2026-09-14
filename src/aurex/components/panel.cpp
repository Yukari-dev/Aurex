#include "aurex/components/panel.hpp"
#include "aurex/render/renderData/panel_render_data.hpp"

namespace Aurex{

Panel::Panel(Vec2 position, Aurex::Size size, Aurex::Color color) : m_color(color), Component(this){
  Layout().SetPosition(position);
  Layout().SetSize(size);
  SetColor(color);
}

Panel::Panel() : Component(this){
}

std::unique_ptr<Aurex::RenderData> Panel::RenderData() const {
  auto data = std::make_unique<PanelRenderData>();

  data->position = Layout().Position();
  data->size = Layout().Size();
  data->color = Color();
  data->opacity = Opacity();
  data->order = m_order;

  return data;
}

}
