#pragma once
#include "types/value.hpp"
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

namespace Aurex{

class Component;

using Factory = std::function<std::unique_ptr<Component>()>;
using Setter = std::function<void(Component&, const Value&)>;

class ComponentRegistry{
public:
  ~ComponentRegistry() = default;

  void RegisterType(const std::string& type, Factory factory);
  void RegisterProperty(const std::string& type, const std::string& prop, Setter setter);

  std::unique_ptr<Component> Create(const std::string& type) const;
  void Apply(Component& c, const std::string& type, const std::string& prop, const Value& v) const;
private:
  std::unordered_map<std::string, Factory> m_factories{};
  std::unordered_map<std::string, std::unordered_map<std::string, Setter>> m_setters;
};

}
