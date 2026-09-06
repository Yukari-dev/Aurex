#include "forma/render/render_tree.hpp"

namespace Forma{

RenderTree::RenderTree() : m_root(std::make_unique<RenderNode>()) {}

RenderNode &RenderTree::Root(){
  return *m_root;
}

RenderNode *RenderTree::HitTest(Vec2 point){
  return m_root->HitTest(point);
}

}
