#pragma once

namespace Forma{

class AnimationNode{
public:
  AnimationNode(float duration) : m_duration(duration){
    m_elapsed = 0.0f;
    m_running = false;
  }
  virtual ~AnimationNode() = default;

  virtual void Start() = 0;
  virtual void Update(float dt) = 0;

  virtual void Reset(){
    m_elapsed = 0.0f;
    m_running = false;
  }

  virtual bool IsFinished() const { return !m_running && m_elapsed >= m_duration; };
  virtual bool IsRunning() const { return m_running; }
  virtual float Duration() const { return m_duration; };
  virtual float Elapsed() const { return m_elapsed; };
protected:
  float m_duration{};
  float m_elapsed{};
  bool m_running{false};
};

}
