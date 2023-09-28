#pragma once

#include "export.h"
#include "pokemon/generation.hpp"
#include "pokemon/party.hpp"
#include "pokemon/pokemon.hpp"

#include "engineparty.hpp"
#include "enginebattle.hpp"

#include <memory>

namespace pokeautumn {
  class Engine {
  public:
    LIBPOKEAUTUMN_EXPORT static const Engine *ForGeneration(Generation generation);

  public:
    virtual Generation EngineGeneration() const = 0;
    std::unique_ptr<EngineParty> CreateParty(Party party) const {
      auto engineParty = std::make_unique<EngineParty>();
      for (auto &pokemon : party) {
        engineParty->push_back(CreatePokemon(pokemon));
      }
      return engineParty;
    }

    virtual std::unique_ptr<EnginePokemon> CreatePokemon(Pokemon pokemon) const = 0;
    virtual std::unique_ptr<EngineBattle> CreateBattle(BattleType fieldType, std::vector<std::shared_ptr<EngineParty>> parties) const = 0;
  };
}
