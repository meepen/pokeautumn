#pragma once

#include "export.h"
#include "pokemon/generation.hpp"
#include "pokemon/party.hpp"
#include "pokemon/pokemon.hpp"

#include "engineparty.hpp"

#include <memory>

namespace pokeautumn {
  class Engine {
  public:
    LIBPOKEAUTUMN_EXPORT static const Engine *ForGeneration(Generation generation);

  public:
    virtual Generation EngineGeneration() const = 0;
    EngineParty CreateParty(Party party) const {
      EngineParty engineParty;
      for (auto &pokemon : party) {
        engineParty.push_back(CreatePokemon(pokemon));
      }
      return engineParty;
    }

    virtual std::unique_ptr<EnginePokemon> CreatePokemon(Pokemon pokemon) const = 0;
  };
}
