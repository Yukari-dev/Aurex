#include "forma/application.hpp"

namespace Forma{

Application::Application(){
  m_window = std::make_unique<Window>(800, 600, "Forma");
  m_rhi = std::make_unique<RhiContext>(m_window->GetHandler(), m_window->GetWidth(), m_window->GetHeight());
  m_renderer = std::make_unique<Renderer2D>(*m_rhi);
}

int Application::Run(){
  while (!m_window->ShouldClose()){
    m_window->PollEvents();
    m_rhi->BeginFrame();
    m_renderer->Begin();

    // rendering

    m_renderer->End();
    m_rhi->EndFrame();
  }
  return 0;
}

}
