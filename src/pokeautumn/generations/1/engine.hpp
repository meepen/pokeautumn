#include "pokeautumn/engine.hpp"
#include "pokemon/pokemon.hpp"

namespace pokeautumn::Generation1 {
  class Generation1Engine : public Engine {
  public:
    Generation EngineGeneration() override { return Generation::GEN1; }
    std::unique_ptr<EnginePokemon> CreatePokemon(Pokemon pokemon) override;
  };

  extern Generation1Engine engine;
}
