#pragma once
#include <glm/glm.hpp>

namespace Forma{

struct Vec2{
  float x, y;

  Vec2 operator+(const Vec2& other){
    return {x + other.x, y + other.y};
  }

  Vec2 operator-(const Vec2& other){
    return {x - other.x, y - other.y};
  }

  glm::vec2 ToGlm()const {
    return glm::vec2{x, y};
  }
};

struct Size{
  float width, height;

  Size operator*(float s){
    return {width * s, height * s};
  }

  Size operator*(const Size& o){
    return {width * o.width, height * o.height};
  }

  glm::vec2 ToGlm() const{
    return glm::vec2{width, height};
  }
};

struct Rect{
  float x{}, y{}, width{}, height{};

  Rect(Vec2 pos, Size size){
    x = pos.x; y = pos.y;
    width = size.width; height = size.height;
  }

  Rect(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}

  Vec2 Position() const{
    return {x, y};
  }

  Forma::Size Size() const{
    return {width, height};
  }

  float FullWidth() const{
    return x + width;
  }

  float FullHeight() const{
    return y + height;
  }

  float HalfWidth() const{
    return x + (width / 2);
  }

  float HalfHeight() const{
    return y + (height / 2);
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
  Relative,
  Anchor
};

enum class Anchor{
  TopLeft, TopCenter, TopRight,
  Left, Center, Right,
  BottomLeft, BottomCenter, BottomRight
};

enum class SizeType{
  Fixed,
  Fill,
  Percent
};

}
