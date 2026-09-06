#include "forma/ui_Context.hpp"
#include "forma/component.hpp"

namespace Forma{

UIContext::UIContext() : m_root(std::make_unique<Component>()){

}

UIContext::~UIContext() {}

Component& UIContext::Root(){
  return *m_root;
}

uint32_t UIContext::GetID(){
  return ++m_currentId;
}

Component *UIContext::Find(uint32_t id){
  return m_root->Find(id);
}

}
