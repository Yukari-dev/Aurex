#pragma once
#include <glm/glm.hpp>

namespace Forma{

struct Vec2{
  float x, y;

  Vec2 operator+(const Vec2& other){
    return {x + other.x, y + other.y};
  }

  glm::vec2 ToGlm()const {
    return glm::vec2{x, y};
  }
};

struct Size{
  float width, height;

  glm::vec2 ToGlm() const{
    return glm::vec2{width, height};
  }
};

struct Color{
  float r, g, b, a;

  Color operator/(float scalar){
    return Color{
      r / scalar, g / scalar, b / scalar, a
    };
  }

  Color Normalize() const{
    Color color = {r, g, b, a};
    return color / 255.0f;
  }

  glm::vec3 ToGlm() const{
    return glm::vec3{r, g, b};
  }
};

struct Padding{
  float top, bottom, right, left;
};

enum class PositionType{
  Absolute,
  Relative
};

enum class SizeType{
  Fixed,
  Fill,
};

}
