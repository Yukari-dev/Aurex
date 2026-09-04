#pragma once
#include <glm/glm.hpp>

struct Vec2{
  float x, y;
};

struct Size{
  float width, height;
};

struct Color{
  float r, g, b, a;

  Color operator/(float scalar){
    return Color{
      r / scalar, g / scalar, b / scalar, a
    };
  }

  Color Normalize(){
    Color color = {r, g, b, a};
    return color / 255.0f;
  }
};

struct Padding{
  float top, bottom, right, left;
};
