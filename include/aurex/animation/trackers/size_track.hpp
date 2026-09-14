#pragma once
#include "aurex/animation/animation_node.hpp"
#include "aurex/animation/attributes/size_animation.hpp"
#include "aurex/animation/trackers/track.hpp"
#include "aurex/interfaces/sizeable.hpp"
#include "types/types.hpp"
#include <memory>
#include <stdexcept>
#include <typeinfo>

namespace Aurex{

class SizeTrack : public AnimationNode, public ITrackable{
public:
  explicit SizeTrack(ISizeable& sizeable);

  void Start() override;
  void Update(float dt) override;
  bool IsFinished() const override;
  float Duration() const override;

  SizeTrack& From(const Size& size);
  SizeTrack& To(const Size& size);
  SizeTrack& Delay(float delay);
  SizeTrack& For(float duration);
  SizeTrack& Using(EaseType easeType);

  void SetFrom(const void* value, const std::type_info& type) override{
    if(type != typeid(Size))
      throw std::invalid_argument("SizeTrack expect Color.");
    From(*static_cast<const Size*>(value));
  }
  void SetTo(const void* value, const std::type_info& type) override{
    if(type != typeid(Size))
      throw std::invalid_argument("SizeTrack expect Color.");
    To(*static_cast<const Size*>(value));
  }
  void SetDelay(float delay) override;
  void SetDuration(float duration) override;
  void SetEase(EaseType easeType) override;
private:
  ISizeable& m_target;
  bool m_hasDefaultValue{true};
  std::unique_ptr<SizeAnimation> m_animation;
};

}
