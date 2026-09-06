#pragma once
#include "forma/component.hpp"
#include "forma/interfaces/mouse_target.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/renderable.hpp"

namespace Forma{

class Panel : public Component, public IRenderable, public IMouseTarget{
public:
  Panel();
  Panel(Vec2 position, Size size, Color color);

  std::unique_ptr<Forma::RenderData> RenderData() const override;

  void OnMouseEnter(MouseEvent& event) override;
  void OnMouseLeave(MouseEvent& event) override;
  void OnMouseMove(MouseEvent& event) override;
  void OnMouseDown(MouseEvent& event) override;
  void OnMouseUp(MouseEvent& event) override;

  Panel& SetColor(Color color);
  Forma::Color Color() const;
private:
  Forma::Color m_color{};
  Forma::Color m_defaultColor{};
};

}
