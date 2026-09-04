#pragma once
#include <memory>
#include <axiom.h>

namespace Forma{

using namespace Axiom;

class Application{
public:
  Application();
  // ~Application();

  int Run();
private:
  std::unique_ptr<Window> m_window{nullptr};
  std::unique_ptr<RhiContext> m_rhi{nullptr};
  std::unique_ptr<Renderer2D> m_renderer{nullptr};
};

}
