#pragma once
#include "forma/components/label.hpp"
#include "forma/interfaces/focusable.hpp"
#include "forma/interfaces/keyboard_target.hpp"
#include "forma/interfaces/mouse_target.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/renderable.hpp"
#include "forma/component.hpp"
#include <string>

namespace Forma{

class TextInput : public Component, public IRenderable, public IMouseTarget, public IFocusable, public IKeyboardTarget{
public:
  TextInput();
  TextInput(Vec2 position, Forma::Size size, Color color);

  void OnInitialize() override;
  
  std::unique_ptr<Forma::RenderData> RenderData() const override;

  void OnKeyDown(KeyEvent& event) override;
  void OnTextInput(TextEvent& event) override;
  
  TextInput& SetColor(Color color);
  Forma::Color Color() const;

  TextInput& SetTextScale(float scale);
  float TextScale() const;

  const std::string& Text() const;
private:
  Label* m_label{nullptr};
  size_t m_cursorPosition{};
  Forma::Color m_color{};
  Forma::Color m_defaultColor{};
};

}
