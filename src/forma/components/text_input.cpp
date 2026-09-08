#include "forma/components/text_input.hpp"
#include "forma/render/renderData/text_input_render_data.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace Forma{

TextInput::TextInput() {}

TextInput::TextInput(Vec2 position, Size size, Forma::Color color) {
  Layout().SetPosition(position);
  Layout().SetSize(size);
  SetColor(color);
}

void TextInput::OnKeyDown(KeyEvent& event){
  if(event.action != GLFW_PRESS) return;

  switch(event.key){
    case GLFW_KEY_BACKSPACE:
      if(m_cursorPosition > 0){
        m_text.erase(m_cursorPosition - 1, 1);
        --m_cursorPosition;
      }
      break;

    case GLFW_KEY_LEFT:
      if(m_cursorPosition > 0)
        --m_cursorPosition;
      break;

    case GLFW_KEY_RIGHT:
      if(m_cursorPosition < m_text.size())
        ++m_cursorPosition;
      break;
  }
}

void TextInput::OnTextInput(TextEvent& event){
  char c = static_cast<char>(event.codepoint);
  m_text.insert(m_cursorPosition, 1, c);
  ++m_cursorPosition;
}

std::unique_ptr<Forma::RenderData> TextInput::RenderData() const{
  auto data = std::make_unique<TextInputRenderData>();

  data->position = Layout().Position();
  data->size = Layout().Size();
  data->color = Color();
  data->order = m_order;
  data->text = m_text;
  data->scale = m_textScale;
  data->cursorPosition = m_cursorPosition;

  return data;
}

TextInput& TextInput::SetColor(Forma::Color color){
  m_color = color;
  m_defaultColor = color;
  return *this;
}

Forma::Color TextInput::Color() const{
  return m_color;
}

TextInput& TextInput::SetTextScale(float scale){
  m_textScale = scale;
  return *this;
}

float TextInput::TextScale() const{
  return m_textScale;
}

}
