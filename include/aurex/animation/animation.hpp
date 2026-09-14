#pragma once
#include <math.hpp>

namespace Aurex{

using namespace Axiom;

template <typename T>
class Animation{
public:
  Animation() = default;

  void Start(T start, T end, float duration, EaseType easeType = EaseType::InOutSine){
    m_start = start;
    m_end = end;
    m_duration = duration;
    m_elapsed = 0.0f;
    m_running = true;
    m_easeType = easeType;
  }

  void Update(float dt){
    if(!m_running) return;

    m_elapsed += dt;

    if(m_elapsed >= m_duration)
      Finish();
  }

  T Value(){
    return EaseLerp(m_start, m_end, Progress(), m_easeType);
  }

  float Progress() const{
    if(m_duration <= 0.0f)
      return 1.0f;
    return std::min(m_elapsed / m_duration, 1.0f);
  }

  float Elapsed() const{
    return m_elapsed;
  }

  void Finish(){
    m_elapsed = m_duration;
    m_running = false;
  }

  EaseType Easing() const{
    return m_easeType;
  }

  bool IsRunning() const{
    return m_running;
  }

  bool IsFinished() const {
    return !m_running && m_elapsed >= m_duration;
  }
private:
  T m_start{};
  T m_end{};
  EaseType m_easeType{EaseType::InOutSine};
  float m_duration{};
  float m_elapsed{};
  bool m_running{false};
};

}
