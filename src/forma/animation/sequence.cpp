#include "forma/animation/sequence.hpp"

namespace Forma{

Sequence::Sequence() : AnimationGroup(0.0f){

}

void Sequence::Start(){
  m_elapsed = 0.0f;
  m_currentChild = 0;
  for(auto& child : Children())
    child->Reset();
  if(Children().empty()){
    m_running = false;
    return;
  }
  m_running = true;
  Children()[m_currentChild]->Start();
}

void Sequence::Update(float dt){
  if(!m_running) return;

  m_elapsed += dt;
  
  auto& child = Children()[m_currentChild];
  child->Update(dt);

  if(!child->IsFinished())
    return;

  m_currentChild++;

  if(m_currentChild >= Children().size()){
    m_elapsed = m_duration;
    m_running = false;
    return;
  }
  Children()[m_currentChild]->Start();
}

void Sequence::UpdateDuration(float childDuratio){
  m_duration += childDuratio;
}

}
