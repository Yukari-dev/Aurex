#pragma once
#include "auruim/value.hpp"
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <optional>

namespace Aurex{

class Component;

using Factory = std::function<std::unique_ptr<Component>()>;
using Setter = std::function<void(Component&, const Auruim::Value&)>;
using Getter = std::function<void(Component&)>;

struct PropertyInfo{
  Setter setter{};
  Auruim::Value defaultValue{};
  bool hasDefault{false};
};

class ComponentRegistry{
public:
  ~ComponentRegistry() = default;

  void RegisterType(const std::string& type, Factory factory);
  void RegisterProperty(
    const std::string& type, const std::string& prop, Setter setter,
    Auruim::Value defaultValue
  );

  std::unique_ptr<Component> Create(const std::string& type) const;
  void Apply(Component& c, const std::string& type, const std::string& prop, const Auruim::Value& v) const;

  std::optional<Auruim::Value> GetDefault(const std::string& type, const std::string& prop) const;
  void Clear();
private:
  std::unordered_map<std::string, Factory> m_factories{};
  std::unordered_map<std::string, std::unordered_map<std::string, PropertyInfo>> m_setters;
};

}
