#pragma once
#include "aurex/component.hpp"
#include "aurex/interfaces/colorable.hpp"
#include "aurex/render/render_data.hpp"
#include "aurex/render/renderable.hpp"

namespace Aurex{

class Panel : public Component, public IRenderable, public IColorable{
public:
  Panel();
  Panel(Vec2 position, Aurex::Size size, Aurex::Color color);

  std::unique_ptr<Aurex::RenderData> RenderData() const override;

  Aurex::Color Color() const override { return m_color;}
  void SetColor(Aurex::Color color) override { m_color = color; }

  float Opacity() const override { return m_opacity;}
  void SetOpacity(float opacity) override { m_opacity = opacity; }
private:
  float m_opacity{1.0f};
  Aurex::Color m_color{};
  Aurex::Color m_defaultColor{};
};

}
