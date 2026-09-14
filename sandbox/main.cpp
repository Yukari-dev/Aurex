#include "aurex/application.hpp"

int main(){
  Axiom::ContextGuard guard;
  Aurex::Application app;

  return app.Run();
}
