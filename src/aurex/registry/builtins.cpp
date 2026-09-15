#include "aurex/component.hpp"
#include "aurex/components/panel.hpp"
#include "auruim/value.hpp"
#include "aurex/registry/component_registry.hpp"
#include <initializer_list>
#include <type_traits>
#include <utility>

namespace Aurex{

template <typename E>
E ParseEnum(std::string s, std::initializer_list<std::pair<const char*, E>> table, E fallback){
  for(auto& [name, value] : table){
    std::transform(
      s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); }
    );
    if (s.compare(name) == 0) return value;
  }
  return fallback;
}

template <typename T>
void Register(ComponentRegistry& r, const std::string& name){
  auto setPosition = [](Component& c, const Auruim::Value& v){
    const auto& a = v.AsArray();
    c.Layout().SetPosition({a[0].AsData<float>(), a[1].AsData<float>()});
  };

  auto setSize = [](Component& c, const Auruim::Value& v){
    const auto& a = v.AsArray();
    c.Layout().SetSize({a[0].AsData<float>(), a[1].AsData<float>()});
  };

  r.RegisterType(name, []{ return std::make_unique<T>(); }); 
  r.RegisterProperty(name, "position", setPosition);
  r.RegisterProperty(name, "size", setSize);
  r.RegisterProperty(name, "position_type", [](Component& c, const Auruim::Value& v){
    std::string s = v.AsData<std::string>();
    PositionType type = ParseEnum<PositionType>(v.AsData<std::string>(), {
      {"relative", PositionType::Relative},
      {"rbsolute", PositionType::Absolute},
    }, PositionType::Absolute);
    c.Layout().SetPositionType(type);
  });

  r.RegisterProperty(name, "animatable", [](Component& c, const Auruim::Value& v){
    std::string s = v.AsData<std::string>();
    c.Layout().SetAnimatable(s == "true" || s == "True");
  });

  r.RegisterProperty(name, "smoothing", [](Component& c, const Auruim::Value& v){
    c.Layout().SetSmoothing(v.AsData<float>());
  });

  if constexpr (std::is_base_of_v<IColorable, T>){
    r.RegisterProperty(name, "color", [](Component& c, const Auruim::Value& v){
      static_cast<IColorable&>(static_cast<T&>(c)).SetColor(v.AsData<std::string>());
    });
    r.RegisterProperty(name, "opacity", [](Component& c, const Auruim::Value& v){
      static_cast<IColorable&>(static_cast<T&>(c)).SetOpacity(v.AsData<float>());
    });
  }
}

void RegisterBuiltins(ComponentRegistry& r){
  Register<Panel>(r, "Panel");
}

}
