#include "forma/animation/sequence.hpp"

namespace Forma{

void Sequence::Start(){
  m_elapsed = 0.0f;
  m_currentChild = 0;
  for(auto& child : m_children)
    child->Reset();
  if(m_children.empty()){
    m_running = false;
    return;
  }
  m_running = true;
  m_children[m_currentChild]->Start();
}

void Sequence::Update(float dt){
  if(!m_running) return;

  m_elapsed += dt;
  
  auto& child = m_children[m_currentChild];
  child->Update(dt);

  if(!child->IsFinished())
    return;

  m_currentChild++;

  if(m_currentChild >= m_children.size()){
    m_elapsed = m_duration;
    m_running = false;
    return;
  }
  m_children[m_currentChild]->Start();
}

}
