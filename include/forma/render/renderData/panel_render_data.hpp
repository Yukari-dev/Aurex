#pragma once
#include "forma/render/render_data.hpp"
#include "types/types.hpp"

namespace Forma{

class PanelRenderData : public RenderData{
public:
  Vec2 position{};
  Size size{};
  Color color{};
  int32_t order{};
};

}
