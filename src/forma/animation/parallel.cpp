#include "forma/animation/parallel.hpp"
#include <algorithm>

namespace Forma{

Parallel::Parallel() : AnimationGroup(0.0f) {}

void Parallel::Start(){
  m_elapsed = 0.0f;

  if(Children().empty())
    return;

  for(auto& child : Children())
    child->Reset();

  m_running = true;

  for(auto& child : Children())
    child->Start();
}

void Parallel::Update(float dt){
  if(!m_running) return;

  m_elapsed += dt;

  bool allFinished = true;
  
  for(auto& child : Children()){
    child->Update(dt);

    if(!child->IsFinished())
      allFinished = false;
  }

  if(allFinished){
    m_elapsed = m_duration;
    m_running = false;
    return;
  }
}

void Parallel::UpdateDuration(float childDuration){
  m_duration = std::max(m_duration, childDuration);
}

}
