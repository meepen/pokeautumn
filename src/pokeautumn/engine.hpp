#pragma once

#include "pokemon/generation.hpp"
#include "pokemon/party.hpp"
#include "pokemon/pokemon.hpp"

#include "engineparty.hpp"

#include <memory>

namespace pokeautumn {
  class Engine {
  public:
    static Engine *ForGeneration(Generation generation);

  public:
    virtual Generation EngineGeneration() = 0;
    virtual EngineParty CreateParty(Party party) = 0;
    virtual std::unique_ptr<EnginePokemon> CreatePokemon(Pokemon pokemon) = 0;
  };
}
