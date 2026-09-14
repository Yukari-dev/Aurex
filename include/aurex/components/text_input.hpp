#pragma once
#include "aurex/components/label.hpp"
#include "aurex/interfaces/focusable.hpp"
#include "aurex/interfaces/keyboard_target.hpp"
#include "aurex/interfaces/mouse_target.hpp"
#include "aurex/render/render_data.hpp"
#include "aurex/render/renderable.hpp"
#include "aurex/component.hpp"
#include <string>

namespace Aurex{

class TextInput : public Component, public IRenderable, public IMouseTarget, public IFocusable, public IKeyboardTarget{
public:
  TextInput();
  TextInput(Vec2 position, Aurex::Size size, Color color);

  void OnInitialize() override;
  
  std::unique_ptr<Aurex::RenderData> RenderData() const override;

  void OnKeyDown(KeyEvent& event) override;
  void OnTextInput(TextEvent& event) override;
  
  TextInput& SetColor(Color color);
  Aurex::Color Color() const;

  TextInput& SetTextScale(float scale);
  float TextScale() const;

  const std::string& Text() const;
private:
  Label* m_label{nullptr};
  size_t m_cursorPosition{};
  Aurex::Color m_color{};
  Aurex::Color m_defaultColor{};
};

}
