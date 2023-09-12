#pragma once 

#include <map>
#include "pokemon/data/species.hpp"
#include "pokemon/data/speciesdata.hpp"

namespace pokeautumn::Generation1 {
  extern const std::map<const Species, const SpeciesData> pokemonData;
}
