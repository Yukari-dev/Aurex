#include "forma/animation/delay.hpp"

namespace Forma{

void Delay::Start(){
  m_elapsed = 0.0f;
  m_running = true; 
}

void Delay::Update(float dt){
  if(!m_running) return;

  m_elapsed += dt;
  if(m_elapsed >= m_duration){
    m_elapsed = m_duration;
    m_running = false;
  }
}

}
