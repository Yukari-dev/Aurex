#include "aurex/components/button.hpp"
#include "aurex/render/renderData/button_render_data.hpp"

namespace Aurex{

Button::Button() {}

void Button::OnUpdate(float dt){

}

std::unique_ptr<Aurex::RenderData> Button::RenderData() const{
  auto data = std::make_unique<ButtonRenderData>();

  data->position = Layout().Position();
  data->size = Layout().Size();
  data->color = Color();
  data->order = m_order;

  return data;
}

Aurex::Color Button::Color() const{
  return m_color;
}

Button& Button::SetColor(Aurex::Color color){
  m_color = color;
  return *this;
}

Button& Button::SetDefaultColor(Aurex::Color color){
  m_defaultColor = color;
  return *this;
}

Button& Button::SetHoverColor(Aurex::Color color){
  m_hoverColor = color;
  return *this;
}

Button& Button::SetPressedColor(Aurex::Color color){
  m_pressedColor = color;
  return *this;
}

Button& Button::SetOnClick(std::function<void(MouseEvent&)> callback){
  m_onClick = std::move(callback);
  return *this;
}

void Button::OnMouseEnter(MouseEvent&) {
  SetColor(m_hoverColor);
}

void Button::OnMouseLeave(MouseEvent&) {
  SetColor(m_defaultColor);
}

void Button::OnMouseDown(MouseEvent&) {
  SetColor(m_pressedColor);
}

void Button::OnMouseUp(MouseEvent&) {
  SetColor(m_hoverColor);
}

void Button::OnClick(MouseEvent& event){
  if(m_onClick){
    m_onClick(event);
  }
}

}
