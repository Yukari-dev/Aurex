#pragma once

namespace Aurex{

class IFocusable{
public:
  virtual ~IFocusable() = default;

  virtual void OnFocus() {}
  virtual void OnBlur() {}
};

}
