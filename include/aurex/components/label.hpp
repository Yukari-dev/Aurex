#pragma once
#include "aurex/component.hpp"
#include "aurex/interfaces/colorable.hpp"
#include "aurex/render/renderable.hpp"
#include "types/types.hpp"

namespace Aurex{

class Label : public Component, public IRenderable, public IColorable{
public:
  Label();
  Label(const std::string& text, float scale, Vec2 position, Aurex::Color color);

  void OnUpdate(float dt) override;
  std::unique_ptr<Aurex::RenderData> RenderData() const override;

  Label& SetText(const std::string& text);
  Label& AddText(const std::string& text, size_t pos = 0);
  Label& AddText(char c, size_t pos = 0);
  Label& RemoveChar(size_t pos);
  const std::string& Text() const;

  Label& SetScale(float scale);
  float Scale();

  Label& SetTextAlign(TextAlign align);
  Aurex::TextAlign TextAlign() const;
private:
  std::string m_text{};
  float m_scale{1.0f};
};

}
