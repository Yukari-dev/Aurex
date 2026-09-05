#pragma once
#include "forma/render/render_tree.hpp"
#include "forma/render/synchronizer.hpp"
#include "forma/ui_Context.hpp"
#include <memory>
#include <axiom.h>

namespace Forma{

using namespace Axiom;

class Application{
public:
  Application();

  int Run();
private:
  std::unique_ptr<Window> m_window{nullptr};
  std::unique_ptr<RhiContext> m_rhi{nullptr};
  std::unique_ptr<Renderer2D> m_renderer{nullptr};
  std::unique_ptr<UIContext> m_context{nullptr};
  std::unique_ptr<RenderTree> m_renderTree{nullptr};
  std::unique_ptr<Synchronizer> m_synchronizer{nullptr};
};

}
