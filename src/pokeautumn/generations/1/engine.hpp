#include "pokeautumn/engine.hpp"
#include "pokemon/pokemon.hpp"

namespace pokeautumn::Generation1 {
  class Generation1Engine : public Engine {
  public:
    Generation EngineGeneration() const override { return Generation::GEN1; }
    std::unique_ptr<EnginePokemon> CreatePokemon(Pokemon pokemon) const override;
    std::unique_ptr<EngineBattle> CreateBattle(BattleType fieldType, std::vector<std::shared_ptr<EngineParty>> parties) const override;
  };

  extern Generation1Engine engine;
}
