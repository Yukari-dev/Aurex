#include "aurex/render/render_tree.hpp"

namespace Aurex{

RenderTree::RenderTree() : m_root(std::make_unique<RenderNode>()) {}

RenderNode &RenderTree::Root(){
  return *m_root;
}

RenderNode *RenderTree::HitTest(Vec2 point){
  return m_root->HitTest(point);
}

}
