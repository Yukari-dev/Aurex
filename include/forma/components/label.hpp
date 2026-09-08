#pragma once
#include "forma/component.hpp"
#include "forma/render/renderable.hpp"

namespace Forma{

class Label : public Component, public IRenderable{
public:
  Label();
  Label(const std::string& text, float scale, Vec2 position, Color color);

  std::unique_ptr<Forma::RenderData> RenderData() const override;

  Label& SetText(const std::string& text);
  const std::string& Text() const;

  Label& SetScale(float scale);
  float Scale();

  Label& SetColor(Color color);
  Forma::Color Color() const;

  Label& SetTextAlign(TextAlign align);
  Forma::TextAlign TextAlign() const;
private:
  std::string m_text{};
  float m_scale{1.0f};
  Forma::Color m_color{};
  Forma::Color m_defaultColor{};
};

}
