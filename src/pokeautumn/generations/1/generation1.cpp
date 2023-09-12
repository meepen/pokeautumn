#include "engine.hpp"
#include "pokemon.hpp"
#include "pokeautumn/enginepokemon.hpp"

#include <memory>

using namespace pokeautumn;
using namespace pokeautumn::Generation1;

EngineParty Generation1Engine::CreateParty(Party party) {
  EngineParty engineParty;
  for (auto &pokemon : party) {
    engineParty.push_back(CreatePokemon(pokemon));
  }
  return engineParty;
}

std::unique_ptr<EnginePokemon> Generation1Engine::CreatePokemon(Pokemon pokemon) {
  auto enginePokemon = std::unique_ptr<EnginePokemon>(
    new Generation1Pokemon(pokemon)
  );
  return enginePokemon;  
}

Generation1Engine Generation1::engine;
