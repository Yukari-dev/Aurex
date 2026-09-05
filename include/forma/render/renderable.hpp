#pragma once
#include "forma/render/render_data.hpp"
#include <memory>

namespace Forma{

class IRenderable{
public:
  virtual ~IRenderable() = default;
  virtual std::unique_ptr<Forma::RenderData> RenderData() const = 0;
};

}
