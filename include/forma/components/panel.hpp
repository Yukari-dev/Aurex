#pragma once
#include "forma/component.hpp"
#include "forma/render/render_data.hpp"
#include "forma/render/renderable.hpp"

namespace Forma{

class Panel : public Component, public IRenderable{
public:
  Panel();
  Panel(Vec2 position, Size size, Color color);

  std::unique_ptr<Forma::RenderData> RenderData() const override;

  Panel& SetColor(Color color);
  Forma::Color Color() const;

private:
  Forma::Color m_color;
};

}
