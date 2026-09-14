#include "aurex/components/text_input.hpp"
#include "aurex/render/renderData/text_input_render_data.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace Aurex{

TextInput::TextInput() {}

TextInput::TextInput(Vec2 position, Aurex::Size size, Aurex::Color color) {
  Layout().SetPosition(position);
  Layout().SetSize(size);
  SetColor(color);
}

void TextInput::OnInitialize() {
  m_label = &Add<Label>();
  m_label->SetOrder(2);
  m_label->SetColor({255});
  m_label->SetScale(0.5f);
  m_label->Layout().SetPositionType(PositionType::Anchor);
  m_label->Layout().SetAnchor(Anchor::Center).SetTextAlign(TextAlign::Center);
}

void TextInput::OnKeyDown(KeyEvent& event){
  if(event.action != GLFW_PRESS) return;

  switch(event.key){
    case GLFW_KEY_BACKSPACE:
      if(m_cursorPosition > 0){
        m_label->RemoveChar(m_cursorPosition - 1);
        --m_cursorPosition;
      }
      break;

    case GLFW_KEY_LEFT:
      if(m_cursorPosition > 0)
        --m_cursorPosition;
      break;

    case GLFW_KEY_RIGHT:
      if(m_cursorPosition < m_label->Text().size())
        ++m_cursorPosition;
      break;
  }
}

void TextInput::OnTextInput(TextEvent& event){
  char c = static_cast<char>(event.codepoint);
  m_label->AddText(c, m_cursorPosition);
  ++m_cursorPosition;
}

std::unique_ptr<Aurex::RenderData> TextInput::RenderData() const{
  auto data = std::make_unique<TextInputRenderData>();

  data->position = Layout().Position();
  data->size = Layout().Size();
  data->color = Color();
  data->order = m_order;
  data->text = m_label->Text();
  data->scale = m_label->Scale();
  data->cursorPosition = m_cursorPosition;

  return data;
}

TextInput& TextInput::SetColor(Aurex::Color color){
  m_color = color;
  m_defaultColor = color;
  return *this;
}

Aurex::Color TextInput::Color() const{
  return m_color;
}

TextInput& TextInput::SetTextScale(float scale){
  m_label->SetScale(scale);
  return *this;
}

float TextInput::TextScale() const{
  return m_label->Scale();
}

const std::string& TextInput::Text() const{
  return m_label->Text();
}

}
