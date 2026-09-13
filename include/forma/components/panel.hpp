#pragma once
#include "forma/component.hpp"
#include "forma/interfaces/colorable.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/renderable.hpp"

namespace Forma{

class Panel : public Component, public IRenderable, public IColorable{
public:
  Panel();
  Panel(Vec2 position, Forma::Size size, Forma::Color color);

  std::unique_ptr<Forma::RenderData> RenderData() const override;

  Forma::Color Color() const override { return m_color;}
  void SetColor(Forma::Color color) override { m_color = color; }
private:
  Forma::Color m_color{};
  Forma::Color m_defaultColor{};
};

}
