#include "aurex/components/label.hpp"
#include "aurex/render/renderData/label_render_data.hpp"

namespace Aurex{

Label::Label() : Component(this) {}

Label::Label(const std::string& text, float scale, Vec2 position, Aurex::Color color)
: Component(this), m_text(text), m_scale(scale){
  Layout().SetPosition(position);
  Layout().SetSize(m_context->Renderer2D().MeasureText(m_text, m_scale));
  SetColor(color);
}

void Label::OnUpdate(float dt){
  ColorUpdate(dt);
}

std::unique_ptr<Aurex::RenderData> Label::RenderData() const {
  auto data = std::make_unique<LabelRenderData>();

  data->position = Layout().Position();
  data->text = m_text;
  data->textScale = m_scale;
  data->size = Layout().Size();
  data->color = Color();
  data->opacity = Opacity();
  data->order = m_order;

  return data;
}

Label& Label::SetText(const std::string& text){
  m_text = text;
  Layout().SetSize(m_context->Renderer2D().MeasureText(m_text, m_scale));
  return *this;
}

Label& Label::AddText(const std::string& text, size_t pos){
  m_text.insert(pos, text);
  Layout().SetSize(m_context->Renderer2D().MeasureText(m_text, m_scale));
  return *this;
}

Label& Label::AddText(char c, size_t pos){
  m_text.insert(pos, 1, c);
  Layout().SetSize(m_context->Renderer2D().MeasureText(m_text, m_scale));
  return *this;
}

Label& Label::RemoveChar(size_t pos){
  m_text.erase(pos - 1, 1);
  return *this;
}

const std::string& Label::Text() const{
  return m_text;
}

Label& Label::SetScale(float scale){
  m_scale = scale;
  Layout().SetSize(m_context->Renderer2D().MeasureText(m_text, m_scale));
  return *this;
}

float Label::Scale(){
  return m_scale;
}

}
