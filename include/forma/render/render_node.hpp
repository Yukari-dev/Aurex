#pragma once
#include "types/types.hpp"
#include <algorithm>
#include <cstdint>
#include <memory>
#include <utility>
#include <vector>

namespace Forma{

class Renderer;

class RenderNode{
public:
  RenderNode() = default;
  virtual ~RenderNode() = default;

  RenderNode(const RenderNode&) = delete;
  RenderNode& operator=(const RenderNode&) = delete;

  RenderNode(RenderNode&&) = default;
  RenderNode& operator=(RenderNode&&) = default;

  RenderNode *Parent() const;

  virtual void Draw(Renderer& renderer) {}

  template<typename T, typename... Args>
  T& Add(Args&& ...args){
    auto child = std::make_unique<T>(std::forward<Args>(args)...);
    child->Initialize(this);
    T& ref = *child;
    m_children.push_back(std::move(child));
    return ref;
  }

  void Remove(RenderNode& node);

  template <typename T>
  T *Find(uint32_t id){
    auto it = std::find_if(
      m_children.begin(), m_children.end(),
      [&id](const std::unique_ptr<RenderNode>& other){
        if(auto *node = dynamic_cast<T*>(other.get())){
          return node->ID() == id;
        }
        return false;
      }
    );
    if (it != m_children.end())
      return dynamic_cast<T*>(it->get());
    return nullptr;
  }

  const std::vector<std::unique_ptr<RenderNode>>& Children() const;

  void SortChildren();

  virtual bool Contains(Vec2 hitPoint) const {
    return false;
  }

  RenderNode *HitTest(Vec2 point);

  int32_t Order() const;
  void SetOrder(int32_t o);

  uint32_t ID() const;
  void SetID(uint32_t id);

  bool Visible() const;
  void SetVisibility(bool mode);

private:
  void Initialize(RenderNode *parent);
protected:
  uint32_t m_id{};
  int32_t m_order{};
  RenderNode *m_parent{nullptr};
  std::vector<std::unique_ptr<RenderNode>> m_children;
  bool m_visible{true};
};

}
