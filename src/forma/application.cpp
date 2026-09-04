#include "forma/application.hpp"
#include "forma/component.hpp"

#include <cassert>

namespace Forma{

Application::Application(){
  m_window = std::make_unique<Window>(800, 600, "Forma");
  m_rhi = std::make_unique<RhiContext>(m_window->GetHandler(), m_window->GetWidth(), m_window->GetHeight());
  m_renderer = std::make_unique<Renderer2D>(*m_rhi);
  m_context = std::make_unique<UIContext>();
}

int Application::Run(){
  auto& root = m_context->Root();
  root.Initialize(nullptr, m_context.get());
  
  auto& test = root.Add<Component>();

  while (!m_window->ShouldClose()){
    m_window->PollEvents();
    m_rhi->BeginFrame();
    m_renderer->Begin();

    // TODO:rendering

    m_renderer->End();
    m_rhi->EndFrame();
  }
  return 0;
}

}
