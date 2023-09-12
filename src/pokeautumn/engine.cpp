#include "engine.hpp"

#include "pokemon/generation.hpp"

#include "generations/1/engine.hpp"

using namespace pokeautumn;


Engine *Engine::ForGeneration(Generation generation) {
  switch (generation) {
    case Generation::GEN1:
      return &Generation1::engine;
    default:
      return nullptr;
  }
}
