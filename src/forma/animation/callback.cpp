#include "forma/animation/callback.hpp"

namespace Forma{

Callback::Callback(CallbackFunction function) : AnimationNode(0.0f), m_callbackFunction(std::move(function)) {}

void Callback::Start(){
  m_elapsed = 0;
  m_running = true;
  m_executed = false;
}

void Callback::Update(float dt){
  if(!m_running) return;

  if(!m_executed){
    m_callbackFunction();
    m_executed = true;
  }
  m_elapsed = m_duration;
  m_running = false;
}

}
