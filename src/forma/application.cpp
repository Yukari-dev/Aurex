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

  auto &background = root.Add<Panel>();
  background.Layout()
    .SetPosition({0, 0})
    .SetSize({800, 1200});
  background.SetColor({250, 250, 250});

  auto &panel = background.Add<Panel>();
  panel.Layout()
    .SetPosition({300, 200})
    .SetSize({200, 200});
  panel.SetColor({1, 1, 1});

  panel.SetOrder(5);

  // auto &child = panel.Add<Panel>();
  // child.Layout()
  //   .SetPosition({2, 2})
  //   .SetPositionType(PositionType::Relative)
  //   .SetSizeType(SizeType::Fill);
  // child.SetColor({128, 255, 255});

  while (!m_window->ShouldClose()) {
    m_window->PollEvents();

    m_synchronizer->Sync(root, m_renderTree->Root(), root.Layout().Position(), root.Layout().Size());

    m_rhi->BeginFrame();
    m_graphicsRenderer->Begin();

    m_renderer->Render(*m_renderTree);

    m_graphicsRenderer->End();
    m_rhi->EndFrame();
  }
  return 0;
}

}
