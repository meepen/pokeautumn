#pragma once

#include <array>

#include "stattype.hpp"
#include "type.hpp"
#include "species.hpp"

namespace pokeautumn {
  // Implemented by the Engine of each generation

  struct PokemonBaseStats {
    unsigned hp : 8;
    unsigned attack : 8;
    unsigned defense : 8;
    unsigned speed : 8;
    union {
      unsigned special_attack : 8;
      unsigned special : 8;
    };
    unsigned special_defense : 8;
  };

  struct SpeciesData {
    PokemonBaseStats baseStats;
    std::array<Type, 2> types = { Type::NONE, Type::NONE };
  };
}