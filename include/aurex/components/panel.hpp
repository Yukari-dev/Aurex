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
  void OnUpdate(float dt) override;
  std::unique_ptr<Aurex::RenderData> RenderData() const override;
};

}
