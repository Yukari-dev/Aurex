#pragma once

namespace Forma{

class IFocusable{
public:
  virtual ~IFocusable() = default;

  virtual void OnFocus() {}
  virtual void OnBlur() {}
};

}
