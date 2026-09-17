#include "aurex/registry/builtins.hpp"
#include "aurex/component.hpp"
#include "aurex/components/label.hpp"
#include "aurex/components/panel.hpp"
#include "aurex/interfaces/colorable.hpp"
#include "aurex/registry/component_registry.hpp"
#include "auruim/value.hpp"
#include <algorithm>
#include <cctype>
#include <initializer_list>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>

namespace Aurex {

namespace {

template <typename E>
E ParseEnum(std::string s, std::initializer_list<std::pair<const char*, E>> table, E fallback){
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return static_cast<char>(std::tolower(c)); });

  for (auto& [name, value] : table)
  if (s == name) return value;

  return fallback;
}

Vec2 GetVec2(const Auruim::Value& v){
  const auto& a = v.AsArray();
  return { a[0].AsData<float>(), a[1].AsData<float>() };
}

Size GetSize(const Auruim::Value& v){
  const auto& a = v.AsArray();
  return { a[0].AsData<float>(), a[1].AsData<float>() };
}

void SetPosition(Component& c, const Auruim::Value& v){
  c.Layout().SetPosition(GetVec2(v));
}

void SetSize(Component& c, const Auruim::Value& v){
  c.Layout().SetSize(GetSize(v));
}

void SetPositionType(Component& c, const Auruim::Value& v){
  c.Layout().SetPositionType(ParseEnum<PositionType>(v.AsData<std::string>(), {
    {"relative", PositionType::Relative},
    {"absolute", PositionType::Absolute},
    {"anchor",   PositionType::Anchor},
  }, PositionType::Absolute));
}

Anchor GetAnchor(const std::string& s){
  return ParseEnum<Anchor>(s, {
    {"topleft",      Anchor::TopLeft},
    {"topcenter",    Anchor::TopCenter},
    {"topright",     Anchor::TopRight},
    {"left",         Anchor::Left},
    {"center",       Anchor::Center},
    {"right",        Anchor::Right},
    {"bottomleft",   Anchor::BottomLeft},
    {"bottomcenter", Anchor::BottomCenter},
    {"bottomright",  Anchor::BottomRight},
  }, Anchor::TopLeft);
}

void SetAnchor(Component& c, const Auruim::Value& v){
  if(v.IsArray()){
    const auto& a = v.AsArray();
    Anchor childAnchor = GetAnchor(a[0].AsData<std::string>());
    Anchor parentAnchor = GetAnchor(a[1].AsData<std::string>());
    c.Layout().SetAnchor(childAnchor, parentAnchor);
  } else{
    Anchor childAnchor = GetAnchor(v.AsData<std::string>());
    c.Layout().SetAnchor(childAnchor);
  }
}

void SetParentAnchor(Component& c, const Auruim::Value& v){
  Anchor parentAnchor = GetAnchor(v.AsData<std::string>());
  c.Layout().SetParentAnchor(parentAnchor);
}

void SetSizeType(Component& c, const Auruim::Value& v){
  c.Layout().SetSizeType(ParseEnum<SizeType>(v.AsData<std::string>(), {
    {"fixed",   SizeType::Fixed},
    {"fill",    SizeType::Fill},
    {"percent", SizeType::Percent},
  }, SizeType::Fixed));
}

void SetTextAlign(Component& c, const Auruim::Value& v){
  c.Layout().SetTextAlign(ParseEnum<TextAlign>(v.AsData<std::string>(), {
    {"left",   TextAlign::Left},
    {"center", TextAlign::Center},
    {"right",  TextAlign::Right},
  }, TextAlign::Left));
}

void SetAnimatable(Component& c, const Auruim::Value& v){
  auto s = v.AsData<std::string>();
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return static_cast<char>(std::tolower(c)); });
  c.Layout().SetAnimatable(s == "true");
  if (auto *colorable = dynamic_cast<IColorable*>(&c))
    colorable->SetAnimatable(s == "true");
}

void SetSmoothing(Component& c, const Auruim::Value& v){
  c.Layout().SetSmoothing(v.AsData<float>());
}

}

void RegisterLayoutProperties(ComponentRegistry& r, const std::string& name){
  r.RegisterProperty(name, "position", SetPosition, Auruim::Value::Array({Auruim::Value::Number(0), Auruim::Value::Number(0)}));
  r.RegisterProperty(name, "size", SetSize, Auruim::Value::Array({Auruim::Value::Number(0), Auruim::Value::Number(0)}));
  r.RegisterProperty(name, "position_type", SetPositionType, Auruim::Value::String("absolute"));
  r.RegisterProperty(name, "anchor", SetAnchor, Auruim::Value::String("topLeft"));
  r.RegisterProperty(name, "parent_anchor", SetParentAnchor, Auruim::Value::String("topLeft"));
  r.RegisterProperty(name, "size_type", SetSizeType, Auruim::Value::String("fixed"));
  r.RegisterProperty(name, "animatable", SetAnimatable, Auruim::Value::String("false"));
  r.RegisterProperty(name, "smoothing", SetSmoothing, Auruim::Value::Number(1.0f));
}

void RegisterColorProperties(ComponentRegistry& r, const std::string& name){
  r.RegisterProperty(name, "color", [](Component& c, const Auruim::Value& v){
    auto *colorable = dynamic_cast<IColorable*>(&c);
    colorable->SetColor(v.AsData<std::string>());
  }, Auruim::Value::String("#000000"));
  r.RegisterProperty(name, "opacity", [](Component& c, const Auruim::Value& v){
    auto *colorable = dynamic_cast<IColorable*>(&c);
    colorable->SetOpacity(v.AsData<float>());
  }, Auruim::Value::Number(1.0f));
}

void RegisterLabelProperties(ComponentRegistry& r, const std::string& name){
  r.RegisterProperty(name, "text", [](Component& c, const Auruim::Value& v){
    auto *text = dynamic_cast<Label*>(&c);
    text->SetText(v.AsData<std::string>());
  }, Auruim::Value::String(""));

  r.RegisterProperty(name, "text_align", SetTextAlign, Auruim::Value::String("left"));

  r.RegisterProperty(name, "text_scale", [](Component& c, const Auruim::Value& v){
    auto *text = dynamic_cast<Label*>(&c);
    text->SetScale(v.AsData<float>());
  }, Auruim::Value::Number(1.0f));
}

template <typename T>
void Register(ComponentRegistry& r, const std::string& name){
  r.RegisterType(name, []{ return std::make_unique<T>(); });
  RegisterLayoutProperties(r, name);

  if constexpr (std::is_base_of_v<Label, T>)
    RegisterLabelProperties(r, name);

  if constexpr (std::is_base_of_v<IColorable, T>)
    RegisterColorProperties(r, name);
}

void RegisterBuiltins(ComponentRegistry& r){
  Register<Panel>(r, "Panel");
  Register<Label>(r, "Label");
}

}
