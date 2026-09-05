#include "forma/render/render_tree.hpp"

namespace Forma{

RenderTree::RenderTree() : m_root(std::make_unique<RenderNode>()) {}

RenderNode &RenderTree::Root(){
  return *m_root;
}

}
