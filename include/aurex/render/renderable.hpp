#pragma once
#include "aurex/render/render_data.hpp"
#include <memory>

namespace Aurex{

class IRenderable{
public:
  virtual ~IRenderable() = default;
  virtual std::unique_ptr<Aurex::RenderData> RenderData() const = 0;
};

}
