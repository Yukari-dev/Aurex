#include "aurex/registry/component_registry.hpp"
#include <iostream>
#include "aurex/component.hpp"

namespace Aurex{

void ComponentRegistry::RegisterType(const std::string& type, Factory factory){
  if(type.empty()){
    std::cerr << "LOG: Name is Empty.\n";
    return;
  }
  auto [it, inserted] = m_factories.emplace(type, std::move(factory));
  if(!inserted)
    std::cerr << "LOG: type " << type << " is already regisrered.\n";
}

void ComponentRegistry::RegisterProperty(const std::string& type, const std::string& prop, Setter setter){
  if(type.empty() || prop.empty()){
    std::cerr << "LOG: Type/Property is Empty.\n";
    return;
  }
  auto [it, inserted] = m_setters[type].emplace(prop, setter);
  if(!inserted)
    std::cerr << "LOG: Duplicate property registration for type: " << type << "with the property: " << prop << '\n';
}

std::unique_ptr<Component> ComponentRegistry::Create(const std::string& type) const{
  auto it = m_factories.find(type);
  if(it == m_factories.end()){
    std::cerr << "LOG: Unknown Type" << type << '\n';
    return nullptr;
  }
  return it->second();
}

void ComponentRegistry::Apply(Component& c, const std::string& type, const std::string& prop, const Auruim::Value& v) const{
  auto typeIt = m_setters.find(type);
  if(typeIt == m_setters.end()){
    std::cerr << "LOG: No Property is registered for this type: " << type << '\n';
    return;
  }
  auto propIt = typeIt->second.find(prop);
  if(propIt == typeIt->second.end()){
    std::cerr << "LOG: Unknwo property: { " << prop << " } on Type: " << type << '\n';
    return;
  }
  propIt->second(c, v);
}

void ComponentRegistry::Clear(){
  m_factories.clear();
  m_setters.clear();
}

}
