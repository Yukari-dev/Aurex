#pragma once
#include "forma/component.hpp"
#include "forma/interfaces/colorable.hpp"
#include "forma/render/renderable.hpp"
#include "types/types.hpp"

namespace Forma{

class Label : public Component, public IRenderable, public IColorable{
public:
  Label();
  Label(const std::string& text, float scale, Vec2 position, Forma::Color color);

  std::unique_ptr<Forma::RenderData> RenderData() const override;

  Label& SetText(const std::string& text);
  Label& AddText(const std::string& text, size_t pos = 0);
  Label& AddText(char c, size_t pos = 0);
  Label& RemoveChar(size_t pos);
  const std::string& Text() const;

  Label& SetScale(float scale);
  float Scale();

  Forma::Color Color() const override { return m_color;}
  void SetColor(Forma::Color color) override { m_color = color; }

  float Opacity() const override { return m_opacity;}
  void SetOpacity(float opacity) override { m_opacity = opacity; }

  Label& SetTextAlign(TextAlign align);
  Forma::TextAlign TextAlign() const;
private:
  std::string m_text{};
  float m_scale{1.0f};
  float m_opacity{1.0f};
  Forma::Color m_color{};
  Forma::Color m_defaultColor{};
};

}
