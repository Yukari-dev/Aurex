#include "forma/application.hpp"
#include "forma/component.hpp"
#include "forma/components/panel.hpp"
#include <cassert>

namespace Forma {

Application::Application() {
  m_window = std::make_unique<Window>(800, 600, "Forma");
  m_rhi = std::make_unique<RhiContext>(m_window->GetHandler(), m_window->GetWidth(), m_window->GetHeight());
  m_rhi->SetResizeCallback([this](int width, int height){ this->OnResize(width, height); });
  m_rhi->SetCursorPosCallback([this](double x, double y){ this->OnMouseMove(x, y); });
  m_rhi->SetMouseButtonCallback([this](int button, int actions, int mods) { this->OnMouseButton(button, actions, mods); });
  m_rhi->SetKeyboardCallback([this](int key, int scancode, int actions, int mods) { this->OnKeyPressed(scancode, actions); });
  m_graphicsRenderer = std::make_unique<Renderer2D>(*m_rhi);
  m_context = std::make_unique<UIContext>();
  m_renderTree = std::make_unique<RenderTree>();
  m_synchronizer = std::make_unique<Synchronizer>();
  m_renderer = std::make_unique<Renderer>(*m_graphicsRenderer);
  m_input = std::make_unique<InputSystem>(*m_context);
}

int Application::Run() {
  auto &root = m_context->Root();
  root.Initialize(nullptr, m_context.get());

  auto &background = root.Add<Panel>();

  background.Layout()
    .SetSizeType(SizeType::Fill);
  background.SetColor({2});

  background.Add<Panel>()
    .SetColor({168, 213, 186})
    .Layout()
      .SetPositionType(PositionType::Anchor)
      .SetAnchor(Anchor::BottomRight)
      .SetParentAnchor(Anchor::Center)
      .SetSize({50, 200});

  background.Add<Panel>()
    .SetColor({255, 179, 186})
    .Layout()
      .SetPosition({10, 0})
      .SetPositionType(PositionType::Anchor)
      .SetAnchor(Anchor::TopLeft)
      .SetParentAnchor(Anchor::Center)
      .SetSize({200, 50});

  background.Add<Panel>()
    .SetColor({229, 196, 208})
    .Layout()
      .SetPosition({0, 60})
      .SetPositionType(PositionType::Anchor)
      .SetAnchor(Anchor::TopRight)
      .SetParentAnchor(Anchor::Center)
      .SetSize({200, 50});

  background.Add<Panel>()
    .SetColor({123, 128, 173})
    .Layout()
      .SetPosition({10, 60})
      .SetPositionType(PositionType::Anchor)
      .SetAnchor(Anchor::TopLeft)
      .SetParentAnchor(Anchor::Center)
      .SetSize({50, 200});

  while (!m_window->ShouldClose()) {
    m_window->PollEvents();

    m_synchronizer->Sync(root, m_renderTree->Root(), root.Layout().Rect());

    m_input->Update(*m_renderTree);

    m_rhi->BeginFrame();
    m_graphicsRenderer->Begin();

    m_renderer->Render(*m_renderTree);

    m_graphicsRenderer->End();
    m_rhi->EndFrame();
  }
  return 0;
}

void Application::OnResize(int width, int height){
  m_viewportSize = {
    static_cast<float>(width),
    static_cast<float>(height)
  };

  m_context->Root().Layout().SetSize(m_viewportSize);
}

void Application::OnMouseMove(double x, double y){
  m_input->SetMouseProperties({static_cast<float>(x), static_cast<float>(y)});
}

void Application::OnMouseButton(int button, int actions, int mods){
  MouseButton mouseButton{};
  switch(button){
    case GLFW_MOUSE_BUTTON_LEFT:
      mouseButton = MouseButton::Left; break;
    case GLFW_MOUSE_BUTTON_MIDDLE:
      mouseButton = MouseButton::Middle; break;
    case GLFW_MOUSE_BUTTON_RIGHT:
      mouseButton = MouseButton::Right; break;
  }

  MouseAction mouseAction{};
  switch(actions){
    case GLFW_PRESS:
      mouseAction = MouseAction::Press; break;
    case GLFW_RELEASE:
      mouseAction = MouseAction::Release; break;
  }

  m_input->SetMouseButton(mouseButton, mouseAction);
}

void Application::OnKeyPressed(int scancode, int action){
  m_input->SetKeyboardKey(scancode, action);
}

}
