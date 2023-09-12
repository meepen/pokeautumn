#pragma once

#include "data/stattype.hpp"
#include "data/type.hpp"
#include "data/species.hpp"

namespace pokeautumn {
  // Implemented by the Engine of each generation
  struct SpeciesData {
    unsigned int base_stats[static_cast<unsigned>(StatType::COUNT)];
    Type types[2] = { Type::NONE, Type::NONE };
    // TODO: learned moves
  };
}