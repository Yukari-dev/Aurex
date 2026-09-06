#include "forma/application.hpp"
#include "forma/component.hpp"
#include "forma/components/panel.hpp"
#include <cassert>

namespace Forma {

Application::Application() {
  m_window = std::make_unique<Window>(800, 600, "Forma");
  m_rhi = std::make_unique<RhiContext>(m_window->GetHandler(), m_window->GetWidth(), m_window->GetHeight());
  m_graphicsRenderer = std::make_unique<Renderer2D>(*m_rhi);
  m_context = std::make_unique<UIContext>();
  m_renderTree = std::make_unique<RenderTree>();
  m_synchronizer = std::make_unique<Synchronizer>();
  m_renderer = std::make_unique<Renderer>(*m_graphicsRenderer);
}

int Application::Run() {
  auto &root = m_context->Root();
  root.Initialize(nullptr, m_context.get());

  auto &panel = root.Add<Panel>();
  panel.Layout().SetPosition({0, 0});
  panel.Layout().SetSize({800, 300});
  panel.SetColor({255, 255, 255});

  // root.Remove(panel);

  while (!m_window->ShouldClose()) {
    m_window->PollEvents();

    m_synchronizer->Sync(root, m_renderTree->Root());

    m_rhi->BeginFrame();
    m_graphicsRenderer->Begin();

    m_renderer->Render(*m_renderTree);

    m_graphicsRenderer->End();
    m_rhi->EndFrame();
  }
  return 0;
}

}
