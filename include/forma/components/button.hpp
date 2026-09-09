#pragma once
#include "forma/animation/animation.hpp"
#include "forma/component.hpp"
#include "forma/interfaces/mouse_target.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/renderable.hpp"
#include <functional>

namespace Forma{

class Button : public Component, public IRenderable, public IMouseTarget{
public:
  Button();

  void OnUpdate(float dt) override;

  void OnMouseEnter(MouseEvent& event) override;
  void OnMouseLeave(MouseEvent& event) override;
  void OnMouseDown(MouseEvent& event) override;
  void OnMouseUp(MouseEvent& event) override;
  void OnClick(MouseEvent& event) override;

  std::unique_ptr<Forma::RenderData> RenderData() const override;

  Forma::Color Color() const;
  Button& SetColor(Forma::Color color);
  Button& SetDefaultColor(Forma::Color color);
  Button& SetHoverColor(Forma::Color color);
  Button& SetPressedColor(Forma::Color color);
  Button& SetOnClick(std::function<void(MouseEvent&)> callback);

  void AnimateColor(Forma::Color color, float duration, EaseType eastType = EaseType::InOutSine);
private:
  Forma::Color m_color{};
  Forma::Color m_defaultColor{};
  Forma::Color m_hoverColor{};
  Forma::Color m_pressedColor{};

  std::function<void(MouseEvent&)> m_onClick{};
  Animation<glm::vec3> m_animation{};
};

}
