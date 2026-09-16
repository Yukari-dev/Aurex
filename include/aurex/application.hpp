#pragma once
#include "aurex/registry/component_registry.hpp"
#include "aurex/input/input_system.hpp"
#include "aurex/registry/file_watcher.hpp"
#include "aurex/render/render_tree.hpp"
#include "aurex/render/renderer.hpp"
#include "aurex/render/synchronizer.hpp"
#include "aurex/ui_Context.hpp"
#include "types/types.hpp"
#include <memory>
#include <axiom.h>

namespace Aurex{

using namespace Axiom;

class Application{
public:
  Application();

  int Run();
private:
  void OnResize(int width, int heigh5);
  void OnMouseMove(double x, double y);
  void OnMouseButton(int button, int actions, int mods);
  void OnKeyPressed(int key, int scancode, int action);
  void OnCharPressed(unsigned int codepoint);
  std::unique_ptr<Component> LoadUI(const std::string& path, Component *parent);
  bool ReloadUI(const std::string& path);
private:
  Size m_viewportSize{};
  std::unique_ptr<Window> m_window{nullptr};
  std::unique_ptr<RhiContext> m_rhi{nullptr};
  std::unique_ptr<Renderer2D> m_graphicsRenderer{nullptr};
  std::unique_ptr<UIContext> m_context{nullptr};
  std::unique_ptr<RenderTree> m_renderTree{nullptr};
  std::unique_ptr<Synchronizer> m_synchronizer{nullptr};
  std::unique_ptr<Renderer> m_renderer{nullptr};
  std::unique_ptr<InputSystem> m_input{nullptr};
  std::unique_ptr<ComponentRegistry> m_registry{nullptr};
  std::unique_ptr<FileWatcher> m_fileWatcher{nullptr};
};

}
