#include "forma/components/button.hpp"
#include "forma/render/renderData/button_render_data.hpp"

namespace Forma{

Button::Button() {}

void Button::OnUpdate(float dt){
  m_animation.Update(dt);
  if(m_animation.IsRunning())
    m_color = m_animation.Value();
}

std::unique_ptr<Forma::RenderData> Button::RenderData() const{
  auto data = std::make_unique<ButtonRenderData>();

  data->position = Layout().Position();
  data->size = Layout().Size();
  data->color = Color();
  data->order = m_order;

  return data;
}

Forma::Color Button::Color() const{
  return m_color;
}

Button& Button::SetColor(Forma::Color color){
  m_color = color;
  return *this;
}

Button& Button::SetDefaultColor(Forma::Color color){
  m_defaultColor = color;
  return *this;
}

Button& Button::SetHoverColor(Forma::Color color){
  m_hoverColor = color;
  return *this;
}

Button& Button::SetPressedColor(Forma::Color color){
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

void Button::AnimateColor(Forma::Color color, float duration, EaseType eastType){
  m_animation.Start(m_color.ToGlm(), color.ToGlm(), duration, eastType);
}

}
