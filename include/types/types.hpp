#pragma once
#include <colors.hpp>
#include <cstdint>
#include <glm/glm.hpp>
#include <string>

namespace Forma{

struct Vec2{
  float x, y;

  Vec2() : x(0), y(0) {}
  Vec2(float x, float y) : x(x), y(y) {}
  Vec2(float s) : x(s), y(s) {}
  Vec2(glm::vec2 v) : x(v.x), y(v.y) {}

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

  Size() : width(0), height(0) {}
  Size(float s) : width(s), height(s) {}
  Size(float width, float height) : width(width), height(height) {}
  Size(glm::vec2 v) : width(v.x), height(v.y) {}

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
  float r{}, g{}, b{}, a{255};

  Color(float r, float g, float b) : r(r), g(g), b(b), a(255) {}
  Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
  Color(float s) : r(s), g(s), b(s), a(255) {}
  Color(const std::string& hex){
    glm::vec3 rgb = Axiom::HexToRgb(hex);
    r = rgb.r * 255.0f; g = rgb.g * 255.0f; b = rgb.b * 255.0f;
  }
  Color(glm::vec3 v) : r(v.r), g(v.g), b(v.b), a(255) {}
  Color() {}

  Color operator-(float scalar){
    return Color{
      r - scalar, g - scalar, b - scalar, a
    };
  }

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

enum class TextAlign{
  None, Left, Center, Right
};

}
