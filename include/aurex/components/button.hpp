#pragma once
#include "aurex/animation/animation.hpp"
#include "aurex/component.hpp"
#include "aurex/interfaces/mouse_target.hpp"
#include "aurex/render/render_data.hpp"
#include "aurex/render/renderable.hpp"
#include <functional>

namespace Aurex{

class Button : public Component, public IRenderable, public IMouseTarget{
public:
  Button();

  void OnUpdate(float dt) override;

  void OnMouseEnter(MouseEvent& event) override;
  void OnMouseLeave(MouseEvent& event) override;
  void OnMouseDown(MouseEvent& event) override;
  void OnMouseUp(MouseEvent& event) override;
  void OnClick(MouseEvent& event) override;

  std::unique_ptr<Aurex::RenderData> RenderData() const override;

  Aurex::Color Color() const;
  Button& SetColor(Aurex::Color color);
  Button& SetDefaultColor(Aurex::Color color);
  Button& SetHoverColor(Aurex::Color color);
  Button& SetPressedColor(Aurex::Color color);
  Button& SetOnClick(std::function<void(MouseEvent&)> callback);
private:
  Aurex::Color m_color{};
  Aurex::Color m_defaultColor{};
  Aurex::Color m_hoverColor{};
  Aurex::Color m_pressedColor{};

  std::function<void(MouseEvent&)> m_onClick{};
};

}
