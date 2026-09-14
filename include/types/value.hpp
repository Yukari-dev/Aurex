#pragma once
#include "types/types.hpp"
#include <string>
#include <variant>

namespace Aurex{

class Value{
public:
  static Value Number(float v) { return Value{v}; }
  static Value Bool(bool v) { return Value{v}; }
  static Value String(const std::string& v) { return Value{v}; }
  static Value Vec2(Aurex::Vec2 v) { return Value{v}; }
  static Value Size(Aurex::Size n) { return Value{ n }; }

  template <typename T>
  bool IsData() const{
    return std::holds_alternative<T>(m_data);
  }

  template <typename T>
  T AsData() const{
    if(auto *p = std::get_if<T>(&m_data)) return *p;
    assert(false && "Value::AsData: wrong type requested");
    return {};
  }

private:
  Value(float v) : m_data(v) {}
  Value(bool v) : m_data(v) {}
  Value(const std::string& v) : m_data(v) {}
  Value(Aurex::Vec2 v) : m_data(v) {}
  Value(Aurex::Size v) : m_data(v) {}

  std::variant<std::monostate, float, bool, std::string, Aurex::Vec2, Aurex::Size> m_data;
};

}
