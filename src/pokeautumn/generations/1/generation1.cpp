#include <memory>

#include "engine.hpp"
#include "pokemon.hpp"
#include "pokeautumn/enginepokemon.hpp"
#include "battle.hpp"

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

std::unique_ptr<EnginePokemon> Generation1Engine::CreatePokemon(Pokemon pokemon) const {
  auto enginePokemon = std::unique_ptr<EnginePokemon>(
    new Generation1Pokemon(pokemon)
  );
  return enginePokemon;  
}

std::unique_ptr<EngineBattle> Generation1Engine::CreateBattle(BattleType fieldType, std::vector<std::shared_ptr<EngineParty>> parties) const {
  switch (fieldType) {
    case BattleType::SINGLES:
      return std::make_unique<Battle>(parties);
    default:
      return nullptr;
  }
  return nullptr;
}

Generation1Engine Generation1::engine;
