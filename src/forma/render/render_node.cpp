#include "forma/render/render_node.hpp"
#include <algorithm>

namespace Forma{

void RenderNode::Remove(RenderNode& node){
  if (&node == this) return;
  
  auto it = std::find_if(
    m_children.begin(), m_children.end(),
    [&node](const std::unique_ptr<RenderNode>& other){
      return other.get() == &node;
    }
  );

  if(it != m_children.end()){
    m_children.erase(it);
  }
}

const std::vector<std::unique_ptr<RenderNode>>& RenderNode::Children() const{
  return m_children;
}

void RenderNode::SortChildren(){
  std::sort(
    m_children.begin(), m_children.end(),
    [](const auto& a, const auto& b){
      return a->Order() < b->Order();
    }
  );
}

RenderNode *RenderNode::HitTest(Vec2 point){
  for(auto& child : m_children){
    if(!child->Visible())
      continue;

    if(auto *hit = child->HitTest(point))
      return hit;
  }
  if(Contains(point))
    return this;

  return nullptr;
}

int32_t RenderNode::Order() const{
  return m_order;
}

void RenderNode::SetOrder(int32_t o){
  m_order = o;
}

uint32_t RenderNode::ID() const{
  return m_id;
}

void RenderNode::SetID(uint32_t id){
  m_id = id;
}

bool RenderNode::Visible() const{
  return m_visible;
}

void RenderNode::SetVisibility(bool mode){
  m_visible = mode;
}

void RenderNode::Initialize(RenderNode *parent){
  m_parent = parent;
}

}
