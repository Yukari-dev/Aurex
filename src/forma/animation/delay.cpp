#include "forma/animation/delay.hpp"
#include <iostream>

namespace Forma{

void Delay::Start(){
  std::cout << "Delay started: " << m_duration << '\n';
  m_elapsed = 0.0f;
  m_running = true; 
}

void Delay::Update(float dt){
  if(!m_running) return;

  m_elapsed += dt;
  if(m_elapsed >= m_duration){
    std::cout << "Delay finished: " << m_duration << '\n';
    m_elapsed = m_duration;
    m_running = false;
  }
}

}
