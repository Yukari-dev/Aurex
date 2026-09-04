#include "forma/application.hpp"

int main(){
  Axiom::ContextGuard guard;
  Forma::Application app;

  return app.Run();
}
